/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:38:51 by vzamyati          #+#    #+#             */
/*   Updated: 2018/05/07 16:38:53 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		validation(char *fractal, t_win *window)
{
	if (ft_strequ(fractal, "mandelbrot") || ft_strequ(fractal, "M"))
		window->fractal = 1;
	else if (ft_strequ(fractal, "julia") || ft_strequ(fractal, "J"))
		window->fractal = 2;
	else if (ft_strequ(fractal, "burningship") || ft_strequ(fractal, "S"))
		window->fractal = 3;
	else if (ft_strequ(fractal, "cube") || ft_strequ(fractal, "C"))
		window->fractal = 4;
	else if (ft_strequ(fractal, "brain") || ft_strequ(fractal, "B"))
		window->fractal = 5;
	else if (ft_strequ(fractal, "hiro") || ft_strequ(fractal, "H"))
		window->fractal = 6;
	else
		window->fractal = 0;
	return (window->fractal);
}
