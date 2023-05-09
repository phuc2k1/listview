#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"debuglogger.h"
#include "classrobot.h"
#include"readdata.h"
#include"checkdata.h"
#include"classfirebase.h"
#include"datastore.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    classrobot* robot ;
    readdata _data;
     QDate date;
     datastore _datastore;



private:
    Ui::MainWindow *ui;
    QStringListModel *m_stringListModel;
    QString readdatenow();
    QString readrealtime();
    classfirebase* m_firebase;
    //classfirebase* m_firebase1;
    classfirebase* m_firebase2;
    checkdata _checkdata;
    void xulychinh(QString tensp,QString masp);
    QPixmap *image;
    QPixmap image1;
    QPixmap image2;
    QPixmap image3;
    DebugLogger* debugLogger;



private slots:



    void on_xuat1_clicked();

    void on_nhap1_clicked();

    void on_xuat2_clicked();

    void on_nhap2_clicked();

    void on_xuat3_clicked();

    void on_nhap3_clicked();

public slots:
    void onFirebaseDataReceived(QString data);

    void DataControlRecieve(QString data);

};

#endif // MAINWINDOW_H
