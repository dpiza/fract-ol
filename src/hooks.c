/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:13:19 by dpiza             #+#    #+#             */
/*   Updated: 2021/10/28 23:45:51 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

int	mouse_hook(int k, int x, int y, t_data *data)
{
	double_t	mx;
	double_t	my;

	mx = (double_t)(x - (WIDTH / 2)) / 100;
	my = (double_t)(y - (HEIGHT / 2)) / 100;
	if (k == 4)
		zoom(data, E, mx, my);
	else if (k == 5)
		zoom(data, Q, mx, my);
	fractol(data);
	expose_hook(data);
	return (0);
}

int	key_hook(int k, t_data *data)
{
	if (k == ESC)
		winclose(data);
	else if (k == RIGHT || k == D)
		move(data, 'x', STEPS);
	else if (k == UP || k == W)
		move(data, 'y', -STEPS);
	else if (k == LEFT || k == A)
		move(data, 'x', -STEPS);
	else if (k == DOWN || k == S)
		move(data, 'y', STEPS);
	else if (k == E || k == Q)
		zoom(data, k, 0, 0);
	else if (k == PLUS || k == MINUS
		|| k == SPACE || k == C || k == V)
		change_stat(data, k);
	else if (k == R)
		setup_fractal(data);
	else if (k == 104)
	{
		help(data);
		return (0);
	}
	fractol(data);
	expose_hook(data);
	return (0);
}

int	help_release(int k, t_data *data)
{
	if (k == 104)
		expose_hook(data);
	return (0);
}

int	expose_hook(t_data *data)
{
	mlx_do_sync(data->vars->mlx);
	mlx_put_image_to_window(data->vars->mlx, data->vars->win, data->img, 0, 0);
	info(data);
	return (0);
}

int	winclose(t_data *data)
{
	mlx_destroy_image(data->vars->mlx, data->img);
	mlx_destroy_window(data->vars->mlx, data->vars->win);
	mlx_destroy_display(data->vars->mlx);
	free (data->vars->mlx);
	free (data->vars->title);
	exit (EXIT_SUCCESS);
}
