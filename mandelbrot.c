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
	int x;
	int y;

	mandel = init_win("Mandelbrot by vz");
	mandel = init_mandel(mandel);
	x = -1;
	while (++x < W_WIDTH)
	{
		mandel->Re = (mandel->factor_Re * x) - fabs(mandel->minRe);
		y = -1;
		while (++y < W_HEIGHT)
		{
			mandel->zRe = 0;
			mandel->zIm = 0;
			mandel->Im = (mandel->factor_Im * y) - fabs(mandel->minIm);
			mandel->loopgo = 0;
			while (mandel->zRe * mandel->zRe + mandel->zIm * mandel->zIm <= 4
				&& mandel->loopgo < MAX_ITER)
			{
				mandel->loopgo++;
				mandel->tempzRe = mandel->zRe;
				mandel->zRe = (mandel->zRe * mandel->zRe) - (mandel->zIm * mandel->zIm) + mandel->Re;
				mandel->zIm = (2 * mandel->tempzRe * mandel->zIm) + mandel->Im;
			}
			if (mandel->loopgo == MAX_ITER)
				put_image(mandel, x, y, 0x000000);
			else
				put_image(mandel, x, y, (mandel->loopgo % 15) * 0xE70E0E);
		}
	}
	mlx_put_image_to_window(mandel->mlx, mandel->win, mandel->img, 0, 0);
	mlx_loop(mandel->mlx);
}

t_win 		*init_mandel(t_win *mandel)
{
	mandel->maxRe = 1;
	mandel->minRe = -2;
	mandel->minIm = -1.2;
	mandel->maxIm = mandel->minIm + (mandel->maxRe - mandel->minRe) * W_HEIGHT/W_WIDTH;
	mandel->zRe = 0;
	mandel->zIm = 0;
	mandel->Re = 0;
	mandel->Im = 0;
	mandel->factor_Re = ((mandel->maxRe - mandel->minRe) / (double)(W_WIDTH - 1));
	mandel->factor_Im = ((mandel->maxIm - mandel->minIm) / (double)(W_HEIGHT - 1));
	mandel->tempzRe = 0;
	mandel->loopgo = 0;
	return (mandel);
}
//(zx * (zy + zy) * (zy * zy) * zx < 4 && loopgo < MAX_ITER) - FLOWER MODE 1
//(zx * zx * zy * zy <= 4 && loopgo < MAX_ITER) - FLOWER 
//(zx * zx + zy * zy <= 4 && loopgo < MAX_ITER) - NORMAL MODE
//(zy * (zy + zy * zx) + (zy + zy * zx) * zx) < 4 && loopgo < MAX_ITER) - FLOWER MODE 2


