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
# include <stdio.h> //DELETE THIS

typedef enum
{
	ISO,
	PARALLEL
}						t_projection;

typedef enum
{
	false,
	true
}						t_bool;

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

typedef struct			s_mouse
{
	char				is_pressed;
	int					x;
	int					y;
	int					pr_x;
	int					pr_y;
}						t_mouse;

typedef struct			s_camera
{
	t_projection		projection;
	int					zoom;
	double				al;
	double				bt;
	double				gm;
	float				z_div;
	int					x_offs;
	int					y_offs;
}						t_camera;

typedef struct			s_image
{
	int					endian;
	int					size_line;
	int					bps;
	int					*image;
	void				*img_ptr;
}						t_image;

typedef struct			s_rotation
{
	char				a;
	int 				angle;
}						t_rotation;

typedef struct			s_fdf
{
	int 				cols; // os OX
	int 				rows; // os OY
	int 				**z; // os OZ[x][y]
	int                 **incidence_matrix;
	int					space; //ZOOM
	int 				shift_y; //shift from 0,0
	int 				shift_x;
	int					max_z;
	int 				color;
	int					angle_x;
	int					angle_y;
	int					angle_z;
	void				*mlx_ptr;
	void				*win_ptr;
	t_rotation			new_angle;
	t_image				image;
	t_camera			*camera;
	t_mouse				*mouse;
}						t_fdf;

int						read_and_init(char *argv, t_fdf *fdf);
int						init_fdf(t_map *map, t_fdf *fdf, int cols);
int 					check_filename(char *argv);
int 					check_input(char *line, int *rows);
int 					check_symb(const char *line);
void					bresenham(t_qtrn start, t_qtrn end, t_fdf *fdf, t_qtrn
						z);
void					draw_background(t_fdf *fdf);
void					draw_qtrn(t_fdf *fdf);
int						draw_image(t_fdf *fdf);
int						ftclose(void *param);
int						mpress(int button, int x, int y, void *param);
int						mrelease(int button, int x, int y, void *param);
int						mmove(int x, int y, void *param);
int						kpress(int key, t_fdf *fdf);
void					setcntrls(t_fdf **fdf);
void					zoom(int key, t_fdf *fdf);
void					move(int key, t_fdf *fdf);
void					changez(int key, t_fdf *fdf);
void					rotate(int key, t_fdf *fdf);
void					print_menu(t_fdf *fdf);
t_qtrn 					quaterni(t_fdf *fdf, int r, int c);
t_qtrn					create_vector(int x, int y, int z);
#endif