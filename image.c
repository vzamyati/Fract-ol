/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:11:54 by vzamyati          #+#    #+#             */
/*   Updated: 2018/06/06 13:11:55 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_image(t_win *window, int x, int y, int color)
{
	if (!(x > 0 && y > 0 && x < W_WIDTH && y < W_HEIGHT))
		return ;
	*(int *)(window->data + (x + y * W_WIDTH) * window->bpp / 8) = color;
}

void		iterating_drawing(t_win *win)
{
	double	tmp;

	tmp = win->z.re;
	while (win->loopgo < win->iter && ((win->f_mode == 0) ? ((double)
		(win->z.re * win->z.re + win->z.im * win->z.im < 4))
		: ((double)(win->z.re * win->z.re * win->z.im * win->z.im < 4))))
	{
		tmp = win->z.re;
		win->z.re = (win->z.re * win->z.re) - (win->z.im * win->z.im)
		+ win->c.re;
		win->z.im = (2 * win->z.im * tmp) + win->c.im;
		win->loopgo++;
	}
	if (win->loopgo < win->iter && win->loopgo > 0)
	{
		win->color = choose_palette(win->loopgo % 16, win);
		put_image(win, win->x_ptr, win->y_ptr, win->color);
	}
}

void		redraw_image(t_win *window)
{
	ft_bzero(window->data, W_HEIGHT * W_WIDTH * 4);
	if (window->fractal == 1)
		mandelbrot(window);
	else if (window->fractal == 2)
		expose(window);
	else if (window->fractal == 3)
		bship(window);
	else if (window->fractal == 4)
		cube(window);
	else if (window->fractal == 5)
		brain(window);
	else if (window->fractal == 6)
		hiro(window);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	info(window);
}

void		reset_fractal(t_win *window)
{
	ft_bzero(window->data, W_HEIGHT * W_WIDTH * 4);
	window->first = 0;
	if (window->fractal == 1)
		window = init_mandel(window);
	else if (window->fractal == 2)
		window = init_julia(window);
	else if (window->fractal == 3)
		window = init_bship(window);
	else if (window->fractal == 4)
		window = init_cube(window);
	else if (window->fractal == 5)
		window = init_brain(window);
	else if (window->fractal == 6)
		window = init_hiro(window);
	mlx_clear_window(window->mlx, window->win);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
}
