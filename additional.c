/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:52:11 by vzamyati          #+#    #+#             */
/*   Updated: 2018/06/14 15:52:12 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		data_init(t_win *window)
{
	window->palette = 1;
	window->f_mode = 0;
	window->iter = MAX_ITER;
}

int			choose_palette(int loopgo, t_win *window)
{
	if (window->palette == 1)
		return (palette_mix(loopgo));
	else if (window->palette == 2)
		return (palette_red(loopgo));
	else if (window->palette == 3)
		return (palette_green(loopgo));
	else if (window->palette == 4)
		return (palette_blue(loopgo));
	else if (window->palette == 5)
		return (palette_purple(loopgo));
	return (0);
}
