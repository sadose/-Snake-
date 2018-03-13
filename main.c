#define RELEASE

#include "global.h"
#include "map.h"
#include "snake.h"
#include "food.h"
#include <stdio.h>
#include <Windows.h>
#include <process.h>
#include <conio.h>

#ifdef TEXT_MAP

void main()
{
	Grade = 123;
	SnakeSpeed = 5;
	InitMap(Map);
	PrintMap(Map);
	getchar();
}

#endif

#ifdef TEXT_PRI

void main()
{
	printf("����\n������");
	getchar();
}

#endif

#ifdef TEXT_INP

void main()
{
	int ch, i;

	for (i = 0; i < 20; i++)
	{
		ch = _getch();
		printf("\n===\n%d\n===\n", ch);
	}
}

#endif

#ifdef RELEASE

//��Ϸ���̴������ʼ

void WelcomeScreen()
{
	SnakeSpeed = 0;

	printf("\n\n\n\n\n\n��������������������");
	printf("��ӭ����̰������Ϸ��");
	printf("\n\n\n��������������������������");
	printf("\n\n\n\n= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n��������������������");
	printf("��������Ϸ�ٶȣ�1-5��:");
	
	do scanf("%d", &SnakeSpeed);
	while ((SnakeSpeed <= 0 || SnakeSpeed > 5)?printf("�������������������������������������룺"):0);
}

void EndScreen()
{
	printf("\n\n\n\n\n\n��������������������");
	printf("��Ϸ������");
	if (SnakeStatus == WALL)
		printf("��ײ����Χǽ��\n");
	else if (SnakeStatus == BODY)
		printf("��ײ�����Լ���\n");
	printf("\n\n\n��������������������");
	printf("���ĵ÷֣�%d\n\n\n\n", Grade);
}

void GetDir()
{
	int ch;

	while (SnakeStatus == ALIVE)
	{
		ch = _getch();
		switch (ch)
		{
		case 119:
		case 72:
		case 87:
			if (SnakeDir == L || SnakeDir == R)
				SnakeDir = U;
			break;
		case 115:
		case 80:
		case 83:
			if (SnakeDir == L || SnakeDir == R)
				SnakeDir = D;
			break;
		case 97:
		case 75:
		case 65:
			if (SnakeDir == U || SnakeDir == D)
				SnakeDir = L;
			break;
		case 100:
		case 77:
		case 68:
			if (SnakeDir == U || SnakeDir == D)
				SnakeDir = R;
			break;
		default:
			break;
		}
	}
}

void main()
{
	HANDLE sub;

	snake *theSnake;
	theSnake = InitSnake();

	struct food Food, *theFood;
	theFood = &Food;
	SetFood(theSnake, theFood);

	InitMap(Map);

	Grade = 0;
	SnakeDir = R;

	WelcomeScreen();
	printf("\n\n\n\n\n��������������������������ɣ�׼��������Ϸ��\n");

	sub = (HANDLE)_beginthread(GetDir, 0, NULL);
	Sleep(2000);

	while (SnakeStatus == ALIVE)
	{
		LoadMap(Map, theSnake, theFood);
		system("cls");
		PrintMap(Map);

		switch (SnakeSpeed)
		{
		case 1:
			Sleep(TIME1);
			break;
		case 2:
			Sleep(TIME2);
			break;
		case 3:
			Sleep(TIME3);
			break;
		case 4:
			Sleep(TIME4);
			break;
		case 5:
			Sleep(TIME5);
			break;
		}
		SnakeMove(theSnake, theFood);
	}

	FreeSnake(theSnake);
	system("cls");
	EndScreen();
	printf("��������������������");
	system("pause");
}

#endif
