#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include<QPixmap>
#include<config.h>
class enemyplane
{
public:
    enemyplane();
    void updatePosition();
    QPixmap Enemy;
    int x0;
    int y0;
    QRect Rect;
    bool free;
    int speed;
    QString enemyPic;
    void setPic(QString);
};

#endif // ENEMYPLANE_H
