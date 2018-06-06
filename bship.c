/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bship.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:42:14 by vzamyati          #+#    #+#             */
/*   Updated: 2018/06/06 17:42:15 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		iterating_drawing_ship(t_win *bship)
{
	double tmp;

	while (bship->loopgo < MAX_ITER && ((double)
		(bship->z.re * bship->z.re + bship->z.im * bship->z.im < 4)))
	{
		tmp = fabs(bship->z.re * bship->z.re - bship->z.im * bship->z.im + bship->c.re);
		bship->z.im = fabs(bship->z.re * bship->z.im) * 2.0 + bship->c.im;
		bship->z.re = tmp;
		bship->loopgo++;
	}
	if (bship->loopgo == MAX_ITER)
		put_image(bship, bship->x_ptr, bship->y_ptr, 0x000000);
	else
		put_image(bship, bship->x_ptr, bship->y_ptr, (bship->loopgo % 15) * 0xF0D3D3);
}

void		bship(t_win *bship)
{
	while (bship->x_ptr < W_WIDTH)
	{
		bship->y_ptr++;
		if (bship->y_ptr > W_WIDTH)
		{
			bship->x_ptr++;
			bship->y_ptr = 0;
		}
		bship->z.re = 0;
		bship->z.im = 0;
		bship->loopgo = 0;
		bship->c.re = bship->min.re - bship->x_ptr * bship->factor.re;
		bship->c.im = bship->max.im + bship->y_ptr * bship->factor.im;
		iterating_drawing_ship(bship);
	}
}

t_win 		*init_bship(t_win *bship)
{
	bship->max.re = 2.0;
	bship->min.re = -2.2;
	bship->min.im = -2.2;
	bship->max.im = bship->min.im + (bship->max.re - bship->min.re) * W_HEIGHT / W_WIDTH;
	bship->x_ptr = 0;
	bship->y_ptr = -1;
	bship->f_mode = 0;
	get_factor(bship);
	return (bship);
}