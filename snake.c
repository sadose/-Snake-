#include "snake.h"
#include "map.h"
#include "global.h"
#include "food.h"
#include <malloc.h>

snake * InitSnake()
{
	snake *pr;
	body *a, *b;
	int i;

	pr = (snake *)malloc(sizeof(snake));
	pr->length = 0;
	a = NULL;
	for (i = 0; i < 4; i++)
	{
		b = (body *)malloc(sizeof(body));
		b->x = 1;
		b->y = i;
		b->next = a;
		pr->length++;
		a = b;
	}
	pr->p = a;

	SnakeStatus = ALIVE;

	return pr;
}

void SnakeMove(snake * s, struct food * f)
{
	int xx, yy;
	body *pr = NULL, *b = NULL;

	xx = s->p->x;
	yy = s->p->y;

	switch (SnakeDir)
	{
	case U:
		xx--;
		break;
	case D:
		xx++;
		break;
	case L:
		yy--;
		break;
	case R:
		yy++;
	}

	if (xx < 0 || xx >= MAP_H || yy < 0 || yy >= MAP_W)
	{
		SnakeStatus = WALL;
		return;
	}
	pr = s->p;
	while (pr != NULL)
	{
		if (xx == pr->x && yy == pr->y && pr->next != NULL)
		{
			SnakeStatus = BODY;
			return;
		}
		pr = pr->next;
	}
	if (xx == f->x && yy == f->y)
	{
		b = (body *)malloc(sizeof(body));
		b->x = xx;
		b->y = yy;
		b->next = s->p;
		s->p = b;
		s->length++;
		Grade = Grade + SnakeSpeed;
		SetFood(s, f);
		return;
	}
	else
	{
		pr = s->p;
		while (pr != NULL)
		{
			if (pr->next->next == NULL)
			{
				pr->next->x = xx;
				pr->next->y = yy;
				pr->next->next = s->p;
				s->p = pr->next;
				pr->next = NULL;
				return;
			}
			pr = pr->next;
		}
	}
}

void FreeSnake(snake * s)
{
	body *a, *b;

	b = s->p;
	while (b != NULL)
	{
		a = b;
		b = b->next;
		free(a);
	}

	free(s);
}
