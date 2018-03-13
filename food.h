#pragma once

#include "snake.h"

//食物结构体类型
struct food
{
	int x;
	int y;
};

//函数声明
void SetFood(snake *s, struct food *f);	//先创建食物结构体，再放置食物
