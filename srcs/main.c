/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:33:03 by blavonne          #+#    #+#             */
/*   Updated: 2019/12/30 17:06:56 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		what_key(int key)
{
	if (key == 53)
		return (1);
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS || key == NUM_PAD_MINUS
			|| key == MAIN_PAD_MINUS)
		return (2);
	if (key == ARROW_LEFT || key == ARROW_RIGHT || key == ARROW_UP || key ==
	ARROW_DOWN || key == MOUSE_SCROLL_UP || key == MOUSE_SCROLL_DOWN)
		return (3);
	if (key == NUM_PAD_2 || key == MAIN_PAD_2 || key == NUM_PAD_8 ||
		key == MAIN_PAD_8 || key == NUM_PAD_4 || key == MAIN_PAD_4 || key ==
		NUM_PAD_6 || key == MAIN_PAD_6 || key == NUM_PAD_1 || key ==
		MAIN_PAD_1 || key == NUM_PAD_3 || key == MAIN_PAD_3 || key ==
		NUM_PAD_7 || key == MAIN_PAD_7 || key == NUM_PAD_9 || key == MAIN_PAD_9)
		return (4);
	if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		return (5);
	return (0);
}

static int		mouse_press(int button, int x, int y, t_fdf *fdf)
{
	x = 1;
	y = 1;
	if (what_key(button) == 3)
		zoom(button, fdf);
	return (1);
}

static void		clean_fdf(t_fdf *fdf)
{
	clean_int_matrix(fdf->z, fdf->rows);
	clean_int_matrix(fdf->incidence_matrix, fdf->rows);
	mlx_destroy_image((*fdf).mlx_ptr, (*fdf).image.img_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	free(fdf->mlx_ptr);
}

static int		deal_key(int key, t_fdf *fdf)
{
	if (what_key(key) == 1)
	{
		clean_fdf(fdf);
		exit(0);
	}
	if (what_key(key) == 2)
		zoom(key, fdf);
	else if (what_key(key) == 3)
		move(key, fdf);
	else if (what_key(key) == 4)
		rotate(key, fdf);
	else if (what_key(key) == 5)
		changez(key, fdf);
	return (1);
}

int				main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2 || !read_and_init(argv[1], &fdf))
	{
		ft_putstr_fd("Input reading error.\nusage: ./fdf filename.fdf\n", 2);
		exit(0);
	}
	mlx_hook(fdf.win_ptr, 2, 0, deal_key, &fdf);
	mlx_hook(fdf.win_ptr, 4, 0, mouse_press, &fdf);
	draw_image(&fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
