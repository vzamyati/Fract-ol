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

void	put_image(t_win *window, int x, int y, int color)
{
	int a;

	if (!(x > 0 && y > 0 && x < W_WIDTH &&  y < W_HEIGHT))
		return ;
	(void)a;
	*(int *)(window->data +
			(x + y * W_WIDTH) * window->bpp / 8) = color;
}

void	fractals(void)
{
	ft_putstr("Fractals that are available: \n");
	ft_putstr(" - mandelbrot \n");
}

void		next_step(char *fractal)
{
	if (!ft_strcmp(fractal, "mandelbrot"))
		mandelbrot();
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac < 2)
		ft_error(1);
	while (++i < ac)
	{
		ft_strtolower(av[i]);
		if (validation(av[i]))
			next_step(av[i]);
		else
			ft_error(2);
	}
	return (0);
}
