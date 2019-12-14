/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cntrl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:45:38 by jquincy           #+#    #+#             */
/*   Updated: 2019/12/14 04:48:24 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	(*fdf).color = 0x000000;
	draw_qtrn(fdf);
	(*fdf).color = 0xAAAA00;
	printf("Zoom\n");
	if (key == MAIN_PAD_PLUS ||
		key == NUM_PAD_PLUS ||
		key == MOUSE_SCROLL_UP)
		(*fdf).space++;
	else if (key == MAIN_PAD_MINUS ||
			 key == NUM_PAD_MINUS ||
			 key == MOUSE_SCROLL_DOWN)
		(*fdf).space--;
	if ((*fdf).space < 1)
		(*fdf).space = 1;
	draw_qtrn(fdf);
//	draw_image(fdf);
}

void	move(int key, t_fdf *fdf)
{
	(*fdf).color = 0x000000;
	draw_qtrn(fdf);
	(*fdf).color = 0xAAAA00;
	printf("Move\n");
	if (key == ARROW_LEFT)
		(*fdf).shift_x -= 10;
	else if (key == ARROW_RIGHT)
		(*fdf).shift_x += 10;
	else if (key == ARROW_UP)
		(*fdf).shift_y -= 10;
	else
		(*fdf).shift_y += 10;
	draw_qtrn(fdf);
//	draw_image(fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	(*fdf).color = 0x000000;
	draw_qtrn(fdf);
	(*fdf).color = 0xAAAA00;
	printf("Rotate\n");
	if (key == NUM_PAD_2 || key == MAIN_PAD_2)
		fdf->angle -= 1;
	else if (key == NUM_PAD_8 || key == MAIN_PAD_8)
		fdf->angle += 1;
//	else if (key == NUM_PAD_4 || key == MAIN_PAD_4)
//		fdf->camera->bt -= 0.05;
//	else if (key == NUM_PAD_6 || key == MAIN_PAD_6)
//		fdf->camera->bt += 0.05;
//	else if (key == NUM_PAD_1 || key == MAIN_PAD_1
//		|| key == NUM_PAD_3 || key == MAIN_PAD_3)
//		fdf->camera->gm += 0.05;
//	else if (key == NUM_PAD_7 || key == MAIN_PAD_7
//		|| key == NUM_PAD_9 || key == MAIN_PAD_9)
//		fdf->camera->gm -= 0.05;
	draw_qtrn(fdf);
//	draw;
}

//void	changez(int key, t_fdf *fdf)
//{
//	if (key == MAIN_PAD_LESS)
//		fdf->camera->z_div -= 0.1;
//	else if (key == MAIN_PAD_MORE)
//		fdf->camera->z_div += 0.1;
//	if (fdf->camera->z_div < 0.1)
//		fdf->camera->z_div = 0.1;
//	else if (fdf->camera->z_div > 10)
//		fdf->camera->z_div = 10;
//	//draw;
//}

//void	change_projection(int key, t_fdf *fdf)
//{
//	fdf->camera->al = 0;
//	fdf->camera->bt = 0;
//	fdf->camera->gm = 0;
//	if (key == MAIN_PAD_I)
//		fdf->camera->projection = ISO;
//	else if (key == MAIN_PAD_P)
//		fdf->camera->projection = PARALLEL;
//	draw(fdf->map, fdf);
//}
