#pragma once

#include "global.h"
#include "snake.h"

//地图标记枚举类型
enum mapmark {
	SPACE=1,
	FOOD,
	SNAKE,
	TEMP
};

//定义地图二维数组
enum mapmark Map[MAP_H][MAP_W];

//得分
int Grade;

//函数声明
void InitMap(enum mapmark map[MAP_H][MAP_W]);								//初始化地图，测试时用
void LoadMap(enum mapmark map[MAP_H][MAP_W], snake * s, struct food * f);	//渲染地图
void PrintMap(enum mapmark map[MAP_H][MAP_W]);								//打印地图
