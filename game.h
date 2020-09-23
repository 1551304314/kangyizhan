#ifndef GAME_H
#define GAME_H
#include <QWidget>
#include<QPainter>
#include<QTimer>
#include<map.h>
#include<QPainter>
#include<doctor.h>
#include<bullet.h>
#include<enemyplane.h>
class game : public QWidget
{
public:
    game(QWidget *parent = 0);
    void init();
    void paintEvent(QPaintEvent * );
    void playGame();
    void updatePosition();
    void mouseMoveEvent(QMouseEvent *event);
    QTimer m_Timer;
    map  Map;
    doctor DOC;
    void enemyapr();
    enemyplane enemys[ENEMY_NUM];
    int enemy_recorder;
    void collideDetect();


};

#endif // GAME_H
