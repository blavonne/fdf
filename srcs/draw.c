#include "fdf.h"


//static void	draw_x(t_fdf *fdf)
//{
//	t_point start;
//	t_point	end;
//	size_t	i;
//
//	start.c = fdf->start.c;
//	start.r = fdf->start.r;
//	end.c = fdf->start.c + fdf->space * fdf->cols + 1;
//	end.r = start.r;
//	i = 0;
//	while (i++ <= fdf->rows)
//	{
//		bresenham(start, end, fdf, 0x00AAAA00);
//		start.r += fdf->space;
//		end.r += fdf->space;
//	}
//}
//
//static void	draw_y(t_fdf *fdf)
//{
//	t_point start;
//	t_point	end;
//	size_t	i;
//
//	i = 0;
//	start.c = fdf->start.c;
//	start.r = fdf->start.r;
//	end.r = fdf->start.r + fdf->space * (fdf->rows);
//	end.c = start.c;
//	while (i++ <= fdf->cols)
//	{
//		bresenham(start, end, fdf, 0x00AAAA00);
//		start.c += fdf->space;
//		end.c += fdf->space;
//	}
//}

t_point	*point(size_t r, size_t c, t_fdf **fdf)
{
	t_point	*p;

	if (!(p = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	p->r = (*fdf)->start_r + (float)r * (float)(*fdf)->space;
	p->c = (*fdf)->start_c + (float)c * (float)(*fdf)->space;
	return (p);
}

void	draw(t_fdf **fdf)
{
	size_t	r;
	size_t	c;

	r = 0;
	while (r <= (*fdf)->rows)
	{
		c = 0;
		while (c <= (*fdf)->cols)
		{
			if (c < (*fdf)->cols)
				bresenham(point(r, c, fdf), point(r, c + 1, fdf), *fdf);
			if (r < (*fdf)->rows)
				bresenham(point(r, c, fdf), point(r + 1, c, fdf), *fdf);
			c++;
		}
		r++;
	}
}

void	draw_image(t_fdf *fdf)
{
	void	*iptr;
	int 	endian;
	int 	size_line;
	int 	bps;
	int 	*address;

	bps = 32;
	endian = 0;
	size_line = fdf->space * fdf->cols * 4;
	iptr = mlx_new_image(fdf->mlx_ptr, fdf->space * fdf->cols + 10,
			fdf->space * fdf->rows + 10);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, iptr, 80, 80);
	address = (int *)mlx_get_data_addr(iptr, &bps, &size_line, &endian);
	int i;

	i = 0;
	while (i < 1000)
	{
		address[i] = 0x00FFFFFF;
		i++;
	}
	while (i < 2000)
	{
		address[i] = 0x000000FF;
		i++;
	}
	while (i < 3000)
	{
		address[i] = 0x00FF0000;
		i++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, iptr, 50, 20);
}
