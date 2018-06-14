/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:53:06 by vzamyati          #+#    #+#             */
/*   Updated: 2018/06/14 15:53:07 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		change_palette(t_win *window)
{
	if (window->palette < 5)
		window->palette += 1;
	else if (window->palette == 5)
		window->palette = 1;
	make_changes(window);
}

void		change_fract(int key, t_win *window)
{
	if (key == NUM_1)
		window->fractal = 1;
	else if (key == NUM_2)
		window->fractal = 2;
	else if (key == NUM_3)
		window->fractal = 3;
	else if (key == NUM_4)
		window->fractal = 4;
	else if (key == NUM_5)
		window->fractal = 5;
	else if (key == NUM_6)
		window->fractal = 6;
	else
		return ;
	reset_fractal(window);
}

void		flower_mode(t_win *window)
{
	if (window->f_mode == 0)
		window->f_mode = 1;
	else if (window->f_mode == 1)
		window->f_mode = 0;
	make_changes(window);
}

void		change_iter(int key, t_win *window)
{
	if (window->iter < 150 && key == MORE)
		window->iter += 5;
	else if (window->iter > 5 && key == LESS)
		window->iter -= 5;
	make_changes(window);
}

void		make_changes(t_win *window)
{
	ft_bzero(window->data, W_HEIGHT * W_WIDTH * 4);
	window->first = 1;
	if (window->fractal == 1)
		window = init_mandel(window);
	else if (window->fractal == 2)
		window = init_julia(window);
	else if (window->fractal == 3)
		window = init_bship(window);
	else if (window->fractal == 4)
		window = init_cube(window);
	else if (window->fractal == 5)
		window = init_brain(window);
	else if (window->fractal == 6)
		window = init_hiro(window);
	mlx_clear_window(window->mlx, window->win);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
}
