#ifndef BULLET_H
#define BULLET_H
#include<QPixmap>


class bullet
{
public:
    bullet();
    void updatePosition();
    QPixmap Bullet;
    int x0;
    int y0;
    int speed;
    bool free;
    QRect Rect;
    QString bulletPic;
    void setPic(QString);

};

#endif // BULLET_H
