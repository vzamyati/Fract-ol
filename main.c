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
