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

#define ERROR_MESSAGE "Please enter \n\t"./fractol mandelbrot\" or \n\t"./fractol julia <value_1> <value_2>\."\n"

#define WIDTH	800
#define HEIGHT	800

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
	//hooks TODO
}	t_fractal;

void	ft_fractal_init(t_fractal *fractal);

#endif