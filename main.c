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
}

void	next_step(char *fractal)
{
	if (!ft_strcmp(fractal, "mandelbrot"))
		return ;//mandelbrot();
}

int		main(int ac, char **av)
{
	int i;
	t_win	*window;

	i = 0;
	if (ac == 2)
	{
		ft_strtolower(av[1]);
		if (validation(av[1]) == 0)
			ft_error(1);
		window = init_win("Fractol by vz");
		window = init_mandel(window);
		mandelbrot(window);
		mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
		mlx_hook(window->win, 2, 5, key_events, window);
		mlx_hook(window->win, 4, 1L << 2,
				mousebtn_press_hook, window);
		mlx_hook(window->win, 17, 1L << 17, f_exit, window);
		mlx_loop(window->mlx);
	}
	else
		ft_error(2);
	return (0);
}
