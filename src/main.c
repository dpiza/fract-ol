/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:23:57 by dpiza             #+#    #+#             */
/*   Updated: 2021/10/29 03:57:03 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

int	setup_env(char **argv, t_vars *vars, t_data *data)
{
	vars->mlx = mlx_init();
	if (!(vars->mlx))
	{
		perror("mlx_init error");
		exit (0);
	}
	vars->title = ft_strjoin("Fractol - ", argv[1]);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, vars->title);
	data->vars = vars;
	data->type = argv[1][0];
	data->c.r = 0;
	data->c.i = 0;
	if (data->type == 'J')
	{
		data->func = &julia_point;
		data->c.r = ft_atof(argv[2]);
		data->c.i = ft_atof(argv[3]);
	}
	if (data->type == 'M')
		data->func = &mandelbrot_point;
	if (data->type == 'B')
		data->func = &burning_point;
	if (data->type == 'C')
		data->func = &celtic_point;
	return (0);
}

void	init_img(t_data *data)
{
	data->img = mlx_new_image(data->vars->mlx, WIDTH, HEIGHT);
	data->addr = (int *)mlx_get_data_addr(data->img, &data->bpp,
			&data->ll, &data->end);
}

int	setup_fractal(t_data *data)
{
	data->iterations = ITERATIONS;
	data->phase = 10;
	data->offx = -2;
	data->offy = -2;
	data->side = 4;
	if (data->type == 'M')
		data->offx = -2.5;
	else if (data->type == 'C')
		data->offx = -2.7;
	else if (data->type == 'B')
	{
		data->offx = -2.8;
		data->offy = -3;
		data->side = 5;
	}
	return (0);
}

void	run_window(t_data *data)
{
	mlx_mouse_hook(data->vars->win, mouse_hook, data);
	mlx_hook(data->vars->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->vars->win, 3, 1L << 1, help_release, data);
	mlx_expose_hook(data->vars->win, expose_hook, data);
	mlx_hook(data->vars->win, 17, 0L, winclose, data);
	mlx_loop(data->vars->mlx);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	data;

	if (argc < 2)
	{
		ft_printf("%s\n\n%s\n%s\n\n%s\n",
			USAGE, AVAILABLE, OPTIONS, PARAMS);
		exit (EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "Mandelbrot", 11) != 0
		&& ft_strncmp(argv[1], "Burning-Ship", 13) != 0
		&& ft_strncmp(argv[1], "Celtic", 7) != 0
		&& (!(ft_strncmp(argv[1], "Julia", 6) == 0 && argc > 3)))
	{
		ft_printf("Invalid Option\n");
		ft_printf("%s\n\n%s\n%s\n\n%s\n",
			USAGE, AVAILABLE, OPTIONS, PARAMS);
		exit (EXIT_FAILURE);
	}
	setup_env(argv, &vars, &data);
	init_img(&data);
	setup_fractal(&data);
	fractol(&data);
	run_window(&data);
	return (EXIT_SUCCESS);
}
