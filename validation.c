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
	if (ft_strequ(fractal, "mandelbrot"))
		window->fractal = 1;
	else if (ft_strequ(fractal, "julia"))
		window->fractal = 2;
	else if (ft_strequ(fractal, "burningship"))
		window->fractal = 3;
	else
		window->fractal = 0;
	return (window->fractal);
}