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
	if (window->fractal == 2)
	{
		window->c.re = x * ((window->max.re - window->min.re) / W_HEIGHT) + window->min.re;
		window->c.im = y * ((window->max.im - window->min.im) / W_HEIGHT) + window->min.im;
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

void	f_move(t_win *window, int x, int y)
{
	f_move2(window, W_WIDTH / 2 + x, W_HEIGHT / 2 + y);
}