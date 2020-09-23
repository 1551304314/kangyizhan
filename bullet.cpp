#include "bullet.h"
#include<config.h>
bullet::bullet()
{
    setPic( "bullet1.png");
    //初始化子弹坐标
    x0 = GAME_WIDTH * 0.5 - Bullet.width() * 0.5;
    y0 = GAME_HEIGHT;
    //子弹空闲状态
    free = true;
    //矩形边框
    Rect.setWidth(Bullet.width());
    Rect.setHeight(Bullet.height());
    Rect.moveTo(x0,y0);
    speed = BULLET_SPEED;

}

void bullet::updatePosition()
{
    //空闲状态
    if(free){
        return;
    }
    //子弹向上移动
    y0 -= speed;
    Rect.moveTo(x0,y0);
    if(y0 <= -Rect.height()){

        free = true;
    }

}

void bullet::setPic(QString a)
{
    bulletPic = a;
    //加载子弹资源
    Bullet.load(bulletPic);

}
