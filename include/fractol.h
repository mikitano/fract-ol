/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:28:30 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/22 15:25:16 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>   // read, write, close
# include <fcntl.h>    // open, O_RDONLY, O_WRONLY
# include <stdlib.h>   // malloc, free
# include <stdio.h>    // perror
# include <string.h>   // strerror
# include <errno.h>    // errno
# include <math.h>
# include "mlx.h"
# include "../lib/libftx/include/libft.h"

#define ERROR_MESSAGE \
"Please enter:\n" \
"\t./fractol mandelbrot\n" \
"\t./fractol julia <value_1> <value_2>\n"

#define WIDTH	800
#define HEIGHT	800

#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define PINK_PASTEL 0xE8A6C7 
#define PURPLE 0x7937A6

#define NAVY_BLUE 0x0A1128
#define BLUE_DEEP 0x001F54 
#define BLUE_OCEAN 0x034078 
#define AQUA_DEEP 0x1282A2
#define BLUE_PASTEL 0x94C4E3

#define BROWN 0x2F1E1E
#define RED_DARK 0x73030D 
#define ORANGE 0xFF6E12
#define AQUA_LIGHT 0x06ADB3

typedef struct s_complex
{
	double 	x;   // real
	double	y;   // imaginary
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;     // pointer to image sturct
	char	*pixels_ptr;  // points to the actual pixels
	int		bits_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_start;
	void	*mlx_window;
	t_img	img;
	double	escp_value;
	int		iter_def;
	//hooks
	double	shift_x;
	double	shift_y;
	double	zoom;
}	t_fractal;

void	ft_fractal_init(t_fractal *fractal);
void	ft_fractal_render(t_fractal *fractal);

double	ft_map (double unscaled_num, double new_min, double new_max, double old_max);
t_complex	ft_sum_complex(t_complex z1, t_complex z2);
t_complex	ft_square_complex(t_complex z);

int	ft_key_handler(int keysym, t_fractal *fractal);
int	ft_close_handler(t_fractal *fractal);

#endif