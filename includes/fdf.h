/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 16:16:05 by jquincy           #+#    #+#             */
/*   Updated: 2019/12/30 17:46:17 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# define WIN_W 1280
# define WIN_H 940
# define MENU_W 256

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "keysmac.h"
# include "quaterni.h"
# include "color.h"

typedef struct			s_map
{
	char				**line;
	struct s_map		*next;
}						t_map;

typedef struct			s_image
{
	int					endian;
	int					size_line;
	int					bps;
	int					*image;
	void				*img_ptr;
}						t_image;

typedef struct			s_fdf
{
	int					cols;
	int					rows;
	int					**z;
	int					**incidence_matrix;
	int					space;
	int					shift_y;
	int					shift_x;
	int					max_z;
	int					angle_x;
	int					angle_y;
	int					angle_z;
	void				*mlx_ptr;
	void				*win_ptr;
	t_image				image;
}						t_fdf;

int						read_and_init(char *argv, t_fdf *fdf);
int						init_fdf(t_map *map, t_fdf *fdf, int cols);
int						check_filename(char *argv);
int						check_input(char *line, int *rows);
int						check_symb(const char *line);
void					bresenham(t_qtrn start, t_qtrn end, t_fdf *fdf, t_qtrn
						z);
int						draw_image(t_fdf *fdf);
void					zoom(int key, t_fdf *fdf);
void					move(int key, t_fdf *fdf);
void					changez(int key, t_fdf *fdf);
void					rotate(int key, t_fdf *fdf);
void					print_menu(t_fdf *fdf);
t_qtrn					quaterni(t_fdf *fdf, int r, int c);
t_qtrn					create_vector(int x, int y, int z);
void					clean_int_matrix(int **z, int rows);
#endif
