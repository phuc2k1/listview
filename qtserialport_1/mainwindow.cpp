#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_firebase= new classfirebase("https://phuc-2f523-default-rtdb.firebaseio.com/1.json");
    m_firebase1=new classfirebase("https://phuc-2f523-default-rtdb.firebaseio.com/ma.json");
    connect(m_firebase,&classfirebase::dataChanged,this,&MainWindow::onFirebaseDataReceived);
    connect(m_firebase1,&classfirebase::dataChanged,this,&MainWindow::onfirevasedatareceived);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onFirebaseDataReceived(QString data)
{
    qDebug()<<"changed"<<data;

}

void MainWindow::onfirevasedatareceived(QString data)
{
    qDebug()<<"changed"<<data;

}
