/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:25:46 by vzamyati          #+#    #+#             */
/*   Updated: 2018/06/14 15:25:47 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		iterating_drawing_brain(t_win *brain)
{
	double	tmp;

	while (brain->loopgo < MAX_ITER && ((double)
		(brain->z.re * brain->z.im * brain->z.im < 4)))
	{
		tmp = brain->z.re;
		brain->z.re = (double)(brain->z.im * brain->z.im) -
		(double)(brain->z.re * brain->z.re) + brain->c.re;
		brain->z.im = (double)(5 * brain->z.im) * tmp + brain->c.im;
		brain->loopgo++;
	}
	if (brain->loopgo < brain->iter && brain->loopgo > 0)
	{
		brain->color = choose_palette(brain->loopgo % 16, brain);
		put_image(brain, brain->x_ptr, brain->y_ptr, brain->color);
	}
}

void		brain(t_win *brain)
{
	while (brain->x_ptr < W_WIDTH)
	{
		brain->y_ptr++;
		if (brain->y_ptr > W_WIDTH)
		{
			brain->x_ptr++;
			brain->y_ptr = 0;
		}
		brain->loopgo = 0;
		brain->c.re = -0.2459368;
		brain->c.im = 0;
		brain->z.re = brain->min.re + brain->x_ptr * brain->factor.re;
		brain->z.im = brain->max.im - brain->y_ptr * brain->factor.im;
		iterating_drawing_brain(brain);
	}
}

t_win		*init_brain(t_win *brain)
{
	if (brain->first != 1)
	{
		brain->max.re = 2.0;
		brain->min.re = -2.0;
		brain->min.im = -2;
		brain->max.im = 2;
	}
	brain->x_ptr = 0;
	brain->y_ptr = -1;
	get_factor(brain);
	return (brain);
}
