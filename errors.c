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
		ft_putstr_fd("Usage:\n./fractol [fractal's name]\n", 2);
		fractals();
	}
	if (error_code == 2)
	{
		ft_putstr_fd("Sorry, that is not available :(\n", 2);
		fractals();
	}
	if (error_code == 3)
		ft_putstr_fd("Unable to allocate memory for window.\n", 2);
	if (error_code == 4)
		ft_putstr_fd("Unable to allocate memory for palette.\n", 2);
	exit(1);
}
