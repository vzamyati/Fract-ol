/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:20:53 by vzamyati          #+#    #+#             */
/*   Updated: 2018/04/21 19:20:54 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractals(void)
{
	ft_putstr("Fractals that are available: \n");
	ft_putstr(" - mandelbrot \n");
	ft_putstr(" - julia \n");
}

void 	fractol(t_win *window)
{
	window->img = mlx_new_image(window->mlx, W_WIDTH, W_HEIGHT);
	window->data = mlx_get_data_addr(window->img, &(window->bpp), &(window->size_line), &(window->endian));
	if (window->fractal == 1)
	{
		window = init_mandel(window);
		mandelbrot(window);
	}
	if (window->fractal == 2)
	{
		window = init_julia(window);
		julia(window);
	}
	if (window->fractal == 3)
	{
		window = init_bship(window);
		bship(window);
	}
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
}

int		main(int ac, char **av)
{
	t_win	*window;

	window = ft_memalloc(sizeof(t_win));
	if (ac == 2)
	{
		if (validation(av[1], window) == 0)
			ft_error(1);
		window->mlx = mlx_init();
		window->win = mlx_new_window(window->mlx, W_WIDTH, W_HEIGHT, "fractol by vz");
		mlx_expose_hook(window->win, expose, window);
		mlx_hook(window->win, 6, 1L << 6, mouse_move, window);
		mlx_hook(window->win, 2, 5, key_events, window);
		mlx_hook(window->win, 4, 1L << 2, mousebtn_press_hook, window);
		mlx_hook(window->win, 17, 1L << 17, f_exit, window);
		mlx_loop(window->mlx);
	}
	else
		ft_error(2);
	return (0);
}
