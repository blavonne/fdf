#include "fdf.h"
#define MAX(a, b) a > b ? a : b

t_qtrn	*create_qtrn(float x, float y, int z, int angle)
{
	t_qtrn	*new;
	double	r_angle;

	r_angle = (angle * 0.5) * M_PI / 180;
	if (!(new = (t_qtrn *)malloc(sizeof(t_qtrn))))
		return NULL;
	new->cos_a = cos(r_angle);
	new->sin_a = sin(r_angle);
	new->x = new->sin_a * x;
	new->y = new->sin_a * y;
	new->z = new->sin_a * z;
	return (new);
}

t_qtrn	*reverse_qtrn(t_qtrn *prev)
{
	t_qtrn	*new;
	double	modulo;

	modulo = sqrt(pow(prev->x, 2) + pow(prev->y, 2) + pow(prev->z, 2) + pow
			(prev->cos_a, 2));
	if (!(new = (t_qtrn *)malloc(sizeof(t_qtrn))))
		return NULL;
	new->cos_a = prev->cos_a;
	new->x = (prev->x != 0.0) ? (-prev->x / modulo) : 0;
	new->y = (prev->y != 0.0) ? (-prev->y / modulo) : 0;
	new->z = (prev->z != 0.0) ? (-prev->z / modulo) : 0;
	return (new);
}

t_qtrn	*create_vector(float x, float y, int z)
{
	t_qtrn	*new;

	if (!(new = (t_qtrn *)malloc(sizeof(t_qtrn))))
		return NULL;
	new->x = x;
	new->y = y;
	new->z = z;
	new->cos_a = 0;
	new->sin_a = 1;
	return (new);
}

t_qtrn	*qtrn_multiply(t_qtrn **qtrn, t_qtrn **vector)
{
	t_qtrn	*res;

	if (!(res = (t_qtrn *)malloc(sizeof(t_qtrn))))
		return NULL;
	res->cos_a = (*qtrn)->cos_a * (*vector)->cos_a - (*qtrn)->x * (*vector)->x
			- (*qtrn)->y * (*vector)->y - (*qtrn)->z * (*vector)->z;
	res->x = (*qtrn)->cos_a * (*vector)->x + (*vector)->cos_a * (*qtrn)->x +
			(*qtrn)->y * (*vector)->z - (*vector)->y * (*qtrn)->z;
	res->y = (*qtrn)->cos_a * (*vector)->y + (*vector)->cos_a * (*qtrn)->y +
			(*qtrn)->z * (*vector)->x - (*vector)->z * (*qtrn)->x;
	res->z = (*qtrn)->cos_a * (*vector)->z + (*vector)->cos_a * (*qtrn)->z +
			 (*qtrn)->x * (*vector)->y - (*vector)->x * (*qtrn)->y;
	return (res);
}

t_qtrn 	*rotation(t_qtrn **napravlenie, t_qtrn **vector, t_qtrn **reversed)
{
	t_qtrn	*tmp;
	t_qtrn	*res;

	if (!(tmp = qtrn_multiply(napravlenie, vector)))
		return NULL;
	if (!(res = qtrn_multiply(&tmp, reversed)))
		return NULL;
	free(tmp);
	return (res);
}

t_qtrn 	*quaterni(int angle, float x, float y, int z)
{
	t_qtrn	*os;
	t_qtrn	*vector;
	t_qtrn	*os_rev;
	t_qtrn	*res;
	int 	rotation_angle;

	rotation_angle = angle;
	if (!(os = create_qtrn(1.0, 0.00, 0, rotation_angle)))
		return NULL;
	if (!(vector = create_vector(x, y, z)))
	{
		free(os);
		return NULL;
	}
	if (!(os_rev = reverse_qtrn(os)))
	{
		free(os);
		free(vector);
		return NULL;
	}
	//создать новый кватернион,
	if (!(res = rotation(&os, &vector, &os_rev)))
	{
		free(os);
		free(vector);
		free(os_rev);
		return NULL;
	}
	return (res);
}

void	bresenham2(t_qtrn **start, t_qtrn **end, t_fdf *fdf)
{
	double	dx;
	double	dy;
	int 	max;

//	(*start)->x *= 0.0001;
	(*start)->x += 250;
//	(*start)->y *= 0.0001;
	(*start)->y += 250;
//	(*end)->x *= 0.0001;
	(*end)->x += 250;
//	(*end)->y *= 0.0001;
	(*end)->y += 250;
	dx = (*end)->x - (*start)->x;
	dy = (*end)->y - (*start)->y;
	max = MAX(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	printf("start: [%i][%i]\nend: [%i][%i]\ndelta: dx[%i], dy[%i]\n",
			(*start)->x, (*start)->y, (*end)->x, (*end)->y, dx, dy);
	while (((*end)->x - (*start)->x) > 0.5 || ((*end)->y - (*start)->y) > 0.5)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (*start)->x, (*start)->y,
				fdf->color);
		(*start)->x += dx;
		(*start)->y += dy;
	}
}

int		draw_qtrn(t_fdf *fdf)
{
	size_t	r;
	size_t	c;
	t_qtrn	*point;
	t_qtrn	*point2;
	int alpha;

	point = NULL;
	point2 = NULL;
	r = 0;
	alpha = 90;
	while (r < fdf->rows)
	{
		c = 0;
		while (c < fdf->cols)
		{
			if (c + 1 < fdf->cols)
			{
				point = quaterni(alpha, c * fdf->space, r * fdf->space,
								 fdf->z[r][c] * fdf->space);
				point2 = quaterni(alpha, (c + 1) * fdf->space, r * fdf->space,
								  fdf->z[r][c + 1] * fdf->space);
				if (!point || !point2)
					return (0);
				bresenham2(&point, &point2, fdf);
				free(point);
				free(point2);
			}
			if (r + 1 < fdf->rows)
			{
				point = quaterni(alpha, c * fdf->space, r * fdf->space,
								 fdf->z[r][c] * fdf->space);
				point2 = quaterni(alpha, c * fdf->space, (r + 1) * fdf->space,
								  fdf->z[r + 1][c] * fdf->space);
				if (!point || !point2)
					return (0);
				bresenham2(&point, &point2, fdf);
				free(point);
				free(point2);
			}
			c++;
		}
		r++;
	}
	return (1);
}
