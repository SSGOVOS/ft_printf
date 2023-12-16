/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:41:04 by amoubine          #+#    #+#             */
/*   Updated: 2023/12/16 01:31:18 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(unsigned long int nbr)
{
	int	counter;

	counter = 0;
	if (!nbr)
	{
		counter += ft_putstr("(nil)");
		return (counter);
	}
	return (counter);
}

int	ft_putnbr_base(unsigned long nbr, char c, int flag)
{
	int		counter;
	char	*base;

	counter = 0;
	if (c == 'p' && ft_check(nbr) == 5)
		return (5);
	if (flag == 1)
		counter += ft_putstr("0x");
	if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (c == 'x' || c == 'X')
	{
		if (nbr >= 16)
			counter += ft_putnbr_base((unsigned int)nbr / 16, c, 0);
	}
	else
	{
		if (nbr >= 16)
			counter += ft_putnbr_base(nbr / 16, c, 0);
	}
	counter += ft_putchar(base[nbr % 16]);
	return (counter);
}
// int main()
// {
//     int num = -26;
//     printf("%d",ft_putnbr_base(num));
//     ft_putchar('\n');
// 	printf("%x", num);
//     return (0);
// }
