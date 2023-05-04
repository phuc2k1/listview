#ifndef CLASSAPIREST_H
#define CLASSAPIREST_H
#include"QObject"
#include"QNetworkAccessManager"
#include"QNetworkReply"
#include"QDebug"
class classapirest: public QObject
{

public:
    classapirest();
    ~classapirest();
    void setAPIKey(const QString & apiKey);
    void singUserUp(const QString & emailAddress,const QString password);
private:
    void performPOST(const QString & url,const QJsonDocument& payload);
    QString _apikey;
    QNetworkAccessManager* _networkaccessmanager;
    QNetworkReply* _networkreply;
public slots:
    void networkreplyreadyread();

};

#endif // CLASSAPIREST_H
