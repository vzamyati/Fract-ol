/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:20:08 by vzamyati          #+#    #+#             */
/*   Updated: 2018/04/21 19:20:09 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define MAX_ITER		50

# define PI 			3.14159265359
# define W_HEIGHT		1200
# define W_WIDTH 		1200

typedef struct 			s_win
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*fractal;
	char				*data;
	int 				bpp;
	int 				size_line;
	int 				endian;
	// double				zoom;
	// double				moveX;
	// double				moveY;
	// int 				iter;
	// double				re_tmp;
	// double				im_tmp;
	// int 				palette;
}						t_win;

// typedef struct 			s_f
// {
// 	double				z;
// 	double				x;
// 	double				y_end;
// 	double				y_start;
// 	double				zoom;
// 	double				moveX;
// 	double				moveY;
// 	int 				iter;
// 	double				oldRe;
// 	double				oldIm;
// 	double				newRe;
// 	double				newIm;
// 	double				tmpRe;;
// 	double				tmpIm;;
// 	int 				loopgo;
// 	int 				palette;
// 	t_win				*window;
// }						t_f;

void		mandelbrot(void);
void		ft_error(int error_code);
void		fractals(void);
void		next_step(char *fractal);
int			validation(char *fractal);
void		init_fract(t_win *window);
void	put_image(t_win *window, int x, int y, int color);

t_win		*init_win(char *fractal);

#endif