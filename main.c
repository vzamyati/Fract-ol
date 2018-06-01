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
	t_win	*mandel;

	i = 0;
	(void)av;
	if (ac < 2)
		ft_error(1);
	mandel = init_win("Mandelbrot by vz");
	mandel = init_mandel(mandel);
	// while (++i < ac)
	// {
	// 	ft_strtolower(av[i]);
	// 	if (validation(av[i]))
	// 		next_step(av[i]);
	// 	else
	// 		ft_error(2);
	// }
	mandelbrot(mandel);
	mlx_put_image_to_window(mandel->mlx, mandel->win, mandel->img, 0, 0);
	mlx_key_hook(mandel->win, key_events, mandel);
	mlx_hook(mandel->win, 17, 1L << 17, f_exit, mandel);
	mlx_loop(mandel->mlx);
	return (0);
}
