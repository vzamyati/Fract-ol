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
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define MAX_ITER		150

# define PI 			3.14159265359
# define W_HEIGHT		1200
# define W_WIDTH 		1200

typedef struct 			s_complex
{
	double				re;
	double				im;		
}						t_complex;

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
	t_complex			max;
	t_complex			min;
	t_complex			factor;
	t_complex 			z;
	t_complex 			real;
	double				oldre;
	double				tempzre;
	int 				loopgo;
	int 				x_ptr;
	int 				y_ptr;
	int 				f_mode;
}						t_win;


int			key_events(int key, t_win *window);
int			validation(char *fractal);
int			f_exit(t_win *window);
void		f_move(t_win *window, int x, int y);
void		f_move2(t_win *window, int x, int y);
void		redraw_image(t_win *window);
void		ft_error(int error_code);
void		fractals(void);
void		next_step(char *fractal);
void		init_fract(t_win *window);
void		mandelbrot(t_win *window);
void		iterating_drawing(t_win *mandel);
void		put_image(t_win *window, int x, int y, int color);
void		var_back(t_win *window);

t_win 		*init_mandel(t_win *mandel);
t_win		*init_win(char *fractal);

#endif
