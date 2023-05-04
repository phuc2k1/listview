
#include "readdata.h"

readdata::readdata()
{


}

bool readdata::getdata(int vitri)
{
    QFile file(LINK);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QString _data= file.readAll();
        file.close();
        QList<QString> list=_data.split(",");
        if(list[vitri]!="1"){return false;}else{return true;}
    }
    else{qDebug()<<"Error read data";}
}
void readdata::setdata(QString datainput,int vitri){
    QFile file(LINK);
    QList<QString> list;
    if (file.open(QIODevice::ReadOnly| QIODevice::Text)){
        QString _data= file.readAll();
         list=_data.split(",");
         if(list.last()=="1\n"){list.last()="1";}
         if(list.last()=="0\n"){list.last()="0";}
         file.close();
    }
    else{qDebug()<<"Error r read data";}
    if (file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Truncate)){
        QTextStream in(&file);
        list[vitri-1]=datainput;
        QString _datasave=list.join(",");
        in<<_datasave;
        file.close();
    }
    else{qDebug()<<"Error w read data";}

}

uint32_t readdata::getvitri()
{
    if(!getdata(0)){return 1;}
    if(!getdata(1)){return 2;}
    if(!getdata(2)){return 3;}
    return 4;
}

void readdata::GetSetVitri(int code, int vitri)
{
    switch(code){
    case 0:{

        break;
    }
    case 1:
        setdata("1",vitri);
        break;
    case 2:
        setdata("0",vitri);
        break;
    default:
        break;

}}

