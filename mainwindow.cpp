
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    debugLogger = new DebugLogger(this);
    connect(debugLogger, &DebugLogger::logAdded, [=]() {
        ui->listView->setModel(debugLogger->model());
    });
    image=new QPixmap("/home/pi/Desktop/listview/anh.jpg");
    image1=image->scaled(ui->khosp1->size());
    image2=image->scaled(ui->khosp2->size());
    image3=image->scaled(ui->khosp3->size());
    debugLogger->log("Start!");
    debugLogger->log("mitom");

    robot=new classrobot();
    //ui->label_13->setStyleSheet("background-color:Gray");

     m_firebase= new classfirebase("https://phuc-2f523-default-rtdb.firebaseio.com/1.json");

     m_firebase2= new classfirebase("https://phuc-2f523-default-rtdb.firebaseio.com/controljson");

    connect(robot,&classrobot::SetTrangThaiSingal,&_data,&readdata::GetSetVitri);
    connect(m_firebase,&classfirebase::dataChanged,this,&MainWindow::onFirebaseDataReceived);

    connect(m_firebase2,&classfirebase::dataChanged,this,&MainWindow::DataControlRecieve);

}
MainWindow::~MainWindow()
{
    delete ui;
}
QString MainWindow::readdatenow()
{
    QDateTime now = QDateTime::currentDateTime();
    QDate currentDate = now.date();
    QString year =QString::number( currentDate.year());
    QString month = QString::number(currentDate.month()).rightJustified(2, '0');
    QString day =QString::number( currentDate.day()).rightJustified(2, '0');
    return day+"_"+month+"_"+year;
}
void MainWindow::xulychinh(QString tensp,QString masp)
{
    int vitri=_data.getvitri();

        switch(vitri){
        case 1:
            debugLogger->log("Nhập kho vào vị trí 1");
            robot->settrangthai(1,1);
            ui->name1->setText(tensp);
            ui->lineEdit->setText(masp);
            ui->lineEdit_2->setText(readdatenow());
            ui->khosp1->setPixmap(image1);
                    break;
        case 2:
            debugLogger->log("Nhập kho vào vị trí 2");
            robot->settrangthai(1,2);
            ui->name2->setText(tensp);
            ui->lineEdit_3->setText(masp);
            ui->lineEdit_4->setText(readdatenow());
            ui->khosp2->setPixmap(image2);
            break;
        case 3:
            debugLogger->log("Nhập kho vào vị trí 3");
            robot->settrangthai(1,3);
            ui->name3->setText(tensp);
            ui->lineEdit_5->setText(masp);
            ui->lineEdit_6->setText(readdatenow());
            ui->khosp3->setPixmap(image3);
            break;
        case 4:
            qDebug()<<"full";
            debugLogger->log("Kho hàng đã đầy");
            break;
        }

}

void MainWindow::onFirebaseDataReceived(QString data)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();
    QString qrcode = jsonObj["belt1"].toString();
    debugLogger->log("Phát hiện mã code  :"+qrcode);
    if(qrcode=="0")return;

    QString datatxt=_checkdata.checkdatatext(qrcode);
    if(datatxt!="-1"){

        QStringList listdata=datatxt.split(":");
        debugLogger->log("Mã code phù hợp với sản phẩm:"+listdata[0]+":"+listdata[1]);
        xulychinh(listdata[0],listdata[1]);

    }
    else{
        qDebug()<<"NO exit qr in txt";
        debugLogger->log(" Mã Code :"+qrcode+" ko có trong danh sách");
    }

    //if(_h)
}



void MainWindow::DataControlRecieve(QString data)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();
    int codecontrol = jsonObj["ct1"].toInt();
    if(codecontrol==0)return;
    switch (codecontrol) {
    case 1:
        if(_data.getdata(0)==true){
            debugLogger->log( "Xuất kho ở vị trí 1");
            robot->settrangthai(2,1);
            ui->name1->clear();
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->khosp1->clear();
            ui->khosp1->setText("Trống");
        }
        else{qDebug()<<"Ko có sản phẩm";}
        break;
    case 2:
        if(_data.getdata(1)==true){
            debugLogger->log("Xuất kho ở vị trí 2");
            robot->settrangthai(2,2);
            ui->name2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->khosp2->clear();
            ui->khosp2->setText("Trống");
        }
        else{qDebug()<<"Ko có sản phẩm";}
        break;
    case 3:
        if(_data.getdata(2)==true){
            debugLogger->log("Xuất kho ở vị trí 3");
            robot->settrangthai(2,3);
            ui->name3->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
            ui->khosp3->clear();
            ui->khosp3->setText("Trống");
        }
        else{qDebug()<<"Ko có sản phẩm";}
        break;
    case 4:
        robot->settrangthai(0,0);
    default:
        break;
    }


}


void MainWindow::on_xuat1_clicked()
{
    if(_data.getdata(0)==true){
        debugLogger->log( "Xuất kho ở vị trí 1");
        robot->settrangthai(2,1);
        ui->name1->clear();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->khosp1->clear();
        ui->khosp1->setText("Trống");
    }
    else{qDebug()<<"Ko có sản phẩm";}
}

void MainWindow::on_nhap1_clicked()
{
    if(_data.getdata(0)==false){
        debugLogger->log("Nhập kho vào vị trí 1");
        robot->settrangthai(1,1);
        ui->lineEdit_2->setText(readdatenow());
        ui->khosp1->setPixmap(image1);
    }
    else{qDebug()<<"Sản phẩm đã có";}
}

void MainWindow::on_xuat2_clicked()
{
    if(_data.getdata(1)==true){
        debugLogger->log("Xuất kho ở vị trí 2");
        robot->settrangthai(2,2);
        ui->name2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->khosp2->clear();
        ui->khosp2->setText("Trống");
    }
    else{qDebug()<<"Ko có sản phẩm";}
}

void MainWindow::on_nhap2_clicked()
{
    if(_data.getdata(1)==false){
        debugLogger->log("Nhập kho vào vị trí 2");
        robot->settrangthai(1,2);
        ui->lineEdit_4->setText(readdatenow());
        ui->khosp2->setPixmap(image2);
    }
    else{qDebug()<<"Sản phẩm đã có";}

}

void MainWindow::on_xuat3_clicked()
{
    if(_data.getdata(2)==true){
        debugLogger->log("Xuất kho ở vị trí 3");
        robot->settrangthai(2,3);
        ui->name3->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->khosp3->clear();
        ui->khosp3->setText("Trống");
    }
    else{qDebug()<<"Ko có sản phẩm";}
}

void MainWindow::on_nhap3_clicked()
{
    if(_data.getdata(2)==false){
        debugLogger->log("Nhập kho vào vị trí 3");
        robot->settrangthai(1,3);
        ui->lineEdit_6->setText(readdatenow());
        ui->khosp3->setPixmap(image3);
    }
    else{qDebug()<<"Sản phẩm đã có";}
}
