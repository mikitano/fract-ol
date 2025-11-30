/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 10:46:59 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/29 17:17:07 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atodbl(char *s)
{
	long	integer_part;
	double	fraction_part;
	double	power;
	int		sign;

	integer_part = 0;
	fraction_part = 0;
	sign = +1;
	power = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
	{
		power /= 10;
		fraction_part = fraction_part + (*s++ - '0') * power;
	}
	return ((integer_part + fraction_part) * sign);
}

int	ft_valid(char *av)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (av[0] == '\0')
		return (1);
	while (av[i])
	{
		if ((av[i] >= 9 && av[i] <= 13) || (av[i] == 32))
			return (1);
		if ((av[i] == '+' || av[i] == '-') && i > 0)
			return (1);
		if ((av[i] >= 'a' && av[i] <= 'z') || (av[i] >= 'A' && av[i] <= 'Z'))
			return (1);
		if ((av[i] >= '0' && av[i] <= '9') || (av[i] == '.'))
		{
			if (av[i] == '.')
				flag++;
			if (flag > 1 && av[i] == '.')
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_erro_bundle(void)
{
	ft_error_msg();
	exit(EXIT_FAILURE);
	return ;
}
