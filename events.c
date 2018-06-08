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

void		reset_fractal(t_win *window)
{
	if (window->fractal == 1)
		window = init_mandel(window);
	else if (window->fractal == 2)
		window = init_julia(window);
	else if (window->fractal == 3)
		window = init_bship(window);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
}

void		change_fract(int key, t_win *window)
{
	if (key == 18)
		window->fractal = 1;
	else if (key == 19)
		window->fractal = 2;
	else if (key == 20)
		window->fractal = 3;
	reset_fractal(window);
	redraw_image(window);
}

void		change_iters(int key, t_win *window)
{
	if (key == 43)
		window->iter -= 5;
	else if (key == 47)
		window->iter += 5;
}

int			f_exit(t_win *window)
{
	if (window != NULL)
	{
		mlx_destroy_window(window->mlx, window->win);
		free(window);
	}
	exit (0);
	return (0);
}

int			key_events(int key, t_win *window)
{
	(key == 53 || key == 12) ? f_exit(window) : 0;
	(key == 124) ? f_move(window, 50, 0) : 0;
	(key == 123) ? f_move(window, -50, 0) : 0;
	(key == 125) ? 	f_move(window, 0, -50) : 0;
	(key == 126) ? 	f_move(window, 0, 50) : 0;
	(key == 69) ? f_zoom(window, 1.13, W_WIDTH / 2, W_HEIGHT / 2) : 0;
	(key == 78) ? f_zoom(window, 0.87, W_WIDTH / 2, W_HEIGHT / 2) : 0;
	(key == 15) ? reset_fractal(window) : 0;
	(key == 37) ? lock_julia(window) : 0;
	(key == 18 || key == 19 || key == 20) ? change_fract(key, window) : 0;
	(key == 43 || key == 47) ? change_iters(key, window) : 0;
	redraw_image(window);
	return (0);
}