//#include "fdf.h"
//
////static void	set_zoom(t_point **start, t_point **end, t_fdf *fdf)
////{
////	(*start)->r = fdf->space * (*start)->r;
////	(*start)->c = fdf->space * (*start)->c;
////	(*end)->r = fdf->space * (*end)->r;
////	(*end)->c = fdf->space * (*end)->c;
////}
//
//static void	set_delta(double *dx, double *dy, t_qtrn *start, t_qtrn *end)
//{
//	(*start).x = round((*start).x);
//	(*start).y = round((*start).y);
//	(*end).x = round((*end).x);
//	(*end).y = round((*end).y);
//	if ((*start).x == (*end).x && (*start).y == (*end).y)
//		return ;
//	if (fabs((*start).x - (*end).x) > fabs((*start).y - (*end).y))
//	{
//		*dx = ((*start).x <= (*end).x) ? 1.0 : -1.0;
//		*dy = ((*start).y <= (*end).y) ? (fabs((*start).y - (*end).y) /
//			(fabs((*start).x - (*end).x))) : (-1.0 * fabs((*start).y -
//				(*end).y) / (fabs((*start).x - (*end).x)));
//	}
//	else
//	{
//		*dy = ((*start).y <= (*end).y) ? 1.0 : -1.0;
//		*dx = ((*start).x <= (*end).x) ? (fabs((*start).x - (*end).x) /
//			(fabs((*start).y - (*end).y))) : (-1.0 * fabs((*start).x -
//				(*end).x) / (fabs((*start).y - (*end).y)));
//	}
////	printf("dx %f, dy %f\n", *dx, *dy); //DELETE
//}
//
//static void	set_shift(t_qtrn *start, t_qtrn *end, int shift_x, int shift_y)
//{
//	(*start).x += shift_x;
//	(*end).x += shift_x;
//	(*start).y += shift_y;
//	(*end).y += shift_y;
//}
//
//void	bresenham(t_qtrn start, t_qtrn end, t_fdf *fdf)
//{
//	double	dx;
//	double	dy;
//	int 	i;
//
//	i = 0;
//	set_shift(&start, &end, fdf->shift_x, fdf->shift_y);
//	set_delta(&dx, &dy, &start, &end);
//	if (start.x == end.x && start.y == end.y)
//		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)round(start.x),
//					  (int)round(start.y), fdf->color);
//	while (fabs(start.x - end.x) > 0.5 || fabs(start.y - end.y) > 0.5)
//	{
//		// условие означает, что, если между точками есть разница при
//		// округлении, то мы будем отрисовывать точку. округление, как в
//		// математике.
//		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)round(start.x),
//					  (int)round(start.y), fdf->color);
//		start.x += dx;
//		start.y += dy;
//	}
//}