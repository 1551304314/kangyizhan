#ifndef MAP_H
#define MAP_H
#include<QPixmap>

class map
{
public:
    map();
    void mapPosition();
    QPixmap map1;
    QPixmap map2;

    int map1_y;
    int map2_y;

    int scroll_speed;
};

#endif // MAP_H
