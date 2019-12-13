#include "fdf.h"

static void	clean_map(t_map **map)
{
	t_map	*tmp;
	t_map	*next;
	size_t	i;

	tmp = *map;
	i = 0;
	while (tmp)
	{
		next = tmp->next;
		while (tmp->line && tmp->line[i])
		{
			free(tmp->line[i]);
			i++;
		}
		free(tmp->line);
		free(tmp);
		tmp = next;
	}
}

static int	push_in_map(t_map **map, char *line)
{
	t_map	*tmp;

	tmp = *map;
	if (!tmp->line)
	{
		if (!(tmp->line = ft_strsplit(line, ' ')))
			return (0);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_map *)malloc(sizeof(t_map))))
			return (0);
		tmp = tmp->next;
		tmp->next = NULL;
		if (!(tmp->line = ft_strsplit(line, ' ')))
			return (0);
	}
	return (1);
}

static void	display_input(t_fdf **coords) //DELETE
{
	size_t	r;
	size_t	c;

	r = 0;
	printf("ROWS: %i COLS: %i\n", (int)(*coords)->rows, (int)(*coords)->cols);
	while (r < (*coords)->rows)
	{
		c = 0;
		while (c < (*coords)->cols)
		{
			printf("%3i", (*coords)->z[r][c]);
			c++;
		}
		printf("\n");
		r++;
	}
}

//static void	display_input2(t_map *map) //DELETE
//{
//	t_map *tmp;
//	size_t i;
//
//	tmp = map;
//	while(tmp)
//	{
//		i = 0;
//		while (tmp->line[i])
//		{
//			printf("%3s", tmp->line[i]);
//			i++;
//		}
//		printf("\n");
//		tmp = tmp->next;
//	}
//}

static int 	create_map(t_map **map)
{
	if (!(*map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	(*map)->next = NULL;
	(*map)->line = NULL;
	return (1);
}

int			read_map(char *argv, t_fdf **coords)
{
	char	*line;
	t_map	*map;
	int 	fd;
	size_t 	cols;

	cols = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0 || !check_filename(argv) || !create_map(&map))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		if (!check_input(line, &cols) || !push_in_map(&map,
				line))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	free(line);
	close(fd);
	fd = set_coords(map, coords, cols);
//	display_input2(map); //DELETE
	fd ? display_input(coords) : 1; //DELETE
	clean_map(&map);
	return (fd);
}
