#pragma once

#define TIME1 450
#define TIME2 350
#define TIME3 250
#define TIME4 150
#define TIME5 75

//������
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

//�ߵ��ƶ�����ö�����ͼ������
enum direction
{
	U=1,
	D,
	L,
	R
};

enum direction SnakeDir;

//�ߵ�״̬ö�����ͼ������
enum status
{
	ALIVE=1,
	WALL,
	BODY
};

enum status SnakeStatus;

//�ߵ��ƶ��ٶ�
int SnakeSpeed;//ȡֵ1-5�������ʱ��ֵ�ں��и���

//��������
snake * InitSnake();							//����һ����
void SnakeMove(snake * s, struct food * f);		//�ƶ���
void FreeSnake(snake * s);						//������
