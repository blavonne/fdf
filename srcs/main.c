/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:33:03 by blavonne          #+#    #+#             */
/*   Updated: 2019/12/02 18:21:44 by blavonne         ###   ########.fr       */
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

int 	deal_key(int key, void *param)
{
	param = 0;
	ft_putnbr(key);
	if (key == 53)
		exit(0);
	return (0);
}

int main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2 || !read_map(argv[1], &fdf))
	{
		ft_putstr_fd("Input reading error.\nusage: ./fdf filename.fdf\n", 2);
		exit(0);
	}
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 600, "I NEED A DOCTOR");
	mlx_key_hook(fdf->win_ptr, deal_key, (void *)0);
//	draw(&fdf);
//	draw_image(fdf);
	draw_qtrn(fdf);
	mlx_loop(fdf->mlx_ptr);
	//очистить fdf
	return (0);
}