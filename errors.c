/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:39:29 by vzamyati          #+#    #+#             */
/*   Updated: 2018/05/07 16:39:30 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int error_code)
{
	if (error_code == 1)
	{
		ft_putstr("Usage:\n./fractol mandelbrot\n");
		fractals();
	}
	if (error_code == 2)
	{
		ft_putstr("Sorry, but you're doing smthing that is not available :(\n");
		fractals();
	}
	if (error_code == 3)
		ft_putstr("Unable to allocate memory for window.\n");
	if (error_code == 4)
		ft_putstr("Unable to allocate memory for palette.\n");
	exit(1);
}
