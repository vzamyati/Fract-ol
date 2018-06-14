/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:32:26 by vzamyati          #+#    #+#             */
/*   Updated: 2018/06/06 15:32:27 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			var_recount2(t_win *window, t_complex d)
{
	double		in;
	t_complex	min;
	t_complex	max;

	in = 1.0 / window->zoom;
	min.re = (d.re + ((window->min.re - d.re) * in));
	max.re = (d.re + ((window->max.re - d.re) * in));
	min.im = (d.im + ((window->min.im - d.im) * in));
	max.im = (d.im + ((window->max.im - d.im) * in));
	if (max.re - min.re == window->c.re)
		return ;
	if (max.im - min.im == window->c.im)
		return ;
	window->max = max;
	window->min = min;
	get_factor(window);
	window->c.im = max.im - min.im;
	window->c.re = max.re - min.re;
}

void			var_back(t_win *window)
{
	window->x_ptr = 0;
	window->y_ptr = -1;
}

t_complex		var_recount(t_win *window, int x, int y)
{
	t_complex	v;

	v.re = (double)x * window->factor.re + window->min.re;
	v.im = (((double)y * window->factor.im + window->min.im) * -1);
	return (v);
}

void			get_factor(t_win *window)
{
	window->factor.re = ((window->max.re - window->min.re)
		/ (double)(W_WIDTH - 1));
	window->factor.im = ((window->max.im - window->min.im)
		/ (double)(W_HEIGHT - 1));
}
