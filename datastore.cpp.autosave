#include "datastore.h"




datastore::datastore()
{
    QFile file(LINK);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Truncate)){
        QTextStream in(&file);
        in<<"0,0,0";
        file.close();
    }

}

int datastore::checkstore(QString qr)
{
    QFile file(LINK);
    int a=0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QString _data= file.readAll();
        file.close();
        QList<QString> list=_data.split(",");
        foreach (auto p_list, list) {
            a++;
            if(p_list==qr)return a;
        }

    }
    else{qDebug()<<"Error read data";}
    return -1;
}

void datastore::Writedata(QString Qr, int local)
{
    QFile file(LINK);
    QList<QString> list;
    if (file.open(QIODevice::ReadOnly| QIODevice::Text)){
        QString _data= file.readAll();
        if(_data.endsWith("\n")){
            _data.chop(1);
        }
         list=_data.split(",");
         file.close();
    }
    else{qDebug()<<"Error r read data";}
    if (file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Truncate)){
        QTextStream in(&file);
        list[local-1]=Qr;
        QString _datasave=list.join(",");
        in<<_datasave;
        file.close();
    }
    else{qDebug()<<"Error w read data";}
}

void datastore::Writredataxuat(QString qr)
{
    QFile file(LINK);
    QList<QString> list;
    if (file.open(QIODevice::ReadOnly| QIODevice::Text)){
        QString _data= file.readAll();
        if(_data.endsWith("\n")){
            _data.chop(1);
        }
         list=_data.split(",");
         file.close();
    }
    else{qDebug()<<"Error r read data";}
    if (file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Truncate)){
        QTextStream in(&file);
        foreach (auto p_list, list) {
            if(qr==p_list){
                p_list="0";
            }
        }
        QString _datasave=list.join(",");
        in<<_datasave;
        file.close();
    }
    else{qDebug()<<"Error w read data";}
}
