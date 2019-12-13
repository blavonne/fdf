/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 23:27:54 by jquincy           #+#    #+#             */
/*   Updated: 2019/12/04 20:40:22 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ftclose(void *param)
{
	(void)param;
	exit(0);
}

//void	setcntrls(t_fdf **fdf)
//{
//	mlx_hook(fdf->win_ptr, 2, 0, kpress, fdf);
//	mlx_hook(fdf->win_ptr, 17, 0, ftclose, fdf);
//	mlx_hook(fdf->win_ptr, 4, 0, mpress, fdf);
//	mlx_hook(fdf->win_ptr, 5, 0, mrelease, fdf);
//	mlx_hook(fdf->win_ptr, 6, 0, mmove, fdf);
//}
