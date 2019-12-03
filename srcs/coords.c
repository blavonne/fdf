#include "fdf.h"

static int	create_coords(t_fdf **coords)
{
	if (!(*coords = (t_fdf *)malloc(sizeof(t_fdf))))
		return (0);
	(*coords)->z = NULL;
	return (1);
}

static int	get_rows(t_map *map)
{
	t_map	*tmp;
	size_t	i;

	i = 0;
	tmp = map;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static int	**create_z(size_t cols, size_t rows)
{
	int 	**z;
	size_t	i;

	i = 0;
	if (!(z = (int **)malloc(sizeof(int *) * rows)))
		return (0);
	//+1 нужно, чтобы не выйти в сегу в брезенхейме
	while (i < rows)
	{
		if (!(z[i] = (int *)malloc(sizeof(int) * cols)))
			return (0);
		i++;
	}
	return (z);
}

static void	strtoi(t_fdf **coords, t_map *map)
{
	size_t	r;
	size_t	c;
	t_map	*tmp;

	tmp = map;
	r = 0;
	while (r < (*coords)->rows)
	{
		c = 0;
		while (c < (*coords)->cols)
		{
			(*coords)->z[r][c] = ft_atoi(tmp->line[c]);
			c++;
		}
		tmp = tmp->next;
		r++;
	}
}

int 	set_coords(t_map *map, t_fdf **coords, int cols)
{
	t_fdf	*tmp;

	if (!create_coords(coords))
		return (0);
	tmp = *coords;
	tmp->cols = cols;
	tmp->rows = get_rows(map);
	tmp->start_r = 50;
	tmp->start_c = 150;
	tmp->space = 20;
	if (!tmp->cols || !tmp->rows)
		return (0);
	if (!(tmp->z = create_z(tmp->cols, tmp->rows)))
		return (0);
	strtoi(coords, map);
	return (1);
}
