#ifndef CLASSROBOT_H
#define CLASSROBOT_H
#include "classservo.h"
#include"qvector.h"
#define TRANGTHHAI {30,80,110,160,160}
#define VITRI_1 70
#define VITRI_2 90
#define VITRI_3 110

#define SERVO_PIN 0//11
#define SERVO_PIN_1 1//12
#define SERVO_PIN_2 2//13
#define SERVO_PIN_3 3//15
#define SERVO_PIN_4 4 //16
class classrobot: public QObject
{
    Q_OBJECT
public:
    classrobot();

private:
    classservo* servo1;
    classservo* servo2;
    classservo* servo3;
    classservo* servo4;
    classservo* servo5;
    QVector<int> trangthai;
public:
    void setvat(int a);
    void getvat(int a);
    void settrangthai(int a,int b);
    void setgoc(QVector<int>& vectorgoc);
    void thucthi(int a,int b);

signals:
    void SetTrangThaiSingal(int a, int b);
};

#endif // CLASSROBOT_H
