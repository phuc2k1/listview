#ifndef CLASSSERVO_H
#define CLASSSERVO_H
#include <wiringPi.h>
#include <softPwm.h>
#include "qdebug.h"
#include"stdint.h"
class classservo
{
public:

    classservo(int pin);
    void setangle(int angle );
    int getangle();
    int getpinmode();
    void setpinmode(int a);

private:
    int localangle;
    int SERVO_PIN;
};

#endif // CLASSSERVO_H
