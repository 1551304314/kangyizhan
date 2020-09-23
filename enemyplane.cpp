#include "enemyplane.h"

enemyplane::enemyplane()
{
    setPic("enemy1.png");
    x0 = 0;
    y0 = 0;
    free = 1;
    speed = ENEMY_SPEED;
    Rect.setWidth(Enemy.width());
    Rect.setHeight(Enemy.height());
    Rect.moveTo(x0,y0);
}

void enemyplane::updatePosition()
{
    //空闲状态
    if(free){
        return;
    }
    //子弹向上移动
    y0 += speed;
    Rect.moveTo(x0,y0);
    if(y0 >= GAME_HEIGHT){

        free = true;
    }


}

void enemyplane::setPic(QString a)
{
    enemyPic = a;
    Enemy.load(enemyPic);
}

