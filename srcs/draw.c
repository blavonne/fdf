#include "fdf.h"

int		draw_image(t_fdf *fdf)
{
	int 	endian;
	int 	size_line;
	int 	bps;
	int 	*image;
	int 	a;

	if ((*fdf).img_ptr)
	{
		mlx_destroy_image((*fdf).mlx_ptr, (*fdf).img_ptr);
		printf("Prev image is deleted\n");
	}
	bps = 32;
	endian = 0;
	size_line = (*fdf).space * (*fdf).cols * (int)sizeof(int);
	// ширина * высота картинки = диаметр шара, описанного вокруг куба со
	// стороной = макс(ряды, колонки) * зум.
	// диаметр шара = диагональ куба = sqrt(3) * a;
	a = ((*fdf).cols < (*fdf).rows) ? (*fdf).rows : (*fdf).cols;
	a = (int)round(a * sqrt(3.0)) * (int)(*fdf).space;
	if (!((*fdf).img_ptr = mlx_new_image((*fdf).mlx_ptr, a, a)))
		return (0);
	image = (int *)mlx_get_data_addr((*fdf).img_ptr, &bps, &size_line, &endian);

	int i;

	i = 0;
	while (i < 1000)
	{
		image[i] = 0x00FFFFFF;
		i++;
	}
	while (i < 2000)
	{
		image[i] = 0x000000FF;
		i++;
	}
	while (i < 3000)
	{
		image[i] = 0x00FF0000;
		i++;
	}
	mlx_put_image_to_window((*fdf).mlx_ptr, (*fdf).win_ptr, (*fdf).img_ptr,
							(*fdf).shift_x, (*fdf).shift_y);
	return (1);
}

void	draw_qtrn(t_fdf *fdf)
{
	int		r;
	int		c;

	r = 0;
	while (r < fdf->rows)
	{
		c = 0;
		while (c < fdf->cols)
		{
			bresenham(quaterni(fdf, r, c), quaterni(fdf, r, c), fdf);
			if (c + 1 < fdf->cols)
				bresenham(quaterni(fdf, r, c), quaterni(fdf, r, c + 1), fdf);
			if (r + 1 < fdf->rows)
				bresenham(quaterni(fdf, r, c), quaterni(fdf, r + 1, c), fdf);
			fdf->color += 100;
			c++;
		}
		r++;
	}
}
