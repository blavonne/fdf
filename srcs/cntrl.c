/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cntrl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:45:38 by jquincy           #+#    #+#             */
/*   Updated: 2019/12/28 23:32:21 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	printf("Zoom\n");
	if (key == MAIN_PAD_PLUS ||
		key == NUM_PAD_PLUS ||
		key == MOUSE_SCROLL_UP)
		(*fdf).space++;
	else if (key == MAIN_PAD_MINUS ||
			 key == NUM_PAD_MINUS ||
			 key == MOUSE_SCROLL_DOWN)
		(*fdf).space--;
	if ((*fdf).space < 1)
		(*fdf).space = 1;
	draw_image(fdf);
}

void	move(int key, t_fdf *fdf)
{
	printf("Move\n");
	if (key == ARROW_LEFT)
		(*fdf).shift_x -= 10;
	else if (key == ARROW_RIGHT)
		(*fdf).shift_x += 10;
	else if (key == ARROW_UP)
		(*fdf).shift_y -= 10;
	else
		(*fdf).shift_y += 10;
//	draw_qtrn(fdf);
	draw_image(fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	printf("Rotate\n");
	if (key == NUM_PAD_2 || key == MAIN_PAD_2)
		fdf->angle_x -= 1;
	else if (key == NUM_PAD_8 || key == MAIN_PAD_8)
		fdf->angle_x += 1;
	else if (key == NUM_PAD_4 || key == MAIN_PAD_4)
		fdf->angle_y -= 1;
	else if (key == NUM_PAD_6 || key == MAIN_PAD_6)
		fdf->angle_y += 1;
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1
		|| key == NUM_PAD_3 || key == MAIN_PAD_3)
		fdf->angle_z += 1;
	else if (key == NUM_PAD_7 || key == MAIN_PAD_7
		|| key == NUM_PAD_9 || key == MAIN_PAD_9)
		fdf->angle_z -= 1;
//	draw_qtrn(fdf);
	draw_image(fdf);
}

void	changez(int key, t_fdf *fdf)
{
    int             c;
    int             r;

    printf("ChangeZ\n");
    c = 0;
	if (key == MAIN_PAD_LESS)
    {
	    while (c < fdf->cols)
        {
	        r = 0;
	        while (r < fdf->rows)
            {
	            fdf->incidence_matrix[r][c] ? fdf->z[r][c]-- : 1;
	            r++;
            }
	        c++;
        }
    }
	else if (key == MAIN_PAD_MORE)
    {
        while (c < fdf->cols)
        {
            r = 0;
            while (r < fdf->rows)
            {
                fdf->incidence_matrix[r][c] ? fdf->z[r][c]++ : 1;
                r++;
            }
            c++;
        }
    }
    draw_image(fdf);
}

//void	change_projection(int key, t_fdf *fdf)
//{
//	fdf->camera->al = 0;
//	fdf->camera->bt = 0;
//	fdf->camera->gm = 0;
//	if (key == MAIN_PAD_I)
//		fdf->camera->projection = ISO;
//	else if (key == MAIN_PAD_P)
//		fdf->camera->projection = PARALLEL;
//	draw(fdf->map, fdf);
//}
