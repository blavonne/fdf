/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:33:03 by blavonne          #+#    #+#             */
/*   Updated: 2019/12/20 17:37:26 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * ptr = mlx_init() - создание указателя на подключение
 * wptr = mlx_new_window(указатель на подключение, ширина, высота,
 * "Заголовок") - указатель окна
 * mlx_loop(ptr) - чтобы не закрывалось, аналог гетча
 * mlx_pixel_put(указатель на подключение, указатель на окно, координата по
 * х, координата по у, цвет RGB 0xAARRGGBB)
 * ESC key 53
 * mlx_key_hook(указатель окна, функция, указатель на параметр функции)
 * функция будет иметь вид "тип название (int key, void *param), где key -
 * нажатая клавиша, которая сама определяется функцией млх кей хук
 */

/*
 * клавиши разбиты на группы, чтобы не нагромождать код след. функции
 */
static int		what_key(int key)
{
	if (key == 53)
		return (1);
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS	|| key == NUM_PAD_MINUS ||
	key == MAIN_PAD_MINUS)
		return (2);
	if (key == ARROW_LEFT || key == ARROW_RIGHT || key == ARROW_UP || key ==
	ARROW_DOWN)
		return (3);
	if (key == NUM_PAD_2 || key == MAIN_PAD_2 || key == NUM_PAD_8 ||
		key == MAIN_PAD_8 || key == NUM_PAD_4 || key == MAIN_PAD_4 || key ==
		NUM_PAD_6 || key == MAIN_PAD_6 || key == NUM_PAD_1 || key ==
		MAIN_PAD_1 || key == NUM_PAD_3 || key == MAIN_PAD_3 || key ==
		NUM_PAD_7 || key == MAIN_PAD_7 || key == NUM_PAD_9 || key == MAIN_PAD_9)
		return (4);
	return (0);
}

static int 	deal_key(int key, t_fdf *fdf)
{
	printf("%i ", key);
	if (what_key(key) == 1)
		exit(0);
	if (what_key(key) == 2)
		zoom(key, fdf);
	else if (what_key(key) == 3)
		move(key, fdf);
	else if (what_key(key) == 4)
		rotate(key, fdf);
	return (0);
}

int main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2 || !read_and_init(argv[1], &fdf))
	{
		ft_putstr_fd("Input reading error.\nusage: ./fdf filename.fdf\n", 2);
		exit(0);
	}
//	mlx_key_hook(fdf.win_ptr, deal_key, &fdf);
	mlx_hook(fdf.win_ptr, 2, 0, deal_key, &fdf);
	draw_image(&fdf);
//	draw_qtrn(&fdf);
	mlx_loop(fdf.mlx_ptr);
//	//очистить fdf
	return (0);
}