/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 00:06:42 by jquincy           #+#    #+#             */
/*   Updated: 2019/12/09 17:02:30 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			kpress(int key, t_fdf **fdf)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS
		|| key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS)
		zoom(key, fdf);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
		|| key == ARROW_UP || key == ARROW_DOWN)
		move(key, fdf);
//	else if (key == NUM_PAD_1 || key == MAIN_PAD_1
//		|| key == NUM_PAD_2 || key == MAIN_PAD_2
//		|| key == NUM_PAD_3 || key == MAIN_PAD_3
//		|| key == NUM_PAD_4 || key == MAIN_PAD_4
//		|| key == NUM_PAD_6 || key == MAIN_PAD_6
//		|| key == NUM_PAD_7 || key == MAIN_PAD_7
//		|| key == NUM_PAD_8 || key == MAIN_PAD_8
//		|| key == NUM_PAD_9 || key == MAIN_PAD_9)
//		rotate(key, fdf);
//	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
//		changez(key, fdf);
//	else if (key == MAIN_PAD_P || key == MAIN_PAD_I)
//		change_projection(key, fdf);
	return (0);
}
