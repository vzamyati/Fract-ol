/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hirosima.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:26:36 by vzamyati          #+#    #+#             */
/*   Updated: 2018/06/14 17:26:37 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		iterating_drawing_hiro(t_win *hiro)
{
	double	tmp;

	while (hiro->loopgo < MAX_ITER && ((double)
		(hiro->z.re * hiro->z.im * hiro->z.im < 4)))
	{
		tmp = hiro->z.re;
		hiro->z.re = (double)(hiro->z.im * hiro->z.im) -
		(double)(hiro->z.re * hiro->z.re) + hiro->c.re;
		hiro->z.im = (double)(5 * hiro->z.im) * tmp + hiro->c.im;
		hiro->loopgo++;
	}
	if (hiro->loopgo < hiro->iter && hiro->loopgo > 0)
	{
		hiro->color = choose_palette(hiro->loopgo % 16, hiro);
		put_image(hiro, hiro->x_ptr, hiro->y_ptr, hiro->color);
	}
}

void		hiro(t_win *hiro)
{
	while (hiro->x_ptr < W_WIDTH)
	{
		hiro->y_ptr++;
		if (hiro->y_ptr > W_WIDTH)
		{
			hiro->x_ptr++;
			hiro->y_ptr = 0;
		}
		hiro->loopgo = 0;
		hiro->z.re = (hiro->min.re + hiro->x_ptr * hiro->factor.im);
		hiro->z.im = (hiro->max.im - hiro->y_ptr * hiro->factor.re);
		hiro->c.re = -0.276211;
		hiro->c.im = 0;
		iterating_drawing_hiro(hiro);
	}
}

t_win		*init_hiro(t_win *hiro)
{
	if (hiro->first != 1)
	{
		hiro->max.re = 2.0;
		hiro->min.re = -2.0;
		hiro->min.im = -2.0;
		hiro->max.im = 2.0;
	}
	hiro->x_ptr = 0;
	hiro->y_ptr = -1;
	get_factor(hiro);
	return (hiro);
}
