/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 21:06:15 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/26 23:06:38 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}
static void	ft_data_init(t_fractal *fractal)
{
	fractal->escp_value = 4;
	fractal->iter_def = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;   // zoom factor;
}
static void	ft_events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMaks, ft_key_handler,
			fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtomPressMaks,
			ft_mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
			ft_close_handler, fractal);
	mlx_hook(fractal->mlx_window, MotionNotify, PointerMotionMask,
			ft_julia_track, fractal);

}

void	ft_fractal_init(t_fractal *fractal)
{
	fractal->mlx_start = mlx_init();
	if (fractal->mlx_start == NULL)
		ft_malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_start, WIDTH, HEIGHT,
										fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_start);
		free(fractal->mlx_start);
		ft_malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_start, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_start, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_start);
		free(fractal->mlx_start);
		ft_malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bits_pixel, &fractal->img.line_len, &fractal->img.endian);
	ft_events_init(fractal);
	ft_data_init(fractal);
}
