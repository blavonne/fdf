#include "fdf.h"

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
		return (NULL);
	while (i < rows)
	{
		if (!(z[i] = (int *)malloc(sizeof(int) * cols)))
			return (NULL);
		i++;
	}
	return (z);
}

static void	fill_z(t_fdf *fdf, t_map *map)
{
	size_t	r;
	size_t	c;
	t_map	*tmp;

	tmp = map;
	r = 0;
	while (r < (*fdf).rows)
	{
		c = 0;
		while (c < (*fdf).cols)
		{
			(*fdf).z[r][c] = ft_atoi(tmp->line[c]);
			c++;
		}
		tmp = tmp->next;
		r++;
	}
}

int			init_fdf(t_map *map, t_fdf *fdf, int cols)
{
	(*fdf).cols = cols;
	(*fdf).rows = get_rows(map);
	(*fdf).shift_y = 250;
	(*fdf).shift_x = 250;
	(*fdf).space = 50;
	(*fdf).color = 0x00AAAA00;
	if (!(*fdf).cols || !(*fdf).rows)
		return (0);
	if (!((*fdf).z = create_z((*fdf).cols, (*fdf).rows)))
		return (0);
	fill_z(fdf, map);
	if (!((*fdf).mlx_ptr = mlx_init()))
		return (0);
	if (!((*fdf).win_ptr = mlx_new_window(fdf->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "I NEED A DOCTOR")))
		return (0);
	return (1);
}
