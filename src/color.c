/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:30:09 by dpiza             #+#    #+#             */
/*   Updated: 2021/10/28 23:44:25 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

int	psychedelite(double_t phase, int count)
{
	int		r;
	int		g;
	int		b;

	r = sin(0.08 * count + 2 + phase) * 128 + 127;
	g = sin(0.08 * count + 0 + phase) * 128 + 127;
	b = sin(0.08 * count + 4 + phase) * 128 + 127;
	return (r << 16 | g << 8 | b);
}

void	light_pixel(t_data *data, int x, int y, int count)
{
	if (count < data->iterations)
		data->addr[y * WIDTH + x] = psychedelite(data->phase, count);
	else
		data->addr[y * WIDTH + x] = 0x00000000;
}
