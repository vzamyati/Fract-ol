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

int		palette_mix(int i)
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

int		palette_red(int i)
{
	int color;

	color = 0;
	color = i == 0 ? 0x000000 : color;
	color = i == 1 ? 0x330000 : color;
	color = i == 2 ? 0x4d0000 : color;
	color = i == 3 ? 0x660000 : color;
	color = i == 4 ? 0x800000 : color;
	color = i == 5 ? 0x990000 : color;
	color = i == 6 ? 0xb30000 : color;
	color = i == 7 ? 0xcc0000 : color;
	color = i == 8 ? 0xe60000 : color;
	color = i == 9 ? 0xff0000 : color;
	color = i == 10 ? 0xff4d4d : color;
	color = i == 11 ? 0xff8080 : color;
	color = i == 12 ? 0xff9999 : color;
	color = i == 13 ? 0xffcccc : color;
	color = i == 14 ? 0xffe6e6 : color;
	color = i == 15 ? 0xffffff : color;
	return (color);
}

int		palette_green(int i)
{
	int color;

	color = 0;
	color = i == 0 ? 0x000000 : color;
	color = i == 1 ? 0x06130d : color;
	color = i == 2 ? 0x0d261a : color;
	color = i == 3 ? 0x133926 : color;
	color = i == 4 ? 0x194d33 : color;
	color = i == 5 ? 0x206040 : color;
	color = i == 6 ? 0x26734d : color;
	color = i == 7 ? 0x2d8659 : color;
	color = i == 8 ? 0x339966 : color;
	color = i == 9 ? 0x40bf80 : color;
	color = i == 10 ? 0x66cc99 : color;
	color = i == 11 ? 0x8cd9b3 : color;
	color = i == 12 ? 0x9fdfbf : color;
	color = i == 13 ? 0xb3e6cc : color;
	color = i == 14 ? 0xd9f2e6 : color;
	color = i == 15 ? 0xffffff : color;
	return (color);
}

int		palette_blue(int i)
{
	int color;

	color = 0;
	color = i == 0 ? 0x000000 : color;
	color = i == 1 ? 0x060d13 : color;
	color = i == 2 ? 0x0d1a26 : color;
	color = i == 3 ? 0x132639 : color;
	color = i == 4 ? 0x19334d : color;
	color = i == 5 ? 0x204060 : color;
	color = i == 6 ? 0x264d73 : color;
	color = i == 7 ? 0x2d5986 : color;
	color = i == 8 ? 0x336699 : color;
	color = i == 9 ? 0x3973ac : color;
	color = i == 10 ? 0x538cc6 : color;
	color = i == 11 ? 0x79a6d2 : color;
	color = i == 12 ? 0x9fbfdf : color;
	color = i == 13 ? 0xc6d9ec : color;
	color = i == 14 ? 0xecf2f9 : color;
	color = i == 15 ? 0xffffff : color;
	return (color);
}

int		palette_purple(int i)
{
	int color;

	color = 0;
	color = i == 0 ? 0x000000 : color;
	color = i == 1 ? 0x0f001a : color;
	color = i == 2 ? 0x1f0033 : color;
	color = i == 3 ? 0x2e004d : color;
	color = i == 4 ? 0x3d0066 : color;
	color = i == 5 ? 0x4c0080 : color;
	color = i == 6 ? 0x5c0099 : color;
	color = i == 7 ? 0x6b00b3 : color;
	color = i == 8 ? 0x7a00cc : color;
	color = i == 9 ? 0x8a00e6 : color;
	color = i == 10 ? 0xa31aff : color;
	color = i == 11 ? 0xb84dff : color;
	color = i == 12 ? 0xcc80ff : color;
	color = i == 13 ? 0xe0b3ff : color;
	color = i == 14 ? 0xf5e6ff : color;
	color = i == 15 ? 0xffffff : color;
	return (color);
}
