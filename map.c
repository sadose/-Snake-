#include "global.h"
#include "map.h"
#include "snake.h"
#include "food.h"
#include <stdio.h>

void InitMap(enum mapmark map[MAP_H][MAP_W])
{
	int i, j;
	for (i = 0; i < MAP_H; i++)
		for (j = 0; j < MAP_W; j++)
			map[i][j] = SPACE;
	for (i = 0; i < 4; i++)
		map[1][i] = SNAKE;
}

void LoadMap(enum mapmark map[MAP_H][MAP_W], snake * s, struct food * f)
{
	body * pr = NULL;
	int i, j;

	pr = s->p;
	while (pr != NULL)
	{
		map[pr->x][pr->y] = TEMP;
		pr = pr->next;
	}
	for(i=0;i<MAP_H;i++)
		for (j = 0; j < MAP_W; j++)
		{
			if (map[i][j] == TEMP)
				map[i][j] = SNAKE;
			else map[i][j] = SPACE;
		}
	map[f->x][f->y] = FOOD;
}

void PrintMap(enum mapmark map[MAP_H][MAP_W])
{
	int i, j;

	for (i = 0; i < MAP_W + 2; i++)
		printf("森");
	printf("\n");
	for (i = 0; i < MAP_H; i++)
	{
		printf("森");
		for(j=0;j<MAP_W;j++)
			switch (map[i][j])
			{
			case SPACE:
				printf("　");
				break;
			case SNAKE:
				printf("■");
				break;
			case FOOD:
				printf("○");
				break;
			default:
				printf("!");
			}
		printf("森");
		if (i == MAP_H / 2 - 2)
			printf("　　　　游戏速度：% .3d", SnakeSpeed);
		else if (i == MAP_H / 2 - 1)
			printf("　　　　当前得分：% .3d", Grade);
		printf("\n");
	}
	for (i = 0; i < MAP_W + 2; i++)
		printf("森");
	printf("\n");
}
