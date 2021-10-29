/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 23:31:57 by dpiza             #+#    #+#             */
/*   Updated: 2021/10/29 00:30:33 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H
/*
** Environment definitions
*/
# define ITERATIONS	60
# define WIDTH		800
# define HEIGHT		800
# define STEPS		0.03
/*
** Key mapping
*/
# define UP			65362
# define DOWN		65364
# define LEFT		65361
# define RIGHT		65363
# define W			119
# define S			115
# define A			97
# define D			100
# define E			101
# define Q			113
# define R 			114
# define C			99
# define V			118
# define SPACE		32
# define PLUS		65451
# define MINUS		65453
# define ESC		65307
/*
** Usage message
*/
# define USAGE		"Usage: ./fractol [OPTION] [PARAM1] [PARAM2]"
# define AVAILABLE	"Available options:"
# define OPTIONS	"\t\tMandelbrot\n\t\tCeltic\n\t\tBurning-Ship\n\t\tJulia"
# define PARAMS		"Use PARAM1 and PARAM2 for Julia set seeds"

#endif