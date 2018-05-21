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

void	put_image(t_win *window, int x, int y, int color)
{
	if (!(x > 0 && y > 0 && x < W_WIDTH &&  y < W_HEIGHT))
		return ;
	*(int *)(window->data +
			(x + y * W_WIDTH) * window->bpp / 8) = color;
}

void		mandelbrot(void)
{
	t_win	*mandel;

	mandel = init_win("Mandelbrot by vz");

	mandel->maxRe = 1;
	mandel->minRe = -2;
	mandel->minIm = -1.2;
	mandel->maxIm = mandel->minIm + (mandel->maxRe - mandel->minRe) * W_HEIGHT/W_WIDTH;
	double zx = 0;
	double zy = 0;
	double cx = 0; //complex real
	double cy = 0; // complex im
	double factor_re = ((mandel->maxRe - mandel->minRe) / (double)(W_WIDTH - 1));
	double factor_im = ((maxim - minim) / (double)(W_HEIGHT - 1));
	double tempzx = 0;
	int loopgo = 0;
	int x = -1;
	while (++x < W_WIDTH)
	{
		cx = (factor_re * x) - fabs(minre);
		int y = -1;
		while (++y < W_HEIGHT)
		{
			zx = 0;
			zy = 0;
			cy = (factor_im * y) - fabs(minim);
			loopgo = 0;
			while (zx * zx + zy * zy <= 4 && loopgo < MAX_ITER)
			{
				loopgo++;
				tempzx = zx;
				zx = (zx * zx) - (zy * zy) + cx;
				zy = (2 * tempzx * zy) + cy;
			}
			if (loopgo == MAX_ITER)
				put_image(mandel, x, y, 0x000000);
			else
				put_image(mandel, x, y, (loopgo % 15) * 0xE70E0E);
		}
	}
	mlx_put_image_to_window(mandel->mlx, mandel->win, mandel->img, 0, 0);
	mlx_loop(mandel->mlx);
}


//(zx * (zy + zy) * (zy * zy) * zx < 4 && loopgo < MAX_ITER) - FLOWER MODE 1
//(zx * zx * zy * zy <= 4 && loopgo < MAX_ITER) - FLOWER 
//(zx * zx + zy * zy <= 4 && loopgo < MAX_ITER) - NORMAL MODE
//(zy * (zy + zy * zx) + (zy + zy * zx) * zx) < 4 && loopgo < MAX_ITER) - FLOWER MODE 2


