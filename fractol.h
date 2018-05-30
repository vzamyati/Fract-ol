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

# define MAX_ITER		150

# define PI 			3.14159265359
# define W_HEIGHT		1200
# define W_WIDTH 		1200

// typedef struct 			s_color
// {
// 	int 				r;
// 	int 				g;
// 	int 				b;
// }						t_color;

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
	int 				flower_m;
	int 				palette;
	double				maxRe;
	double				maxIm;
	double				minRe;
	double				minIm;
	double 				zRe;
	double 				zIm;
	double 				Re;
	double 				Im;
	double 				factor_Re;
	double 				factor_Im;
	double				oldRe;
	double				tempzRe;
	int 				loopgo;
	int 				x_ptr;
	int 				y_ptr;
	int 				f_mode;
	double				minX;
	double				minY;
	double				maxX;
	double				maxY;
	// t_color				*color;
}						t_win;


int			key_events(int key, t_win *window);
int			validation(char *fractal);
int			f_exit(t_win *window);
void		f_move(t_win *window, int key);
void		redraw_image(t_win *window, char *fractal);
void		ft_error(int error_code);
void		fractals(void);
void		next_step(char *fractal);
void		init_fract(t_win *window);
void		mandelbrot(void);
void		iterating_drawing(t_win *mandel);
void		put_image(t_win *window, int x, int y, int color);
void		var_back(t_win *window);
void		redraw_image(t_win *window, char *fractal);

t_win 		*init_mandel(t_win *mandel);
t_win		*init_win(char *fractal);

#endif
