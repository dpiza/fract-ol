/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:49:26 by dpiza             #+#    #+#             */
/*   Updated: 2021/10/28 23:49:02 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

void	info(t_data *data)
{
	int		px;
	int		py;
	char	*iterations;
	int		color;

	color = 0x00000000;
	px = 8;
	py = 15;
	iterations = ft_itoa(data->iterations);
	mlx_string_put(data->vars->mlx, data->vars->win, px, py, color,
		"Iterations: ");
	mlx_string_put(data->vars->mlx, data->vars->win, px + 80, py, color,
		iterations);
	mlx_string_put(data->vars->mlx, data->vars->win, px, py + 780, color,
		"Hold H to view keybinding");
	free (iterations);
}

void	help(t_data *data)
{
	int		px;
	int		py;
	int		color;

	color = 0x00000000;
	px = 8;
	py = 705;
	mlx_string_put(data->vars->mlx, data->vars->win, px, py, color,
		"[W][A][S][D]:    move screen");
	mlx_string_put(data->vars->mlx, data->vars->win, px, py + 15, color,
		"[E][Q]|[Scroll]: zoom in and out");
	mlx_string_put(data->vars->mlx, data->vars->win, px, py + 30, color,
		"[+][-]:          control iteration");
	mlx_string_put(data->vars->mlx, data->vars->win, px, py + 45, color,
		"[C][V]:          control seed (Julia Set only)");
	mlx_string_put(data->vars->mlx, data->vars->win, px, py + 60, color,
		"[SPACE]:         change color");
	mlx_string_put(data->vars->mlx, data->vars->win, px, py + 75, color,
		"[R]:             reset fractal");
	info(data);
}
