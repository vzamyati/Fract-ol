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

int			f_exit(t_win *window)
{
	if (window != NULL)
		mlx_destroy_window(window->mlx, window->win);
	exit (1);
	return (0);
}

void		f_move(t_win *window, int key)
{
	float	factor;

	window->minX = -2.1;
	window->maxX = 0.6;
	window->minY = -1.35;
	window->maxY = 1.35;
	factor = window->maxX - window->minX;
	factor /= 35;
	if (key == 123)
	{
		window->maxX += factor;
		window->minX += factor;
	}
	else if (key == 124)
	{
		window->maxX -= factor;
		window->minX -= factor;
	}
	var_back(window);
	redraw_image(window, window->fractal);
}

int			key_events(int key, t_win *window)
{
	if (key == 53 || key == 12)
		f_exit(window);
	else if (key == 123 || key == 124)
		f_move(window, key);
	return (0);
}