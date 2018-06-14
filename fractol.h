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

# define MAX_ITER		55

# define W_HEIGHT		1000
# define W_WIDTH 		1000

# define MWHEEL_UP		5
# define MWHEEL_DOWN	4

# define ESC			53
# define Q				12
# define AR_RIGHT		124
# define AR_LEFT		123
# define AR_UP			126
# define AR_DOWN		125
# define R				15
# define L				37
# define NUM_1			18
# define NUM_2			19
# define NUM_3			20
# define NUM_4			21
# define NUM_5			23
# define NUM_6			22
# define ENTER			36
# define F				3
# define MORE			47
# define LESS			43

typedef struct			s_complex
{
	double				re;
	double				im;
}						t_complex;

typedef struct			s_win
{
	void				*mlx;
	void				*win;
	void				*img;
	int					fractal;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
	t_complex			max;
	t_complex			min;
	t_complex			factor;
	t_complex			z;
	t_complex			c;
	int					palette;
	int					color;
	double				zoom;
	int					loopgo;
	int					x_ptr;
	int					y_ptr;
	int					f_mode;
	int					iter;
	int					lock;
	int					first;
}						t_win;

/*
** additional.c
*/
void					data_init(t_win *window);
int						choose_palette(int loopgo, t_win *window);
/*
**brain.c
*/
void					iterating_drawing_brain(t_win *brain);
void					brain(t_win *brain);
t_win					*init_brain(t_win *brain);
/*
**bship.c
*/
void					iterating_drawing_ship(t_win *bship);
void					bship(t_win *bship);
t_win					*init_bship(t_win *bship);
/*
**changes.c
*/
void					change_palette(t_win *window);
void					change_fract(int key, t_win *window);
void					flower_mode(t_win *window);
void					change_iter(int key, t_win *window);
void					make_changes(t_win *window);
/*
**cube.c
*/
void					iterating_drawing_cube(t_win *cube);
void					cube(t_win *cube);
t_win					*init_cube(t_win *cube);
/*
**errors.c
*/
void					ft_error(int error_code);
/*
**events.c
*/
int						f_exit(t_win *window);
int						key_events(int key, t_win *window);
/*
**hiro.c
*/
t_win					*init_hiro(t_win *hiro);
void					hiro(t_win *hiro);
void					iterating_drawing_hiro(t_win *hiro);
/*
**image.c
*/
void					put_image(t_win *window, int x, int y, int color);
void					iterating_drawing(t_win *win);
void					redraw_image(t_win *window);
void					reset_fractal(t_win *window);
/*
**info.c
*/
void					info(t_win *window);
void					fractals(void);
/*
**julia.c
*/
void					lock_julia(t_win *window);
void					julia(t_win *julia);
t_win					*init_julia(t_win *julia);
/*
**main.c
*/
int						expose(t_win *window);
/*
**mandelbrot.c
*/
void					mandelbrot(t_win *mandel);
t_win					*init_mandel(t_win *mandel);
/*
**movement.c
*/
int						mouse_move(int x, int y, t_win *window);
void					f_move2(t_win *window, int x, int y);
void					f_move(t_win *window, int x, int y);
/*
**palettes.c
*/
int						palette_mix(int i);
int						palette_red(int i);
int						palette_green(int i);
int						palette_blue(int i);
int						palette_purple(int i);
/*
**validation.c
*/
int						validation(char *fractal, t_win *window);
/*
**vars.c
*/
void					var_recount2(t_win *window, t_complex d);
void					var_back(t_win *window);
t_complex				var_recount(t_win *window, int x, int y);
void					get_factor(t_win *window);
/*
**zoom.c
*/
void					f_zoom(t_win *window, double nzoom, int x, int y);
int						mousebtn_press_hook(int button, int x, int y, t_win *w);

#endif
