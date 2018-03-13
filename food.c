#include "food.h"
#include "global.h"
#include "map.h"
#include "snake.h"
#include <stdlib.h>
#include <time.h>

void SetFood(snake * s, struct food * f)
{
	int xx, yy;
	body * pr = NULL;
	srand((unsigned)time(NULL));

	while(1)
	{
		xx = rand() % MAP_H;
		yy = rand() % MAP_W;

		pr = s->p;
		while (pr != NULL)
		{
			if (pr->x == xx && pr->y == yy) break;
			pr = pr->next;
		}
		if (pr == NULL) break;
	}

	f->x = xx;
	f->y = yy;
}
