#ifndef DATASTORE_H
#define DATASTORE_H
#define LINK "/home/pi/Desktop/listview/data2/checkdata.txt"
#include <QFile>
#include <QTextStream>
#include <QString>
#include "qdebug.h"
#include"qlist.h"
class datastore:public QObject
{
    Q_OBJECT
public:
    datastore();
    int checkstore(QString qr);
    void Writedata(QString Qr,int local);

};

#endif // DATASTORE_H
