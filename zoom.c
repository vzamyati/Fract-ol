/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:19:33 by vzamyati          #+#    #+#             */
/*   Updated: 2018/06/01 20:19:34 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			f_zoom(t_win *window, double nzoom, int x, int y)
{
	t_complex	d;

	window->zoom = nzoom;
	d = var_recount(window, x, y);
	var_recount2(window, d);
	var_back(window);
	mouse_move(x, y, window);
}

int				mousebtn_press_hook(int button, int x, int y, t_win *window)
{
	if (button == MWHEEL_UP || button == MWHEEL_DOWN)
	{
		if (button == MWHEEL_DOWN)
			f_zoom(window, 0.87, x, y);
		else if (button == MWHEEL_UP)
			f_zoom(window, 1.13, x, y);
		redraw_image(window);
	}
	return (0);
}
