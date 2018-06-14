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

int			f_exit(t_win *window)
{
	if (window != NULL)
	{
		mlx_destroy_window(window->mlx, window->win);
		free(window);
	}
	exit(0);
	return (0);
}

int			key_events(int key, t_win *window)
{
	if (key == ESC || key == Q)
		f_exit(window);
	else if (key == AR_RIGHT || key == AR_LEFT)
		(key == AR_RIGHT) ? f_move(window, 50, 0) : f_move(window, -50, 0);
	else if (key == AR_UP || key == AR_DOWN)
		(key == AR_UP) ? f_move(window, 0, -50) : f_move(window, 0, 50);
	if (key == R)
		reset_fractal(window);
	else if (window->fractal == 2 && key == L)
		lock_julia(window);
	else if (key == NUM_1 || key == NUM_2 || key == NUM_3
		|| key == NUM_4 || key == NUM_5 || key == NUM_6)
		change_fract(key, window);
	else if (key == ENTER)
		change_palette(window);
	else if (key == F)
		flower_mode(window);
	else if (key == LESS || key == MORE)
		change_iter(key, window);
	else
		return (0);
	redraw_image(window);
	return (0);
}
