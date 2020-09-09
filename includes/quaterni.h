/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaterni.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 16:35:55 by jquincy           #+#    #+#             */
/*   Updated: 2019/12/30 17:52:06 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_QUATERNI_H
# define FDF_QUATERNI_H

typedef struct	s_quaternion
{
	double	cos_a;
	double	sin_a;
	double	x;
	double	y;
	double	z;
}				t_qtrn;

#endif
