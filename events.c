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
		mlx_destroy_window(window->mlx, window->win);
	exit (1);
	return (0);
}

int			key_events(int key, t_win *window)
{
	if (key == 53 || key == 12)
		f_exit(window);
	else if (key == 124)
		f_move(window, 50, 0);
	else if (key == 123)
		f_move(window, -50, 0);
	else if (key == 126)
		f_move(window, 0, -50);
	else if (key == 125)
		f_move(window, 0, 50);
	else if (key == 69)
		f_zoom(window, 1.25, W_WIDTH / 2, W_HEIGHT / 2);
	else if (key == 78)
		f_zoom(window, 0.75, W_WIDTH / 2, W_HEIGHT / 2);
	mandelbrot(window);
	redraw_image(window);
	return (0);
}