#include "game.h"
#include<QPainter>
#include<QtWidgets>
#include<mainwindow.h>
#include<config.h>
#include<QMouseEvent>
game::game(QWidget *parent) : QWidget(parent)
{
    init();
}

void game::init()
{
    resize(GAME_WIDTH,GAME_HEIGHT);
    this->setWindowTitle("单人游戏");
    m_Timer.setInterval(GAME_RATE);
    playGame();
    enemy_recorder = 0;
    srand((unsigned int)time(0));
}
void game::playGame()
{
    //玩游戏 启动定时器
    m_Timer.start();
    //信号监听
    connect(&m_Timer,&QTimer::timeout,[=](){
        enemyapr();//敌机出场
        updatePosition();//更新坐标
        update();//屏幕重绘
        collideDetect();//碰撞检测
    });
}

void game::updatePosition()
{
    //更新地图坐标
    Map.mapPosition();
    //发射子弹
    DOC.shoot();
    for(int i=0;i<BULLET_NUM;i++){
        if(!DOC.Bullets[i].free){
            DOC.Bullets[i].updatePosition();
        }
    }
    for(int i=0;i<ENEMY_NUM;i++){
        if(!enemys[i].free){
            enemys[i].updatePosition();
        }
    }

}

void game::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x() - DOC.Rect.width() * 0.5;
    int y = event->y() - DOC.Rect.height() * 0.5;
    //边界检测
    if(x <= 0){
        x = 0;
    }
    if(x >= GAME_WIDTH - DOC.Rect.width()){
        x = GAME_WIDTH - DOC.Rect.width();
    }
    if(y <= 0)
{
        y = 0;
    }
    if(y >= GAME_HEIGHT - DOC.Rect.height()){

        y = GAME_HEIGHT - DOC.Rect.height();
    }
    DOC.setPosition(x,y);
}

void game::enemyapr()
{
    enemy_recorder++;
    if(enemy_recorder<ENEMY_INTERVAL){
        return;
    }
    enemy_recorder = 0;
    for(int i = 0;i<ENEMY_NUM;i++){
        if(enemys[i].free){

            enemys[i].free = 0;
            enemys[i].x0 = rand() % (GAME_WIDTH - enemys[i].Rect.width());
            enemys[i].y0 = -enemys[i].Rect.height();
            break;
        }
    }

}

void game::collideDetect()
{
    for(int i = 0;i<ENEMY_NUM;i++){
        if(enemys[i].free)
        {
            continue;
        }
        for(int j=0;j<BULLET_NUM;j++)
        {
            if(DOC.Bullets[i].free)
            {
                continue;
            }

        if(enemys[i].Rect.intersects(DOC.Bullets[j].Rect))
        {
            enemys[i].free = 1;
            DOC.Bullets[j].free = 1 ;
        }
    }
}
}

void game::paintEvent(QPaintEvent *)
{   //绘制地图
    QPainter painter(this);
    painter.drawPixmap(0,Map.map1_y,Map.map1);
    painter.drawPixmap(0,Map.map2_y,Map.map2);
    //绘制飞机
    painter.drawPixmap(DOC.x0,DOC.y0,DOC.Doc);
    //绘制子弹
    for(int i=0;i<BULLET_NUM;i++){
        if(!DOC.Bullets[i].free){
            painter.drawPixmap(DOC.Bullets[i].x0,DOC.Bullets[i].y0,DOC.Bullets[i].Bullet);
        }
    }
    for(int i=0;i<ENEMY_NUM;i++){
        if(!enemys[i].free){
            painter.drawPixmap(enemys[i].x0,enemys[i].y0,enemys[i].Enemy);
        }
    }

}
