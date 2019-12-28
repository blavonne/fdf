#include "fdf.h"

static void	set_zoom(t_qtrn *start, t_qtrn *end, t_fdf *fdf)
{
	start->y = fdf->space * start->y;
	start->x = fdf->space * start->x;
	end->y = fdf->space * end->y;
	end->x = fdf->space * end->x;
}

static void	set_delta(double *dx, double *dy, t_qtrn *start, t_qtrn *end)
{
	(*start).x = round((*start).x);
	(*start).y = round((*start).y);
	(*end).x = round((*end).x);
	(*end).y = round((*end).y);
	if ((*start).x == (*end).x && (*start).y == (*end).y)
		return ;
	if (fabs((*start).x - (*end).x) > fabs((*start).y - (*end).y))
	{
		*dx = ((*start).x <= (*end).x) ? 1.0 : -1.0;
		*dy = ((*start).y <= (*end).y) ? (fabs((*start).y - (*end).y) /
			(fabs((*start).x - (*end).x))) : (-1.0 * fabs((*start).y -
				(*end).y) / (fabs((*start).x - (*end).x)));
	}
	else
	{
		*dy = ((*start).y <= (*end).y) ? 1.0 : -1.0;
		*dx = ((*start).x <= (*end).x) ? (fabs((*start).x - (*end).x) /
			(fabs((*start).y - (*end).y))) : (-1.0 * fabs((*start).x -
				(*end).x) / (fabs((*start).y - (*end).y)));
	}
//	printf("dx %f, dy %f\n", *dx, *dy); //DELETE
}

static void	set_shift(t_qtrn *start, t_qtrn *end, t_fdf *fdf)
{
	(*start).x += fdf->shift_x;
	(*end).x += fdf->shift_x;
	(*start).y += fdf->shift_y;
	(*end).y += fdf->shift_y;
//	(*start).x += fdf->shift_x - fdf->space * round(0.5 * fdf->cols);
//	(*end).x += fdf->shift_x - fdf->space * round(0.5 * fdf->cols);
//	(*start).y += fdf->shift_y - fdf->space * round(0.5 * fdf->rows);
//	(*end).y += fdf->shift_y - fdf->space * round(0.5 * fdf->rows);
}

void	bresenham(t_qtrn start, t_qtrn end, t_fdf *fdf, t_qtrn z)
{
	double	dx;
	double	dy;
	int		z_color;

	set_zoom(&start, &end, fdf);
	set_delta(&dx, &dy, &start, &end);
    set_shift(&start, &end, fdf);
	z_color = (z.x || z.y) ? Z_COLOR : IMAGE_COLOR;
	z_color = (z.x == z.y && z.x == fdf->max_z) ? Z_MAX : z_color;
	if (start.x == end.x && start.y == end.y && (int)round(start.x) >= 0 &&
		(int)round(start.x) < WIN_W && (int)round(start.y) >= 0 &&
			(int)round(start.y) < WIN_H)
        fdf->image.image[(int)round(start.x) + (int)round(start.y) * WIN_W]
                = ((int)round(start.x) + (int)round(start.y) * WIN_W % WIN_W <
                   MENU_W) ? MENU_COLOR : z_color;
	while ((fabs(start.x - end.x) > 0.5 || fabs(start.y - end.y) > 0.5))
	{
		//переставить условие ниже
		// условие означает, что, если между точками есть разница при
		// округлении, то мы будем отрисовывать точку. округление, как в
		// математике.
        if ((int)round(start.x) >= 0 && (int)round(start.x) < WIN_W &&
            (int)round(start.y) >= 0 && (int)round(start.y) < WIN_H)
            fdf->image.image[(int)round(start.x) + (int)round(start.y) * WIN_W]
                    = ((int)round(start.x) + (int)round(start.y) * WIN_W % WIN_W <
                       MENU_W) ? MENU_COLOR : z_color;
		start.x += dx;
		start.y += dy;
	}
}
