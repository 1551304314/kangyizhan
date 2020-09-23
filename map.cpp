#include "map.h"
#include"config.h"
map::map()
{
    //初始化加载地图对象
    map1.load(MAP_PATH);
    map2.load(MAP_PATH);
    map1_y = - GAME_HEIGHT;
    map2_y = 0;
    scroll_speed = MAP_SPEED;
}

void map::mapPosition()
{
    //第一张图片滚动
    map1_y += scroll_speed;
    if(map1_y >= 0){
        map1_y = - GAME_HEIGHT;
    }
    //第二张图片滚动
    map2_y += scroll_speed;
    if(map2_y >= GAME_HEIGHT){
        map2_y = 0;
    }
}
