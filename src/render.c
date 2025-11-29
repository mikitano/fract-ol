/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:57:37 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/29 15:17:20 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

static void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	ft_madel_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	ft_handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (ft_map(x, -2, +2, WIDTH) + fractal->shift_x) * fractal->zoom;
	z.y = (ft_map(y, +2, -2, HEIGHT) + fractal->shift_y) * fractal->zoom;
	ft_madel_or_julia(&z, &c, fractal);
	while (i < fractal->iter_def)
	{
		z = ft_sum_complex(ft_square_complex(z), c); // z = z^2 + c
		if ((z.x * z.x) + (z.y * z.y) > fractal->escp_value)
		{
			color = ft_map(i, BLACK, WHITE, fractal->iter_def);
			ft_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	ft_pixel_put(x, y, &fractal->img, BLUE_DEEP);
}

void	ft_fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			ft_handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_start, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
