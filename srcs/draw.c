#include "fdf.h"

t_point	*point(size_t r, size_t c)
{
	t_point	*p;

	if (!(p = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	p->r = r;
	p->c = c;
	return (p);
}

void	draw(t_fdf **fdf)
{
	size_t	r;
	size_t	c;

	r = 0;
	while (r < (*fdf)->rows)
	{
		c = 0;
		while (c < (*fdf)->cols)
		{
			if (c + 1 < (*fdf)->cols)
				bresenham(point(r, c), point(r, c + 1), *fdf);
			if (r + 1 < (*fdf)->rows)
				bresenham(point(r, c), point(r + 1, c), *fdf);
			c++;
		}
		r++;
	}
}

void	draw_image(t_fdf **fdf)
{
	void	*iptr;
	int 	endian;
	int 	size_line;
	int 	bps;
	int 	*address;

	if ((*fdf)->img_ptr)
	{
		mlx_destroy_image((*fdf)->mlx_ptr, (*fdf)->img_ptr);
		printf("Draw\n");
	}
	bps = 32;
	endian = 0;
	size_line = (*fdf)->space * (*fdf)->cols * 4;
	iptr = mlx_new_image((*fdf)->mlx_ptr, IMG_WIDTH * (*fdf)->space / 20,
						 IMG_HEIGHT * (*fdf)->space / 20);
	(*fdf)->img_ptr = iptr;
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
	mlx_put_image_to_window((*fdf)->mlx_ptr, (*fdf)->win_ptr, iptr,
							(*fdf)->shift_x, (*fdf)->shift_y);
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
	alpha = 20;
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
				bresenham(&point, &point2, fdf);
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
				bresenham(&point, &point2, fdf);
				free(point);
				free(point2);
			}
			fdf->color += 100;
			c++;
		}
		r++;
	}
	return (1);
}
