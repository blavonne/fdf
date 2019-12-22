#include "fdf.h"

void	draw_background(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i < WIN_W * WIN_H)
	{
		(*fdf).image.image[i] = (i % WIN_W < MENU_W) ? MENU_COLOR : BACKGROUND;
		i++;
	}
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
			bresenham(quaterni(fdf, r, c), quaterni(fdf, r, c), fdf,
					  fdf->z[r][c]);
			if (c + 1 < fdf->cols)
				bresenham(quaterni(fdf, r, c), quaterni(fdf, r, c + 1), fdf, fdf->z[r][c]);
			if (r + 1 < fdf->rows)
				bresenham(quaterni(fdf, r, c), quaterni(fdf, r + 1, c), fdf, fdf->z[r][c]);
			c++;
		}
		r++;
	}
}

int 	draw_image(t_fdf *fdf)
{
	if (!((*fdf).image.img_ptr = mlx_new_image((*fdf).mlx_ptr, WIN_W, WIN_H)))
		return (0);
	(*fdf).image.image = (int *)mlx_get_data_addr((*fdf).image.img_ptr, &(*fdf)
			.image.bps,	&(*fdf).image.size_line, &(*fdf).image.endian);
	draw_background(fdf);
	print_menu(fdf);
	draw_qtrn(fdf);
	mlx_put_image_to_window((*fdf).mlx_ptr, (*fdf).win_ptr, (*fdf).image
			.img_ptr,0, 0);
	print_menu(fdf);
	return (1);
}
