/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:06:52 by jquincy           #+#    #+#             */
/*   Updated: 2019/12/09 18:49:55 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	print_menu(t_fdf **fdf)
{
	int		y;
	int 	color1;
	int 	color2;
	int 	delta;

	color1 = 0x00AAAA00;
	color2 = 0x00AA00AA;
	delta = (color1 - color2) / 1900;

	y = 0;
	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 65, y += 20, color1,
			"How to Use");
	color1 += delta;
	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 15, y += 35, color1,
			"Zoom: Scroll or +/-");
	color1 += delta;
	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 15, y += 30, color1,
			"Move: Arrows");
	color1 += delta;
	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 15, y += 30, color1,
			"Flatten: </>");
	color1 += delta;
	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 15, y += 30, color1,
			"Rotate: Press & Move");
	color1 += delta;
	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 15, y += 30, color1,
			"Rotate:");
	color1 += delta;
	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 57, y += 25, color1,
			"X-Axis - 2/8");
	color1 += delta;
	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 57, y += 25, color1,
			"Y-Axis - 4/6");
	color1 += delta;
	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 57, y += 25, color1,
			"Z-Axis - 1 (3)/7(9)");
	color1 += delta;
	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 15, y += 30, color1,
			"Projection");
	color1 += delta;
	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 57, y += 25, color1,
			"ISO: I Key");
	color1 += delta;
	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 57, y += 25, color1,
			"Parallel: P Key");
}
