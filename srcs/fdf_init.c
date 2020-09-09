/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:15:08 by jquincy           #+#    #+#             */
/*   Updated: 2019/12/30 17:34:04 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_rows(t_map *map)
{
	t_map	*tmp;
	int		i;

	i = 0;
	tmp = map;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
		if (i + 1 < i)
			return (0);
	}
	return (i);
}

static int		**create_matrix(int cols, int rows)
{
	int	**z;
	int	i;

	i = 0;
	if (!(z = (int **)malloc(sizeof(int *) * rows)))
		return (NULL);
	while (i < rows)
	{
		if (!(z[i] = (int *)malloc(sizeof(int) * cols)))
			return (NULL);
		i++;
	}
	return (z);
}

static void		fill_z(t_fdf *fdf, t_map *map)
{
	int		r;
	int		c;
	t_map	*tmp;
	int		max;

	max = 0;
	tmp = map;
	r = 0;
	while (r < (*fdf).rows)
	{
		c = 0;
		while (c < (*fdf).cols)
		{
			(*fdf).z[r][c] = ft_atoi(tmp->line[c]);
			if ((*fdf).z[r][c] > max)
				max = (*fdf).z[r][c];
			fdf->incidence_matrix[r][c] = (fdf->z[r][c] != 0) ? 1 : 0;
			c++;
		}
		tmp = tmp->next;
		r++;
	}
	(*fdf).max_z = max;
}

static void		image_init(t_image *img)
{
	img->bps = BPS;
	img->size_line = WIN_W * (int)sizeof(int);
	img->endian = ENDIAN;
	img->image = NULL;
	img->img_ptr = NULL;
}

int				init_fdf(t_map *map, t_fdf *fdf, int cols)
{
	(*fdf).cols = cols;
	(*fdf).rows = get_rows(map);
	(*fdf).shift_y = (int)round(0.5 * WIN_H);
	(*fdf).shift_x = (int)round(0.5 * (WIN_W + MENU_W));
	(*fdf).space = 40;
	(*fdf).angle_x = 30;
	(*fdf).angle_y = 0;
	(*fdf).angle_z = 0;
	if (!(*fdf).cols || !(*fdf).rows)
		return (0);
	image_init(&(*fdf).image);
	if (!((*fdf).z = create_matrix((*fdf).cols, (*fdf).rows)))
		return (0);
	if (!((*fdf).incidence_matrix = create_matrix((*fdf).cols, (*fdf).rows)))
		return (0);
	fill_z(fdf, map);
	if (!((*fdf).mlx_ptr = mlx_init()))
		return (0);
	if (!((*fdf).win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_W, WIN_H, "I NEED"
					" A DOCTOR")))
		return (0);
	return (1);
}
