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

int		validation(char *fractal)
{
	if (!ft_strcmp(fractal, "mandelbrot"))
		return (1);
	return (0);
}