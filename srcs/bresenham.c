#include "fdf.h"
#define MAX(a, b) a > b ? a : b

static void	set_zoom(t_point **start, t_point **end, t_fdf *fdf)
{
	(*start)->r = fdf->space * (*start)->r;
	(*start)->c = fdf->space * (*start)->c;
	(*end)->r = fdf->space * (*end)->r;
	(*end)->c = fdf->space * (*end)->c;
}

static void	set_shift(t_point **start, t_point **end, t_fdf *fdf)
{
	(*start)->r += fdf->start_r;
	(*start)->c += fdf->start_c;
	(*end)->r += fdf->start_r;
	(*end)->c += fdf->start_c;
}

static void iso(t_point *point, int z)
{
	double	angle;
	double	r_angle;

	angle = 0;
	r_angle = angle * M_PI / 180;
	point->r = (float)(point->r * cos(r_angle) + point->c * sin(r_angle));
	point->c = (angle > 0) ? (float)(-point->r * sin(r_angle) + point->c * cos
			(r_angle) -	z * 20) : (float)(-point->r * sin(r_angle) + point->c *
					cos(r_angle));
}

//static int	set_color(int z_start, int z_end)
//{
//	// 0x00AAAA00 желтый 0x00AA00AA розовый 0x0000AAAA не знаю
//
//	return (0);
//}

void	bresenham(t_point *start, t_point *end, t_fdf *fdf)
{
	float	dx;
	float	dy;
	int 	max;
	int 	z_start;
	int 	z_end;

	z_start = fdf->z[(int)start->r][(int)start->c];
	z_end = fdf->z[(int)end->r][(int)end->c];
	set_zoom(&start, &end, fdf);
//	fdf->color = set_color(z_start, z_end);
	fdf->color = (z_start || z_end) ? 0x00AA00AA : 0x00AAAA00;
	iso(start, z_start);
	iso(end, z_end);
	set_shift(&start, &end, fdf);
	dx = end->c - start->c;
	dy = end->r - start->r;
	max = MAX(abs((int)dx), abs((int)dy));
	dx /= (float)max;
	dy /= (float)max;
	while ((int)(start->c - end->c) || (int)(start->r - end->r))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, start->c, start->r,
		fdf->color);
		start->c += dx;
		start->r += dy;
	}
	free(start);
	free(end);
}
