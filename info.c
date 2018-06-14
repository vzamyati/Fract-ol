/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:50:53 by vzamyati          #+#    #+#             */
/*   Updated: 2018/06/14 15:50:54 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	info(t_win *window)
{
	char *str;

	str = ft_itoa(window->iter);
	mlx_string_put(window->mlx, window->win, 5, 10, 0xFFFFFF,
		"Arrows = MOVE");
	mlx_string_put(window->mlx, window->win, 5, 30, 0xFFFFFF,
		"Mouse wheel = ZOOM");
	mlx_string_put(window->mlx, window->win, 5, 50, 0xFFFFFF,
		"L = LOCK JULIA");
	mlx_string_put(window->mlx, window->win, 5, 70, 0xFFFFFF,
		"R = RESET");
	mlx_string_put(window->mlx, window->win, 5, 90, 0xFFFFFF,
		"Enter = CHANGE COLOR");
	mlx_string_put(window->mlx, window->win, 5, 110, 0xFFFFFF,
		"Nums = CHANGE FRACTAL");
	mlx_string_put(window->mlx, window->win, 5, 130, 0xFFFFFF,
		"F = FLOWER MODE");
	mlx_string_put(window->mlx, window->win, 5, 150, 0xFF0000,
		"Esc || Q = EXIT");
	mlx_string_put(window->mlx, window->win, W_WIDTH - 50, 10, 0xFFFFFF,
		str);
	free(str);
}

void	fractals(void)
{
	ft_putstr("Fractals that are available: \n");
	ft_putstr(" - mandelbrot || M\n");
	ft_putstr(" - julia || J\n");
	ft_putstr(" - burningship || S\n");
	ft_putstr(" - cube || N\n");
	ft_putstr(" - brain || B\n");
}
