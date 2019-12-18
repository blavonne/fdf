/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:06:52 by jquincy           #+#    #+#             */
/*   Updated: 2019/12/16 19:16:54 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	print_menu(t_fdf *fdf)
{
	int		y;
//	delta = (TEXT_COLOR - color2) / 1900; //delete

	y = 0;
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 65, y += 20, TEXT_COLOR,
			"How to Use");
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 15, y += 35, TEXT_COLOR,
			"Zoom: Scroll or +/-");
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 15, y += 30, TEXT_COLOR,
			"Move: Arrows");
//	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 15, y += 30, TEXT_COLOR,
//			"Flatten: </>");
//	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 15, y += 30, TEXT_COLOR,
//			"Rotate: Press & Move");
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 15, y += 30, TEXT_COLOR,
			"Rotate:");
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 57, y += 25, TEXT_COLOR,
			"X-Axis - 2/8");
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 57, y += 25, TEXT_COLOR,
			"Y-Axis - 4/6");
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 57, y += 25, TEXT_COLOR,
			"Z-Axis - 1 (3)/7(9)");
//	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 15, y += 30, TEXT_COLOR,
//			"Projection");
//	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 57, y += 25, TEXT_COLOR,
//			"ISO: I Key");
//	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr, 57, y += 25, TEXT_COLOR,
//			"Parallel: P Key");
}
