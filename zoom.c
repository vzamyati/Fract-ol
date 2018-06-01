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

void			var_recount2(t_win *window, t_complex d)
{
	double 		in;
	t_complex 	min;
	t_complex 	max;

	in = 1.0 / window->zoom;
	min.re = (d.re + ((window->min.re - d.re) * in));
	max.re = (d.re + ((window->max.re - d.re) * in));
	min.im = (d.im + ((window->min.im - d.im) * in));
	max.im = (d.im + ((window->max.im - d.im) * in));
	if (max.re - min.re == window->real.re)
		return ;
	if (max.im - min.im == window->real.im)
		return ;
	window->max = max;
	window->min = min;
	get_factor(window);
	window->real.im = max.im - min.im;
	window->real.re = max.re - min.re;
}

void			f_zoom(t_win *window, double nzoom, int x, int y)
{
	t_complex 	d;

	window->zoom = nzoom;
	d = var_recount(window, x, y);
	var_recount2(window, d);
	var_back(window);
}

int				mousebtn_press_hook(int button, int x, int y, t_win *window)
{
	if (button == MOUSE_WHEEL_DOWN)
		f_zoom(window, 0.75, x, y);
	else if (button == MOUSE_WHEEL_UP)
		f_zoom(window, 1.25, x, y);
	mandelbrot(window);
	redraw_image(window);
	return (0);
}
