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
	ft_bzero(window->data, W_HEIGHT * W_WIDTH * 4);
	if (window->fractal == 1)
		window = init_mandel(window);
	else if (window->fractal == 2)
	{
		window->f_julia = 0;
		window = init_julia(window);
	}
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
	else
		return ;
	reset_fractal(window);
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
	if (key == 53 || key == 12)
		f_exit(window);
	else if (key == 124)
		f_move(window, 50, 0);
	else if (key == 123)
		f_move(window, -50, 0);
	else if (key == 125)
		f_move(window, 0, -50);
	else if (key == 126)
		f_move(window, 0, 50);
	else if (key == 15)
		reset_fractal(window);
	else if (window->fractal == 2 && key == 37)
		lock_julia(window);
	else if (key == 18 || key == 19 || key == 20)
		change_fract(key, window);
	else
		return (0);
	redraw_image(window);
	return (0);
}