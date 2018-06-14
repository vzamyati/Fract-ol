/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:37:05 by vzamyati          #+#    #+#             */
/*   Updated: 2018/05/07 12:37:25 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot(t_win *mandel)
{
	while (mandel->x_ptr < W_WIDTH)
	{
		mandel->y_ptr++;
		if (mandel->y_ptr > W_WIDTH)
		{
			mandel->x_ptr++;
			mandel->y_ptr = 0;
		}
		mandel->c.re = mandel->min.re + mandel->x_ptr * mandel->factor.re;
		mandel->c.im = mandel->max.im - mandel->y_ptr * mandel->factor.im;
		mandel->z.re = 0;
		mandel->z.im = 0;
		mandel->loopgo = 0;
		iterating_drawing(mandel);
	}
}

t_win		*init_mandel(t_win *mandel)
{
	if (mandel->first != 1)
	{
		mandel->max.re = 0.5;
		mandel->min.re = -2.0;
		mandel->min.im = 1.25;
		mandel->max.im = -1.25;
	}
	mandel->x_ptr = 0;
	mandel->y_ptr = -1;
	mandel->zoom = 0.0035;
	get_factor(mandel);
	return (mandel);
}
