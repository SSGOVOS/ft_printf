/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:01:25 by amoubine          #+#    #+#             */
/*   Updated: 2023/12/16 01:17:04 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'x')
		count += ft_putnbr_base((va_arg(args, unsigned int)), 'x', 0);
	else if (c == 'X')
		count += ft_putnbr_base((va_arg(args, unsigned int)), 'X', 0);
	else if (c == 'p')
		count += ft_putnbr_base((va_arg(args, unsigned long)), 'p', 1);
	else if (c == 'd')
		count += ft_putnbr((va_arg(args, int)), 'd');
	else if (c == 'u')
		count += ft_long((va_arg(args, unsigned int)));
	else if (c == 'i')
		count += ft_putnbr((va_arg(args, int)), 'i');
	else
	{
		count += ft_putchar('%');
		count += ft_putchar(c);
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	size_t	i;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s && s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				return (-1);
			else if (s[i] == '%')
				count += ft_putchar('%');
			else
				count += format(s[i], args);
		}
		else if (s[i] != '%')
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
