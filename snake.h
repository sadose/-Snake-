#pragma once

#define TIME1 450
#define TIME2 350
#define TIME3 250
#define TIME4 150
#define TIME5 75

//蛇链表
struct node
{
	int x;
	int y;
	struct node * next;
};

struct head
{
	int length;
	struct node * p;
};

typedef struct head snake;
typedef struct node body;

//蛇的移动方向枚举类型及其变量
enum direction
{
	U=1,
	D,
	L,
	R
};

enum direction SnakeDir;

//蛇的状态枚举类型及其变量
enum status
{
	ALIVE=1,
	WALL,
	BODY
};

enum status SnakeStatus;

//蛇的移动速度
int SnakeSpeed;//取值1-5，具体的时间值在宏中给出

//函数声明
snake * InitSnake();							//返回一条蛇
void SnakeMove(snake * s, struct food * f);		//移动蛇
void FreeSnake(snake * s);						//销毁蛇
