#include "classqtserialport.h"


classqtserialport::classqtserialport(QString _com)
{
    serialPort.setPortName(_com);
    serialPort.setBaudRate(QSerialPort::Baud9600);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setFlowControl(QSerialPort::NoFlowControl);
    serialPort.open(QIODevice::ReadWrite);

}
void classqtserialport::writedata(QString data){
    serialPort.write(data.toUtf8());
    qt1.setInterval(2000);
    qt1.setSingleShot(true);
    connect(&serialPort,&QSerialPort::readyRead,this,&classqtserialport::readataReciece);
    qt1.start();
    connect(&qt1,&QTimer::timeout,this,[]{qDebug()<<"Cant recieve data form master";});
}
QString classqtserialport::readdata()
{
    return QString::fromUtf8(serialPort.readAll());
}

void classqtserialport::readataReciece()
{
    QString _str= readdata();
    if(_str==1){
        qt1.stop();
        qDebug()<<" recieved data from Master ";
    }
}
