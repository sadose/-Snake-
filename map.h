#pragma once

#include "global.h"
#include "snake.h"

//��ͼ���ö������
enum mapmark {
	SPACE=1,
	FOOD,
	SNAKE,
	TEMP
};

//�����ͼ��ά����
enum mapmark Map[MAP_H][MAP_W];

//�÷�
int Grade;

//��������
void InitMap(enum mapmark map[MAP_H][MAP_W]);								//��ʼ����ͼ������ʱ��
void LoadMap(enum mapmark map[MAP_H][MAP_W], snake * s, struct food * f);	//��Ⱦ��ͼ
void PrintMap(enum mapmark map[MAP_H][MAP_W]);								//��ӡ��ͼ
