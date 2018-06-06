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
		julia->c.re = 0.4;
		julia->c.im = 0.6;
		julia->z.re = julia->min.re + julia->x_ptr * julia->factor.re;
		julia->z.im = julia->max.im - julia->y_ptr * julia->factor.im;
		julia->loopgo = 0;
		iterating_drawing(julia);
	}
}

t_win 		*init_julia(t_win *julia)
{
	julia->max.re = 2.0;
	julia->min.re = -2.2;
	julia->min.im = -2.2;
	julia->max.im = julia->min.im + (julia->max.re - julia->min.re) * W_HEIGHT / W_WIDTH;
	julia->x_ptr = 0;
	julia->y_ptr = -1;
	julia->f_mode = 0;
	get_factor(julia);
	return (julia);
}
