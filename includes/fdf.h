#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> //DELETE THIS

typedef struct		s_map
{
	char			**line;
	struct s_map	*next;
}					t_map;

typedef struct		s_point
{
	float	c;
	float	r;
}					t_point;

typedef struct		s_fdf
{
	size_t 	cols;
	size_t 	rows;
	int 	**z;
	size_t	space;
	int 	color;

	float start_r;
	float start_c;
	void	*mlx_ptr;
	void	*win_ptr;
}					t_fdf;



int					read_map(char *argv, t_fdf **coords);
int					set_coords(t_map *map, t_fdf **coords, int rows);
int 				check_filename(char *argv);
int 				check_input(char *line, size_t *rows);
int 				check_symb(char *line);
void				bresenham(t_point *start, t_point *end, t_fdf *fdf);
void				draw(t_fdf **fdf);
void				draw_image(t_fdf *fdf);
#endif