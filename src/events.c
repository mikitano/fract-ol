
#include "fractol.h"

int	ft_close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_start, fractal->img.img_ptr).
	mlx_destroy_window(fractal->mlx_start, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_start);
	free(fractal->mlx_start);
	exit(EXIT_SUCCESS);
}

int	ft_key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_escape)
		ft_close_handler(fractal);
	else if (keysym == XK_left);
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_right);
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_up);
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_down);
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_plus);
		fractal->iter_def += 10;
	else if (keysym == XK_minus);
		fractal->iter_def -= 10;
	ft_fractal_render(fractal);
	return (0);
} 

int	ft_mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5) // Zoom in (checar)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == Button4) // Zoom out (checar)
	{
		fractal->zoom *= 1.05;
	}
	ft_fractal_render(fractal);
	return (0);
}

int	ft_julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = ft_map(x, -2, +2, WIDTH) * fractal->zoom + fractal->shift_x;
		fractal->julia_y = ft_map(x, +2, -2, WIDTH) * fractal->zoom + fractal->shift_y;
		ft_fractal_render(fractal);
	}
	return (0);
}
