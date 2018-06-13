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
	if (!(x > 0 && y > 0 && x < W_WIDTH &&  y < W_HEIGHT))
		return ;
	*(int *)(window->data + (x + y * W_WIDTH) * window->bpp / 8) = color;
}

int 		choose_palette(int loopgo, t_win *window)
{
	if (window->palette == 1)
		return (palette1(loopgo));
	else if (window->palette == 2)
		return (palette2(loopgo));
	return (0);
}

void		iterating_drawing(t_win *win)
{
	double	tmp;

	tmp = win->z.re;
	while (win->loopgo < win->iter && ((win->f_mode == 0) ? ((double)
		(win->z.re * win->z.re + win->z.im * win->z.im < 4)) : ((double)(win->z.re * win->z.re * win->z.im * win->z.im < 4))))
	{
		tmp = win->z.re;
		win->z.re = (win->z.re * win->z.re) - (win->z.im * win->z.im) + win->c.re;
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
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	mlx_string_put(window->mlx, window->win, 10, 5, 0xFFFFFF, ft_itoa(window->iter));
}
