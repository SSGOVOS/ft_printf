/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:24:27 by amoubine          #+#    #+#             */
/*   Updated: 2023/12/15 00:16:07 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, char c)
{
	int	counter;

	counter = 0;
	if (c == 'd' || c == 'i')
	{
		if (n == -2147483648)
		{
			return (ft_putstr("-2147483648"));
		}
		else
		{
			if (n < 0)
			{
				ft_putchar('-');
				n *= -1;
				counter++;
			}
			if (n > 9)
				counter += ft_putnbr((n / 10), c);
			counter += ft_putchar(n % 10 + '0');
		}
	}
	return (counter);
}

// int	main(void)
// {
// 	ft_printf("\n\n%d\n", ft_putnbr((2147483647), 'd'));
// }