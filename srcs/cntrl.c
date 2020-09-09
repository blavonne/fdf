/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cntrl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:45:38 by jquincy           #+#    #+#             */
/*   Updated: 2019/12/30 17:33:26 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int key, t_fdf *fdf)
{
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
	draw_image(fdf);
}

void	move(int key, t_fdf *fdf)
{
	if (key == ARROW_LEFT)
		(*fdf).shift_x -= 10;
	else if (key == ARROW_RIGHT)
		(*fdf).shift_x += 10;
	else if (key == ARROW_UP)
		(*fdf).shift_y -= 10;
	else
		(*fdf).shift_y += 10;
	draw_image(fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_2 || key == MAIN_PAD_2)
		fdf->angle_x -= 1;
	else if (key == NUM_PAD_8 || key == MAIN_PAD_8)
		fdf->angle_x += 1;
	else if (key == NUM_PAD_4 || key == MAIN_PAD_4)
		fdf->angle_y -= 1;
	else if (key == NUM_PAD_6 || key == MAIN_PAD_6)
		fdf->angle_y += 1;
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1
		|| key == NUM_PAD_3 || key == MAIN_PAD_3)
		fdf->angle_z += 1;
	else if (key == NUM_PAD_7 || key == MAIN_PAD_7
		|| key == NUM_PAD_9 || key == MAIN_PAD_9)
		fdf->angle_z -= 1;
	draw_image(fdf);
}

void	changez(int key, t_fdf *fdf)
{
	int		c;
	int		r;
	int		i;

	c = 0;
	i = (key == MAIN_PAD_LESS) ? -1 : 1;
	while (c < fdf->cols)
	{
		r = 0;
		while (r < fdf->rows)
		{
			fdf->incidence_matrix[r][c] ? fdf->z[r][c] =
					fdf->z[r][c] + i : 1;
			r++;
		}
		c++;
	}
	draw_image(fdf);
}
