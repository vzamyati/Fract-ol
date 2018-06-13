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

# define MAX_ITER		51

# define W_HEIGHT		1000
# define W_WIDTH 		1000

#define MOUSE_WHEEL_UP	5
#define MOUSE_WHEEL_DOWN 4


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
	int					fractal;
	char				*data;
	int 				bpp;
	int 				size_line;
	int 				endian;
	t_complex			max;
	t_complex			min;
	t_complex			factor;
	t_complex 			z;
	t_complex 			c;
	int 				palette;
	int 				color;
	double				zoom;
	int 				loopgo;
	int 				x_ptr;
	int 				y_ptr;
	int 				f_mode;
	int 				iter;
	int 				lock;
	int 				f_julia;
}						t_win;

void		fractals(void);
int			validation(char *fractal, t_win *window);
void		ft_error(int error_code);

void		f_move(t_win *window, int x, int y);
void		f_move2(t_win *window, int x, int y);
int			mouse_move(int x, int y, t_win *widow);
void		f_zoom(t_win *window, double nzoom, int x, int y);
int			mousebtn_press_hook(int button, int x, int y, t_win *window);

int			key_events(int key, t_win *window);
int			f_exit(t_win *window);

int 		expose(t_win *window);
void		iterating_drawing_ship(t_win *bship);
void		iterating_drawing(t_win *mandel);
void		redraw_image(t_win *window);
void		put_image(t_win *window, int x, int y, int color);

void		var_back(t_win *window);
void		var_recount2(t_win *window, t_complex d);
t_complex	var_recount(t_win *window, int x, int y);
void		get_factor(t_win *window);

void		mandelbrot(t_win *window);
void		bship(t_win *bship);
void		julia(t_win *julia);
void		lock_julia(t_win *window);
t_win 		*init_mandel(t_win *mandel);
t_win 		*init_bship(t_win *bship);
t_win 		*init_julia(t_win *julia);
t_complex	var_recount_zoom(t_win *window, int x, int y);
int 		choose_palette(int loopgo, t_win *window);

int			palette1(int i);
int			palette2(int i);
void		change_palette(t_win *window);

#endif
