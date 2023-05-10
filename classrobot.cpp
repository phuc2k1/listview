
#include "classrobot.h"

classrobot::classrobot()
{
    trangthai = QVector<int>::fromStdVector(TRANGTHHAI);
    servo1= new classservo(SERVO_PIN);
    servo2= new classservo(SERVO_PIN_1);
    servo3= new classservo(SERVO_PIN_2);
    servo4= new classservo(SERVO_PIN_3);
    servo5= new classservo(SERVO_PIN_4);
    qDebug()<<"Success INIT robot";
    settrangthai(0,0);



}


void classrobot::settrangthai(int a,int b){
    emit SetTrangThaiSingal(a,b);
    switch(a){
    case 0:{
        setgoc(trangthai);
        qDebug()<<"ve ban dau";

        break;
    }
    case 1:
        setvat(b);
        qDebug()<<"Dat vat vi tri"<<b;
        break;
    case 2:
        getvat(b);
        qDebug()<<"Lay vat vi tri"<<b;
        break;
    default:
        setgoc(trangthai);
        qDebug()<<"loi thong so";


    }
}
void classrobot::setgoc(QVector<int> &vectorgoc)
{

    servo1->setangle(vectorgoc[0]);
    servo2->setangle(vectorgoc[1]);
    servo3->setangle(vectorgoc[2]);
    servo4->setangle(vectorgoc[3]);
    servo5->setangle(vectorgoc[4]);

}
void classrobot::thucthi(int a, int b){
    trangthai[a]=trangthai[a]+b;
    setgoc(trangthai);
    qDebug()<<trangthai;
}
void classrobot::setvat(int a)  {
    int b;
    bool c=true;
        qDebug()<<"Thuc hien lenh dat vi tri: "<<a;
        if (a==1)
            {b=VITRI_1;}
        else if (a==2)
            {b=VITRI_2;c=false;}
        else if (a==3)
            {b=VITRI_3;}
        thucthi(1,-50);//haxuong
        thucthi(4,-80);//gap
        thucthi(1,50);//nang
        //thucthi(3,-20);//be len
        thucthi(0,b);//quay
        delay(1000);
        if(c==true)thucthi(2,-10);
        //thucthi(3,20);//bexuong
        thucthi(1,-60);//ha
        thucthi(4,80);//nha
        thucthi(1,60);//nanglen
        thucthi(0,-b);//quayve
        delay(1000);
        if(c==true)thucthi(2,10);
        //thucthi(1,-40);//haxuong

}
void classrobot::getvat(int a){
    int b;
    bool c=true;
        qDebug()<<"Thuc hien lenh lay vi tri: "<<a;
        if (a==1)
            {b=VITRI_1;}
        else if (a==2)
            {b=VITRI_2;c=false;}
        else if (a==3)
            {b=VITRI_3;}
        //thucthi(1,40);//nang1
        //thucthi(3,-20);//be len2
        thucthi(0,b);//xoay3
        delay(1000);
        if(c==true)thucthi(2,-10);
        thucthi(1,-60);//ha4
        //thucthi(3,20);//be xuong5
        thucthi(4,-80);//gap6
        thucthi(1,60);//nang7
        thucthi(0,-b);//xoay8
        delay(1000);
        if(c==true)thucthi(2,10);
        thucthi(1,-50);//ha9
        thucthi(4,80);//nha10
        thucthi(1,50);//nanglen



}
