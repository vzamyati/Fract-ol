
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:46:52 by vzamyati          #+#    #+#             */
/*   Updated: 2018/05/07 12:46:54 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	data_init(t_win *window, char *fract)
// {
// 	window->fractal = fract;
// 	window->zoom = 1;
// 	window->moveX = 0;
// 	window->moveY = 0;
// 	window->iter = MAX_ITER;
// 	window->re_tmp = 0;
// 	window->im_tmp = 0;
// 	window->palette = 1;
// }

t_win	*init_win(char *fractal)
{
	t_win	*window;

	window = (t_win*)ft_memalloc(sizeof(t_win));
	if (!window)
	{
		ft_error(3);
		return (NULL);
	}
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, W_WIDTH, W_HEIGHT, fractal);
	// data_init(window, fractal);
	window->img = mlx_new_image(window->mlx, W_WIDTH, W_HEIGHT);
	window->data = mlx_get_data_addr(window->img, &(window->bpp), &(window->size_line), &(window->endian));
	// if (!(ft_strcmp(window->fractal, "mandelbrot")))
	// 	pthread_for_mand(window);
	// mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	return (window);
}
