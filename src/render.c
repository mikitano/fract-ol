
#include "fractol.h"

static void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y + img->line_len) + (x * (img->bits_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	ft_handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = ft_map(x, -2, +2, 0, WIDTH);
	c.y = ft_map(y, +2, -2, 0. HEIGHT);
	while (i < fractal->iter_def)
	{
		z = ft_sum_complex(ft_square_complex(z), c);    // z = z^2 + c
		if ((z.x * z.x) + (z.y * z.y) > fractal->escp_value)
		{
			color = ft_map (i, BLACK, WHITE, 0, fractal->iter_def);
			ft_pixel_put();  // TODO
			return ;
		}
	}
}

void	ft_fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			ft_handle_pixel(x, y, fractal);
		}
	}
}
