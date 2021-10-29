/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:23:48 by dpiza             #+#    #+#             */
/*   Updated: 2021/10/29 03:57:10 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
/*
** INCLUDES
*/
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "defines.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
/*
** Mlx instances and window
*/
typedef struct s_vars {
	void		*mlx;
	void		*win;
	char		*title;
}	t_vars;
/*
** Complex number
*/
typedef struct s_cnb {
	double_t	r;
	double_t	i;
}	t_cnb;
/*
** Image and fractal data
*/
typedef struct s_data {
	t_vars		*vars;
	void		*img;
	int			*addr;
	int			bpp;
	int			ll;
	int			end;
	int			type;
	t_cnb		c;
	double_t	offx;
	double_t	offy;
	double_t	side;
	double_t	phase;
	int			iterations;
	int			(*func)(t_cnb, t_cnb, int);
}	t_data;
/*
** Environment settings and core program
** main.c
*/
int		setup_env(char **argv, t_vars *vars, t_data *data);
void	init_img(t_data *data);
int		setup_fractal(t_data *data);
void	run_window(t_data *data);
/*
** Event hooks
** hooks.c
*/
int		mouse_hook(int keycode, int x, int y, t_data *data);
int		key_hook(int keycode, t_data *data);
int		help_release(int k, t_data *data);
int		expose_hook(t_data *data);
int		winclose(t_data *data);
/*
** Actions taken from events
** actions.c
*/
void	move(t_data *data, int axle, float steps);
void	change_stat(t_data *data, int k);
void	zoom(t_data *data, int way, double_t x, double_t y);
/*
** Fractal algorithms
** fractol.c
*/
void	fractol(t_data *data);
int		mandelbrot_point(t_cnb c, t_cnb v, int it);
int		celtic_point(t_cnb c, t_cnb v, int it);
int		burning_point(t_cnb c, t_cnb v, int it);
int		julia_point(t_cnb z, t_cnb c, int it);
/*
** Color and pixel put
** color.c
*/
int		psychedelite(double_t phase, int count);
void	light_pixel(t_data *data, int x, int y, int count);
/*
** Information and Help display
** info.c
*/
void	info(t_data *d);
void	help(t_data *d);

#endif