/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:30:28 by jquincy           #+#    #+#             */
/*   Updated: 2019/12/09 16:59:54 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//static void		rot_x(int *y, int *z, double al)
//{
//	int	pr_y;
//
//	pr_y = *y;
//	*y = pr_y * cos(al) + *z * sin(al);
//	*z = -pr_y * sin(al) + *z * cos(al);
//}
//
//static void		rot_y(int *x, int *z, double bt)
//{
//	int	pr_x;
//
//	pr_x = *x;
//	*x = pr_x * cos(bt) + *z * sin(bt);
//	*z = -pr_x * sin(bt) + *z * cos(bt);
//}
//
//static void		rot_z(int *y, int *x, double gm)
//{
//	int	pr_y;
//	int	pr_x;
//
//	pr_y = *y;
//	pr_x = *x;
//	*y = pr_x * sin(gm) + pr_y * cos(gm);
//	*x = pr_y * cos(gm) - pr_y * sin(gm);
//}

//t_point		project(t_point p, t_fdf *fdf)
//{
//	p.x *= fdf->camera->zoom;
//	p.y *= fdf->camera->zoom;
//	p.z *= fdf->camera->zoom / fdf->camera->z_div;
//	p.x -= (fdf->map->width * fdf->camera->zoom) / 2;
//	p.y -= (fdf->map->height * fdf->camera->zoom) / 2;
//	rot_x(&p.y, &p.z, fdf->camera->al);
//	rot_y(&p.x, &p.z, fdf->camera->bt);
//	rot_z(&p.x, &p.y, fdf->camera->gm);
//}