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

void		mandelbrot(void)
{
	t_win	*mandel;

	mandel = init_win("Mandelbrot by vz");
	double	maxre;
	double	maxim;
	double	minre;
	double	minim;

	maxre = 1;
	minre = -2;
	minim = -1.2;
	maxim = minim + (maxre - minre) * W_HEIGHT/W_WIDTH;
	double zx = 0;
	double zy = 0;
	double cx = 0; //complex real
	double cy = 0; // complex im
	double factor_re = ((maxre - minre) / (double)(W_WIDTH - 1));
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
			while (zx * zx * zy * zy <= 4 && loopgo < MAX_ITER)
			{
				loopgo++;
				tempzx = zx;
				zx = (zx * zx) - (zy * zy) + cx;
				zy = (2 * tempzx * zy) + cy;
			}
			if (loopgo == MAX_ITER)
				put_image(mandel, x, y, 0x000000);// mlx_pixel_put(mandel->mlx, mandel->win, x, y, 0xFFFFFF);
			else
				put_image(mandel, x, y, loopgo * 0xFFFFFF);// mlx_pixel_put(mandel->mlx, mandel->win, x, y, loopgo * 0xFF0000);
		}
	}
	mlx_put_image_to_window(mandel->mlx, mandel->win, mandel->img, 0, 0);
	mlx_loop(mandel->mlx);
}

// 	}
// 	// init_fract(mandel);
// 	mandel->img = mlx_new_image(mandel->mlx, W_WIDTH, W_HEIGHT);
// 	// mandel->data = mlx_get_data_addr(mandel->img, &mandel->bpp,
// 	// 				&mandel->size_line, &mandel->endian);
// 	// mlx_put_image_to_window(mandel->mlx, mandel->win, mandel->img, 0, 0);
// 	mlx_loop(mandel->mlx);
// }

// void	*mandelbrot(void	*data)
// {
// 	t_f	*fractal;

// 	fractal = (t_f *)data;
// 	while(fractal->y_start < fractal->y_end)
// 	{
// 		fractal->x = 0;
// 		while (fractal->x < W_WIDTH)
// 		{
// 			fractal->oldRe = (fractal->x - W_WIDTH / 2) * fractal->zoom + fractal->moveX;
// 			fractal->oldIm = (fractal->y_start - W_HEIGHT / 2) * fractal->zoom + fractal->moveY;
// 			fractal->tmpRe = fractal->oldRe;
// 			fractal->tmpIm = fractal->oldIm;
// 			fractal->loopgo = 0;
// 			while (fractal->loopgo < fractal->iter && (fractal->oldRe * fractal->oldRe + fractal->oldIm * fractal->oldIm) < 4)
// 			{
// 				fractal->newRe = fractal->oldRe * fractal->oldRe - fractal->oldIm * fractal->oldIm;
// 				fractal->newIm = 2 * fractal->oldRe * fractal->oldIm;
// 				fractal->oldRe = fractal->newRe + fractal->tmpRe;
// 				fractal->oldIm = fractal->newIm + fractal->tmpIm;
// 				fractal->loopgo++;
// 			}
// 			fractal->z = fractal->oldRe * fractal->oldRe + fractal->oldIm * fractal->oldIm;
// 			if (fractal->loopgo < fractal->iter)
// 				drawing(fractal, fractal->window);
// 			fractal->x++;
// 		}
// 		fractal->y_start++;
// 	}
// 	pthread_exit(0);
// }

// void	pthread_for_mand(t_win *window)
//  {
//  	pthread_t 	thread[16];
//  	t_f			fractal[16];
//  	int 		i;

//  	i = 0;
//  	while (i < 16)
//  	{
//  		fractal[i].y_end = 50 * (i + 1);
// 		fractal[i].y_start = fractal[i].y_end - 50;
// 		fractal[i].zoom = window->zoom;
// 		fractal[i].moveX = window->moveX;
// 		fractal[i].moveY = window->moveY;
// 		fractal[i].iter = window->iter;
// 		fractal[i].palette = window->palette;
// 		fractal[i].window = window;
// 		pthread_create(&(thread[i]), NULL, mandelbrot, (void *)&(fractal[i]));
// 		i++;
//  	}
//  	i = 0;
//  	while (i < 16)
//  	{
//  		pthread_join(thread[i], NULL);
//  		i++;
//  	}
//  }