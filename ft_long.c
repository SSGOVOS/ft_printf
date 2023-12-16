/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:32:56 by amoubine          #+#    #+#             */
/*   Updated: 2023/12/16 01:30:54 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_long(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n > 9)
		counter += ft_long(n / 10);
	counter += ft_putchar(n % 10 + '0');
	return (counter);
}
