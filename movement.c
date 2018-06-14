/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:15:31 by vzamyati          #+#    #+#             */
/*   Updated: 2018/06/01 20:15:33 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_move(int x, int y, t_win *window)
{
	static t_complex new;

	if (window->lock == 0 && window->fractal == 2)
	{
		window->first = 1;
		new.re = (x - W_WIDTH / 2) * (1.0 / (W_WIDTH / 2.0));
		new.im = (y - W_HEIGHT / 2) * (1.0 / (W_HEIGHT / 2.0));
		window->c.re = new.re;
		window->c.im = new.im;
		mlx_destroy_image(window->mlx, window->img);
		expose(window);
	}
	else if (window->lock == 1 && window->fractal == 2)
	{
		window->c.re = new.re;
		window->c.im = new.im;
		mlx_destroy_image(window->mlx, window->img);
		expose(window);
	}
	return (0);
}

void		f_move2(t_win *window, int x, int y)
{
	t_complex c;
	t_complex d;

	c = var_recount(window, W_WIDTH / 2, W_HEIGHT / 2);
	d = var_recount(window, x, y);
	d.im = c.im - d.im;
	d.re = c.re - d.re;
	window->min.re -= d.re;
	window->max.re -= d.re;
	window->min.im -= d.im;
	window->max.im -= d.im;
	var_back(window);
}

void		f_move(t_win *window, int x, int y)
{
	f_move2(window, W_WIDTH / 2 + x, W_HEIGHT / 2 + y);
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
