#include "fdf.h"
#define MAX(a, b) a > b ? a : b

void	bresenham(t_point *start, t_point *end, t_fdf *fdf)
{
	float	dx;
	float	dy;
	int 	max;
//	int 	z;

//	printf("INT %i %i\n", (int)start->r/(int)fdf->space, (int)start->c/
//			(int)fdf->space); //выход за пределы массива, т.к. индексы
//			// умножены в другой функции
//	z = fdf->z[(int)start->r][(int)start->c];
	dx = end->c - start->c;
	dy = end->r - start->r;
	max = MAX(abs((int)dx), abs((int)dy));

	dx /= (float)max;
	dy /= (float)max;
	while ((int)(start->c - end->c) || (int)(start->r - end->r))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, start->c, start->r,
		0x00AAAA00);
		start->c += dx;
		start->r += dy;
	}
	free(start);
	free(end);
}
