/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:27:15 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/29 17:23:11 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot")) || (ac == 4
			&& !ft_strcmp(av[1], "julia")))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			if ((ft_valid(av[2])) || (ft_valid(av[3])))
				ft_erro_bundle();
			fractal.julia_x = ft_atodbl(av[2]);
			fractal.julia_y = ft_atodbl(av[3]);
		}
		ft_fractal_init(&fractal);
		ft_fractal_render(&fractal);
		mlx_loop(fractal.mlx_start);
	}
	else
	{
		ft_error_msg();
		exit(EXIT_FAILURE);
	}
	return (0);
}
