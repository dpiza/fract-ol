/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:39:09 by dpiza             #+#    #+#             */
/*   Updated: 2021/10/28 23:44:47 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

int	mandelbrot_point(t_cnb c, t_cnb v, int it)
{
	t_cnb		z;
	t_cnb		zsqr;
	int			count;

	(void)v;
	z.r = 0;
	z.i = 0;
	zsqr.r = z.r * z.r;
	zsqr.i = z.i * z.i;
	count = 0;
	while ((zsqr.r + zsqr.i < 4) && (count < it))
	{
		z.i = 2 * z.r * z.i + c.i;
		z.r = zsqr.r - zsqr.i + c.r;
		zsqr.r = pow(z.r, 2);
		zsqr.i = pow(z.i, 2);
		count++;
	}
	return (count);
}

int	celtic_point(t_cnb c, t_cnb v, int it)
{
	t_cnb		z;
	t_cnb		zsqr;
	int			count;

	(void)v;
	z.r = 0;
	z.i = 0;
	zsqr.r = z.r * z.r;
	zsqr.i = z.i * z.i;
	count = 0;
	while ((zsqr.r + zsqr.i < 4) && (count < it))
	{
		z.i = 2 * z.r * z.i + c.i;
		z.r = fabs(zsqr.r - zsqr.i) + c.r;
		zsqr.r = pow(z.r, 2);
		zsqr.i = pow(z.i, 2);
		count++;
	}
	return (count);
}

int	burning_point(t_cnb c, t_cnb v, int it)
{
	t_cnb		z;
	t_cnb		zsqr;
	int			count;

	(void)v;
	z.r = 0;
	z.i = 0;
	zsqr.r = z.r * z.r;
	zsqr.i = z.i * z.i;
	count = 0;
	while ((zsqr.r + zsqr.i < 4) && (count < it))
	{
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		z.i = 2 * z.r * z.i + c.i;
		z.r = zsqr.r - zsqr.i + c.r;
		zsqr.r = pow(z.r, 2);
		zsqr.i = pow(z.i, 2);
		count++;
	}
	return (count);
}

int	julia_point(t_cnb z, t_cnb c, int it)
{
	t_cnb		zsqr;
	int			count;

	zsqr.r = z.r * z.r;
	zsqr.i = z.i * z.i;
	count = 0;
	while ((zsqr.r + zsqr.i < 4) && (count < it))
	{
		z.i = 2 * z.r * z.i + c.i;
		z.r = zsqr.r - zsqr.i + c.r;
		zsqr.r = pow(z.r, 2);
		zsqr.i = pow(z.i, 2);
		count++;
	}
	return (count);
}

void	fractol(t_data *data)
{
	t_cnb		c;
	int			x;
	int			y;
	double_t	ratio;

	y = -1;
	ratio = data->side / WIDTH;
	if (ratio == 0)
		perror("Limit Reached");
	while (y++ < HEIGHT)
	{
		x = -1;
		while (x++ < WIDTH)
		{
			c.r = (x * ratio + data->offx);
			c.i = (y * ratio + data->offy);
			light_pixel(data, x, y,
				data->func(c, data->c, data->iterations));
		}
	}
}
