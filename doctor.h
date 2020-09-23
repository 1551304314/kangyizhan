#ifndef DOCTOR_H
#define DOCTOR_H
#include<QPixmap>
#include<config.h>
#include<bullet.h>

class doctor
{
public:
    doctor();
    void shoot();
    void setPosition(int,int);
    QPixmap Doc;
    int x0;
    int y0;
    QRect Rect;
    QString DocPic;
    void setPic(QString);
    bullet Bullets[BULLET_NUM];
    int bullet_recorder;

};

#endif // DOCTOR_H
