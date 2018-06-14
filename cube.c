/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:30:01 by vzamyati          #+#    #+#             */
/*   Updated: 2018/06/14 16:30:04 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		iterating_drawing_cube(t_win *cube)
{
	double	tmp_re;
	double	tmp_im;

	cube->z.re = 0;
	cube->z.im = 0;
	while (cube->loopgo < MAX_ITER && ((cube->f_mode == 0) ? ((double)
		(cube->z.re * cube->z.re + cube->z.im * cube->z.im < 4)) :
		((double)(cube->z.re * cube->z.re * cube->z.im * cube->z.im < 4))))
	{
		tmp_re = cube->c.re;
		tmp_im = cube->c.im;
		cube->z.re = tan(cube->c.re);
		cube->z.im = tan(cube->c.im);
		cube->c.re = cube->z.re + tmp_re;
		cube->c.im = cube->z.im + tmp_im;
		cube->loopgo++;
	}
	if (cube->loopgo < cube->iter && cube->loopgo > 0)
	{
		cube->color = choose_palette(cube->loopgo % 16, cube);
		put_image(cube, cube->x_ptr, cube->y_ptr, cube->color);
	}
}

void		cube(t_win *cube)
{
	while (cube->x_ptr < W_WIDTH)
	{
		cube->y_ptr++;
		if (cube->y_ptr > W_WIDTH)
		{
			cube->x_ptr++;
			cube->y_ptr = 0;
		}
		cube->loopgo = 0;
		cube->c.re = (cube->min.re + cube->x_ptr * cube->factor.im);
		cube->c.im = (cube->max.im - cube->y_ptr * cube->factor.re);
		iterating_drawing_cube(cube);
	}
}

t_win		*init_cube(t_win *cube)
{
	if (cube->first != 1)
	{
		cube->max.re = 3.0;
		cube->min.re = -2.0;
		cube->min.im = -2.0;
		cube->max.im = 3.0;
	}
	cube->x_ptr = 0;
	cube->y_ptr = -1;
	get_factor(cube);
	return (cube);
}
