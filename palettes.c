/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:47:18 by vzamyati          #+#    #+#             */
/*   Updated: 2018/06/13 11:47:19 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		palette1(int i)
{
	int color;

	color = 0;
	color = i == 0 ? 0x421e0f : color;
	color = i == 1 ? 0x19071a : color;
	color = i == 2 ? 0x09012f : color;
	color = i == 3 ? 0x040449 : color;
	color = i == 4 ? 0x000764 : color;
	color = i == 5 ? 0x0c2c8a : color;
	color = i == 6 ? 0x1852b1 : color;
	color = i == 7 ? 0x397dd1 : color;
	color = i == 8 ? 0x86b5e5 : color;
	color = i == 9 ? 0xd3ecf8 : color;
	color = i == 10 ? 0xf1e9bf : color;
	color = i == 11 ? 0xf8c95f : color;
	color = i == 12 ? 0xffaa00 : color;
	color = i == 13 ? 0xcc8000 : color;
	color = i == 14 ? 0x995700 : color;
	color = i == 15 ? 0x995700 : color;
	return (color);
}

int		palette2(int i)
{
	int r;

	r = 0;
	r = i == 0 ? 0xFF0000 : r;
	r = i == 1 ? 0x97FFFF : r;
	r = i == 2 ? 0xFF0000 : r;
	r = i == 3 ? 0x97FFFF : r;
	r = i == 4 ? 0xFFD700 : r;
	r = i == 5 ? 0x00B2EE : r;
	r = i == 6 ? 0x97FFFF : r;
	r = i == 7 ? 0x7FFF00 : r;
	r = i == 8 ? 0xf8c95f : r;
	r = i == 9 ? 0xFFFF00 : r;
	r = i == 10 ? 0xf8c95f : r;
	r = i == 11 ? 0x7FFF00 : r;
	r = i == 12 ? 0xf8c95f : r;
	r = i == 13 ? 0x00FF00 : r;
	r = i == 14 ? 0xEEEED1 : r;
	r = i == 15 ? 0x00FF00 : r;
	return (r);
}
