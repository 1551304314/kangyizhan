#include "doctor.h"
#include<config.h>
doctor::doctor()
{   setPic( "doc1.png");
    //初始化坐标
    x0 = GAME_WIDTH*0.5 - Doc.width() * 0.5;
    y0 = GAME_HEIGHT - Doc.height() - 20;
    //矩形边框
    Rect.setWidth(Doc.width());
    Rect.setHeight(Doc.height());
    Rect.moveTo(x0,y0);
    bullet_recorder = 0;
}

void doctor::shoot()
{
        bullet_recorder++;
        if(bullet_recorder<20){
            return;
        }
        bullet_recorder = 0;
        for(int i=0;i<BULLET_NUM;i++){
            if(Bullets[i].free){
                Bullets[i].free = 0;
                Bullets[i].x0 = x0 + Rect.width()*0.5 - 17;
                Bullets[i].y0 = y0;
                break;
            }
        }

}

void doctor::setPosition(int x, int y)
{
    x0 = x;
    y0 = y;
    Rect.moveTo(x0,y0);
}

void doctor::setPic(QString a)
{
    //载入飞机资源
    DocPic = a;
    Doc.load(DocPic);

}
