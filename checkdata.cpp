#include "checkdata.h"

checkdata::checkdata()
{
    firebase=new classfirebase("https://phuc-2f523-default-rtdb.firebaseio.com/ma.json");
    connect(firebase,&classfirebase::dataChanged,this,&checkdata::writedata);

}

QString checkdata::checkdatatext(QString dataqr)
{
    QFile file(LINK);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QString _datastr= file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(_datastr.toUtf8());
        QJsonObject dataobj = doc.object();
        for(auto i=dataobj.constBegin();i!=dataobj.constEnd();i++){
            if(i.value().toInt()==dataqr.toInt()){
                qDebug()<<i.key()<<i.value().toInt();
                int datamatxt=i.value().toInt();
                file.close();
                return i.key()+":"+QString::number(datamatxt);
            }
        }


    }
    else{qDebug()<<"Error read data";}
    return "-1";
}

void checkdata::writedata(QString data)
{
//    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
//    QJsonObject jsonObj = jsonDoc.object();
//    QString sp1 = jsonObj["SanPham1"].toString();
//    QString sp2 = jsonObj["SanPham2"].toString();
//    QString sp3 = jsonObj["SanPham3"].toString();
//    QString sp4 = jsonObj["SanPham4"].toString();
    QFile file(LINK);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&file);
        stream<<data;
        file.close();

    }
    qDebug()<<data;
}
