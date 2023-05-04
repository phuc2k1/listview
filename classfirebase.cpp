
#include "classfirebase.h"

classfirebase::classfirebase(QObject *parent):QObject(parent)
{
    _networkmanager= new QNetworkAccessManager(this);
    QString firebaseUrl="https://phuc-2f523-default-rtdb.firebaseio.com/1.json";
    m_request = QNetworkRequest(QUrl(firebaseUrl ));
    _qnetworkreply= _networkmanager->get(m_request);
    connect(_qnetworkreply,&QNetworkReply::readyRead,this,&classfirebase::networkReplyReadyRead);
}
classfirebase::classfirebase(QString url){
    _networkmanager= new QNetworkAccessManager(this);
    QString firebaseUrl=url;
    m_request = QNetworkRequest(QUrl(firebaseUrl ));
    _qnetworkreply= _networkmanager->get(m_request);
    connect(_qnetworkreply,&QNetworkReply::readyRead,this,&classfirebase::networkReplyReadyRead);
}



classfirebase::~classfirebase()
{
    _networkmanager->deleteLater();
}

void classfirebase::networkReplyReadyRead()
{
     if (_qnetworkreply->error() == QNetworkReply::NoError) {
             QString _data = QString::fromUtf8(_qnetworkreply->readAll());
            if(data!=_data){
                data=_data;
                 qDebug()<<data;
                  emit dataChanged(_data);

            }
         }
     else {
             qDebug() << "Lỗi khi lấy dữ liệu từ Firebase:" <<_qnetworkreply->errorString();
         }
     _qnetworkreply=_networkmanager->get(m_request);
     connect(_qnetworkreply, &QNetworkReply::readyRead, this, &classfirebase::networkReplyReadyRead);

}






