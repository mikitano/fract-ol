/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 10:45:07 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/29 11:21:55 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

double	ft_map(double unscaled_num, double new_min, double new_max,
		double old_max)
{
	double	old_min;
	double	result;

	old_min = 0;
	result = (new_max - new_min) * (unscaled_num - old_min) / (old_max
			- old_min) + new_min;
	return (result);
}

t_complex	ft_sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	ft_square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
