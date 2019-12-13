/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caminit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:17:12 by jquincy           #+#    #+#             */
/*   Updated: 2019/12/09 17:23:16 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//
//t_camera	*camera_init(t_fdf *fdf)
//{
//	t_camera	*camera;
//
//	if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
//		return (NULL);
//	camera->zoom = FT_MIN((IMG_WIDTH - WINDOW_WIDTH) / fdf->map->width / 2,
//												IMG_HEIGHT / fdf->map->height / 2);
//	camera->al = 0;
//	camera->bt = 0;
//	camera->gm = 0;
//	camera->z_div = 1;
//	camera->x_offs = 0;
//	camera->y_offs = 0;
//	return (camera);
//}

//void	set_zoom(int key, t_fdf **fdf)
//{
//	if (key == MAIN_PAD_PLUS ||
//		key == NUM_PAD_PLUS ||
//		key == MOUSE_SCROLL_UP)
//		(*fdf)->space++;
//	else if (key == MAIN_PAD_MINUS ||
//			 key == NUM_PAD_MINUS ||
//			 key == MOUSE_SCROLL_DOWN)
//		(*fdf)->space--;
//	if ((*fdf)->space < 1)
//		(*fdf)->space = 1;
//}
