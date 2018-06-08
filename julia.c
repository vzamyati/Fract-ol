/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:36:09 by vzamyati          #+#    #+#             */
/*   Updated: 2018/06/06 15:36:10 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		lock_julia(t_win *window)
{
	if (window->lock == 0)
		window->lock = 1;
	else if (window->lock == 1)
		window->lock = 0;
}

void		julia(t_win *julia)
{
	while (julia->x_ptr < W_WIDTH)
	{
		julia->y_ptr++;
		if (julia->y_ptr > W_WIDTH)
		{
			julia->x_ptr++;
			julia->y_ptr = 0;
		}
		julia->z.re = julia->min.re + julia->x_ptr * julia->factor.re;
		julia->z.im = julia->max.im - julia->y_ptr * julia->factor.im;
		julia->loopgo = 0;
		iterating_drawing(julia);
	}
}

t_win 		*init_julia(t_win *julia)
{
	julia->max.re = 2.25;
	julia->min.re = -2.25;
	julia->min.im = -2;
	julia->max.im = 2;
	julia->x_ptr = 0;
	julia->y_ptr = -1;
	julia->f_mode = 0;
	julia->lock = 0;
	julia->iter = MAX_ITER;
	get_factor(julia);
	return (julia);
}
