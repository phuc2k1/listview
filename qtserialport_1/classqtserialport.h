#ifndef CLASSQTSERIALPORT_H
#define CLASSQTSERIALPORT_H
#include <QtSerialPort/QSerialPort>
#include"qobject.h"
#include"qstring.h"
#include"QDebug"
#include"QTimer"
class classqtserialport: public QObject
{
    Q_OBJECT
public:

    classqtserialport(QString _com);
public:
    void writedata(QString data);
    QString readdata();

private:
    QTimer qt1;
    QSerialPort serialPort;
public slots:
    void readataReciece();
};

#endif // CLASSQTSERIALPORT_H
