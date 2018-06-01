/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:46:19 by vzamyati          #+#    #+#             */
/*   Updated: 2018/05/30 16:46:20 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		var_back(t_win *window)
{
	window->x_ptr = 0;
	window->y_ptr = -1;
}

t_complex		var_recount(t_win *window, int x, int y)
{
	t_complex	v;

	v.re = (double)x * window->factor.re + window->min.re;
	v.im = (double)y * window->factor.im + window->min.im;
	return(v); 
}

int			f_exit(t_win *window)
{
	if (window != NULL)
		mlx_destroy_window(window->mlx, window->win);
	exit (1);
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

void	f_move(t_win *window, int x, int y)
{
	f_move2(window, W_WIDTH / 2 + x, W_HEIGHT / 2 + y);
}

int			key_events(int key, t_win *window)
{
	if (key == 53 || key == 12)
		f_exit(window);
	else if (key == 123)
		f_move(window, 100, 0);
	else if (key == 124)
		f_move(window, -100, 0);
	mandelbrot(window);
	redraw_image(window);
	return (0);
}