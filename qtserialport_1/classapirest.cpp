#include "classapirest.h"

classapirest::classapirest():_apikey(QString() )
{
    _networkaccessmanager = new QNetworkAccessManager(this);
}

classapirest::~classapirest()
{
    _networkaccessmanager->deleteLater();
}

void classapirest::setAPIKey(const QString & apiKey)
{
    _apikey= apiKey;
}

void classapirest::singUserUp(const QString &emailAddress, const QString password)
{
    QString signupendpoint="https://identitytoolkit.googleapis.com/v1/accounts:signInWithCustomToken?key="+_apikey;
    QVariantMap variantpayload;
    variantpayload["email"]=emailAddress;
    variantpayload["password"]=password;
    variantpayload["returnSecureToken"]=true;

    QJsonDocument jonpayload=QJsonDocument::fromVariant(variantpayload);
    performPOST(signupendpoint,jsonpayload);
}

void classapirest::networkreplyreadyread()
{
   qDebug()<<_networkreply->readAll();
}
