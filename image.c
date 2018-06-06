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

int 	expose(t_win *window)
{
	fractol(window);
	return (0);
}

void		put_image(t_win *window, int x, int y, int color)
{
	if (!(x > 0 && y > 0 && x < W_WIDTH &&  y < W_HEIGHT))
		return ;
	*(int *)(window->data + (x + y * W_WIDTH) * window->bpp / 8) = color;
}

void		iterating_drawing(t_win *win)
{
	double	tmp;

	tmp = win->z.re;
	while (win->loopgo < MAX_ITER && ((double)
		(win->z.re * win->z.re + win->z.im * win->z.im < 4)))
	{
		tmp = win->z.re;
		win->z.re = (win->z.re * win->z.re) - (win->z.im * win->z.im) + win->c.re;
		win->z.im = (2 * win->z.im * tmp) + win->c.im;
		win->loopgo++;
	}
	if (win->loopgo == MAX_ITER)
		put_image(win, win->x_ptr, win->y_ptr, 0x000000);
	else
		put_image(win, win->x_ptr, win->y_ptr, (win->loopgo % 15) * 0xF0D3D3);
}

void		redraw_image(t_win *window)
{
	if (window->fractal == 1)
		mandelbrot(window);
	else if (window->fractal == 2)
		julia(window);
	else if (window->fractal == 3)
		bship(window);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
}