
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
	while ( *s == '+' || *s == '-')
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
