#pragma once

#include "snake.h"

//ʳ��ṹ������
struct food
{
	int x;
	int y;
};

//��������
void SetFood(snake *s, struct food *f);	//�ȴ���ʳ��ṹ�壬�ٷ���ʳ��
