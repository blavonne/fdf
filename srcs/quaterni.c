/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaterni.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:12:40 by jquincy           #+#    #+#             */
/*   Updated: 2019/12/30 17:06:56 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_qtrn	create_qtrn(int x, int y, int z, int angle)
{
	t_qtrn	new;
	double	r_angle;

	r_angle = (angle * 0.5) * M_PI / 180;
	new.cos_a = cos(r_angle);
	new.sin_a = sin(r_angle);
	new.x = new.sin_a * x;
	new.y = new.sin_a * y;
	new.z = new.sin_a * z;
	return (new);
}

static t_qtrn	reverse_qtrn(t_qtrn prev)
{
	t_qtrn	new;
	double	modulo;

	modulo = sqrt(pow(prev.x, 2) + pow(prev.y, 2) + pow(prev.z, 2) +
			pow(prev.cos_a, 2));
	new.cos_a = prev.cos_a;
	new.x = (prev.x != 0.0) ? (-prev.x / modulo) : 0;
	new.y = (prev.y != 0.0) ? (-prev.y / modulo) : 0;
	new.z = (prev.z != 0.0) ? (-prev.z / modulo) : 0;
	return (new);
}

t_qtrn			create_vector(int x, int y, int z)
{
	t_qtrn	new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.cos_a = 0;
	new.sin_a = 1;
	return (new);
}

static t_qtrn	qtrn_multiply(t_qtrn qtrn, t_qtrn vector)
{
	t_qtrn	res;

	res.cos_a = qtrn.cos_a * vector.cos_a - qtrn.x * vector.x
		- qtrn.y * vector.y - qtrn.z * vector.z;
	res.x = qtrn.cos_a * vector.x + vector.cos_a * qtrn.x +
		qtrn.y * vector.z - vector.y * qtrn.z;
	res.y = qtrn.cos_a * vector.y + vector.cos_a * qtrn.y +
		qtrn.z * vector.x - vector.z * qtrn.x;
	res.z = qtrn.cos_a * vector.z + vector.cos_a * qtrn.z +
		qtrn.x * vector.y - vector.x * qtrn.y;
	return (res);
}

t_qtrn			quaterni(t_fdf *fdf, int r, int c)
{
	t_qtrn	os;
	t_qtrn	vector;
	t_qtrn	os_rev;
	t_qtrn	res;

	vector = create_vector(c - (int)round(0.5 * fdf->cols),
			r - (int)round(0.5 * fdf->rows), (*fdf).z[abs(r)][abs(c)]);
	os = create_qtrn(1, 0, 0, (*fdf).angle_x);
	os_rev = reverse_qtrn(os);
	res = qtrn_multiply(os, vector);
	res = qtrn_multiply(res, os_rev);
	os = create_qtrn(0, 1, 0, (*fdf).angle_y);
	os_rev = reverse_qtrn(os);
	res = qtrn_multiply(os, res);
	res = qtrn_multiply(res, os_rev);
	os = create_qtrn(0, 0, 1, (*fdf).angle_z);
	os_rev = reverse_qtrn(os);
	res = qtrn_multiply(os, res);
	res = qtrn_multiply(res, os_rev);
	return (res);
}
