/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 00:01:50 by jquincy           #+#    #+#             */
/*   Updated: 2019/12/04 20:41:28 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			mpress(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, &fdf);
	else if (button == MOUSE_LEFT_BUTTON)
		fdf->mouse->is_pressed = true;
	return (0);
}

int			mrelease(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->mouse->is_pressed = false;
	return (0);
}

//int			mmove(int x, int y, void *param)
//{
//	t_fdf	*fdf;
//
//	fdf = (t_fdf *)param;
//	fdf->mouse->pr_x = fdf->mouse->x;
//	fdf->mouse->pr_y = fdf->mouse->y;
//	fdf->mouse->x = x;
//	fdf->mouse->y = y;
//	if (fdf->mouse->is_pressed)
//	{
//		fdf->camera->bt += (x - fdf->mouse->pr_x) * 0.002;
//		fdf->camera->al += (y - fdf->mouse->pr_y) * 0.002;
//		draw(fdf->map, fdf);
//	}
//	return (0);
//}