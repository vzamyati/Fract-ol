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

void		put_image(t_win *window, int x, int y, int color)
{
	if (!(x > 0 && y > 0 && x < W_WIDTH &&  y < W_HEIGHT))
		return ;
	*(int *)(window->data +
			(x + y * W_WIDTH) * window->bpp / 8) = color;
}

void		iterating_drawing(t_win *mandel)
{
	double	tmp;

	tmp = mandel->z.re;
	while (mandel->loopgo < MAX_ITER && ((double)
		(mandel->z.re * mandel->z.re + mandel->z.im * mandel->z.im < 4 
			&& mandel->f_mode == 0) || ((double)(mandel->z.re * 
				(mandel->z.im + mandel->z.im) * (mandel->z.im * mandel->z.im)
			 * mandel->z.re < 4 && mandel->f_mode == 1)) || ((double)
			(mandel->z.re * mandel->z.re * mandel->z.im * mandel->z.im < 4) 
			&& mandel->f_mode == 2)))
	{
		tmp = mandel->z.re;
		mandel->z.re = (mandel->z.re * mandel->z.re) - (mandel->z.im * mandel->z.im) + mandel->real.re;
		mandel->z.im = (2 * mandel->z.im) * tmp + mandel->real.im;
		mandel->loopgo++;
	}
	if (mandel->loopgo == MAX_ITER)
		put_image(mandel, mandel->x_ptr, mandel->y_ptr, 0x000000);
	else
		put_image(mandel, mandel->x_ptr, mandel->y_ptr, (mandel->loopgo % 15) * 0xFFFFFFF);
}

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
		mandel->z.re = 0;
		mandel->z.im = 0;
		mandel->loopgo = 0;
		mandel->real.re = (mandel->factor.re * mandel->x_ptr) - fabs(mandel->min.re);
		mandel->real.im = (mandel->factor.im * mandel->y_ptr) - fabs(mandel->min.im);
		iterating_drawing(mandel);
	}
}

t_win 		*init_mandel(t_win *mandel)
{
	mandel->max.re = 2;
	mandel->max.im = 2.2;
	mandel->min.re = -2.2;
	mandel->min.im = -2.2;
	mandel->factor.re = ((mandel->max.re - mandel->min.re) / (double)(W_WIDTH - 1));
	mandel->factor.im = ((mandel->max.im - mandel->min.im) / (double)(W_HEIGHT - 1));
	mandel->x_ptr = 0;
	mandel->y_ptr = -1;
	mandel->f_mode = 2;
	return (mandel);
}

//(zx * zx * zy * zy <= 4 && loopgo < MAX_ITER) - FLOWER 
//(zx * zx + zy * zy <= 4 && loopgo < MAX_ITER) - NORMAL MODE
//(zy * (zy + zy * zx) + (zy + zy * zx) * zx) < 4 && loopgo < MAX_ITER) - FLOWER MODE 2


