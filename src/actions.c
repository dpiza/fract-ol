/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:57:51 by dpiza             #+#    #+#             */
/*   Updated: 2021/10/29 00:39:19 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

void	move(t_data *data, int axle, float steps)
{
	if (axle == 'x')
		data->offx += steps * data->side;
	else if (axle == 'y')
		data->offy += steps * data->side;
}

void	change_stat(t_data *data, int k)
{
	if (k == PLUS)
		data->iterations += 10;
	else if (k == MINUS)
		data->iterations -= 10;
	else if (k == C)
		data->c.r -= 0.001;
	else if (k == V)
		data->c.r += 0.001;
	else if (k == SPACE)
		data->phase += 0.1;
}

void	zoom(t_data *data, int k, double_t x, double_t y)
{
	int	way;

	way = 1;
	if (k == Q && data->side >= 5)
		return ;
	if (k == Q)
		way = -1;
	data->side -= way * (0.04 * data->side);
	data->offx += way * (0.02 * data->side + (x * 0.01 * data->side));
	data->offy += way * (0.02 * data->side + (y * 0.01 * data->side));
}
