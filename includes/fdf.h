#ifndef FDF_FDF_H
# define FDF_FDF_H
# define IMG_WIDTH 100
# define IMG_HEIGHT 400
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 940

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "keysmac.h"
# include "quaterni.h"
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

typedef struct			s_fdf
{
	size_t 				cols;
	size_t 				rows;
	int 				**z;
	size_t				space;
	int 				color;
	int 				shift_y;
	int 				shift_x;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	t_camera			*camera;
	t_mouse				*mouse;

}						t_fdf;

int						read_map(char *argv, t_fdf **coords);
int						set_coords(t_map *map, t_fdf **coords, int rows);
int 					check_filename(char *argv);
int 					check_input(char *line, size_t *rows);
int 					check_symb(char *line);
void					bresenham(t_qtrn **start, t_qtrn **end, t_fdf *fdf);
void					draw(t_fdf **fdf);
void					draw_image(t_fdf **fdf);
int						draw_qtrn(t_fdf *fdf);
int						read_map(char *argv, t_fdf **coords);
int						set_coords(t_map *map, t_fdf **coords, int rows);
int 					check_filename(char *argv);
int 					check_input(char *line, size_t *rows);
int 					check_symb(char *line);
int						ftclose(void *param);
int						mpress(int button, int x, int y, void *param);
int						mrelease(int button, int x, int y, void *param);
int						mmove(int x, int y, void *param);
int						kpress(int key, t_fdf **fdf);
void					draw(t_fdf **fdf);
void					setcntrls(t_fdf **fdf);
void					zoom(int key, t_fdf **fdf);
void					move(int key, t_fdf **fdf);
void					changez(int key, t_fdf *fdf);
void					rotate(int key, t_fdf *fdf);
void					print_menu(t_fdf **fdf);
void					change_projection(int key, t_fdf *fdf);
t_point					project(t_point p, t_fdf *fdf);
static void				rot_z(int *y, int *x, double gm);
static void				rot_y(int *x, int *z, double bt);
static void				rot_x(int *y, int *z, double al);
t_qtrn 					*quaterni(int angle, float x, float y, int z);

#endif