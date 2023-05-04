
#ifndef READDATA_H
#define READDATA_H
#define LINK "/home/pi/Desktop/listview/data2/datalocal.txt"

#include <QFile>
#include <QTextStream>
#include <QString>
#include "qdebug.h"
#include"qlist.h"
class readdata: public QObject
{
    Q_OBJECT
public:
    readdata();
    bool getdata(int vitri);
    void setdata(QString datainput,int vitri);
    uint32_t getvitri();
private:
    QString data;
public slots:
    void GetSetVitri(int code,int vitri);

};

#endif // READDATA_H
