#ifndef CLASSFIREBASE_H
#define CLASSFIREBASE_H
#include"QObject"
#include <QNetworkAccessManager>
#include"qstring.h"
#include"QNetworkReply"
#include"QNetworkRequest"
#include"QDebug"
#include"QTimer"
#include"QtNetwork"
#include"QtMath"
#include"QVariantMap"
#include <QJsonObject>
#include <QJsonDocument>
class classfirebase: public QObject
{
    Q_OBJECT
public:
    explicit classfirebase(QObject *parent= nullptr);
    classfirebase(QString url);
    ~classfirebase();
private:
     QString  data;

    QNetworkRequest m_request;
    QNetworkAccessManager* _networkmanager;
    QNetworkReply* _qnetworkreply;
public slots:
    void networkReplyReadyRead();
signals:
    void datamapOutput(const QVariantMap data);
    void dataChanged(const QString& data);
};

#endif // CLASSFIREBASE_H
