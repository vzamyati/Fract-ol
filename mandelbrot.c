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
	mandel->tempzRe= mandel->zRe;
	while (mandel->loopgo < MAX_ITER && ((double)
		(mandel->zRe * mandel->zRe + mandel->zIm * mandel->zIm < 4 
			&& mandel->f_mode == 0) || ((double)(mandel->zRe * 
				(mandel->zIm + mandel->zIm) * (mandel->zIm * mandel->zIm)
			 * mandel->zRe < 4 && mandel->f_mode == 1)) || ((double)
			(mandel->zRe * mandel->zRe * mandel->zIm * mandel->zIm < 4) 
			&& mandel->f_mode == 2)))
	{
		mandel->tempzRe = mandel->zRe;
		mandel->zRe = (mandel->zRe * mandel->zRe) - (mandel->zIm * mandel->zIm) + mandel->Re;
		mandel->zIm = (2 * mandel->tempzRe * mandel->zIm) + mandel->Im;
		mandel->loopgo++;
	}
	if (mandel->loopgo == MAX_ITER)
		put_image(mandel, mandel->x_ptr, mandel->y_ptr, 0x000000);
	else
		put_image(mandel, mandel->x_ptr, mandel->y_ptr, (mandel->loopgo % 15) * 0xFFFFFFF);
}

void		mandelbrot(void)
{
	t_win	*mandel;

	mandel = init_win("Mandelbrot by vz");
	mandel = init_mandel(mandel);
	while (mandel->x_ptr < W_WIDTH)
	{
		mandel->y_ptr++;
		if (mandel->y_ptr > W_WIDTH)
		{
			mandel->x_ptr++;
			mandel->y_ptr = 0;
		}
		mandel->zRe = 0;
		mandel->zIm = 0;
		mandel->loopgo = 0;
		mandel->Re = (mandel->factor_Re * mandel->x_ptr) - fabs(mandel->minRe);
		mandel->Im = (mandel->factor_Im * mandel->y_ptr) - fabs(mandel->minIm);
		iterating_drawing(mandel);
	}
	mlx_put_image_to_window(mandel->mlx, mandel->win, mandel->img, 0, 0);
	mlx_key_hook(mandel->win, key_events, mandel);
	mlx_hook(mandel->win, 17, 1L << 17, f_exit, mandel);
	mlx_loop(mandel->mlx);
}

t_win 		*init_mandel(t_win *mandel)
{
	mandel->maxRe = 1;
	mandel->minRe = -2;
	mandel->minIm = -1.2;
	mandel->maxIm = mandel->minIm + (mandel->maxRe - mandel->minRe) * W_HEIGHT/W_WIDTH;
	mandel->factor_Re = ((mandel->maxRe - mandel->minRe) / (double)(W_WIDTH - 1));
	mandel->factor_Im = ((mandel->maxIm - mandel->minIm) / (double)(W_HEIGHT - 1));
	mandel->tempzRe = 0;
	mandel->x_ptr = 0;
	mandel->y_ptr = -1;
	mandel->f_mode = 2;
	return (mandel);
}

//(zx * zx * zy * zy <= 4 && loopgo < MAX_ITER) - FLOWER 
//(zx * zx + zy * zy <= 4 && loopgo < MAX_ITER) - NORMAL MODE
//(zy * (zy + zy * zx) + (zy + zy * zx) * zx) < 4 && loopgo < MAX_ITER) - FLOWER MODE 2


