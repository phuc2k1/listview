#ifndef CHECKDATA_H
#define CHECKDATA_H
#define LINK "/home/pi/Desktop/listview/data2/checkdata.txt"

#include <QFile>
#include <QTextStream>
#include <QString>
#include "qdebug.h"
#include"qlist.h"
#include"classfirebase.h"

class checkdata:public QObject
{
    Q_OBJECT
public:
    checkdata();
    QString checkdatatext(QString stringqr);

private slots:
    void writedata(QString data);
private:
    classfirebase* firebase;
};

#endif // CHECKDATA_H
