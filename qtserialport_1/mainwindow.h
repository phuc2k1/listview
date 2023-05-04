#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"classfirebase.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    classfirebase *m_firebase;
    classfirebase *m_firebase1;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
public slots:
    void onFirebaseDataReceived(QString data);
    void onfirevasedatareceived(QString data);


};

#endif // MAINWINDOW_H
