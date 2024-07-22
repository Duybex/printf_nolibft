/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohen <acohen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:24:36 by acohen            #+#    #+#             */
/*   Updated: 2024/07/22 19:49:05 by acohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_count(int n)
{
	int			count;
	long int	num;

	num = n;
	count = 1;
	ft_putnbr_fd(num, 1);
	if (num < 0)
	{
		count ++;
		num = -num;
	}
	while (num >= 10)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int	ft_put_unsigned(int n)
{
	char			c;
	int				d;
	unsigned int	num;
	int				count;

	count = 0;
	num = (unsigned int)n;
	d = 1;
	while (num / d >= 10)
		d = d * 10;
	while (d != 0)
	{
		c = '0' + (num / d);
		write (1, &c, 1);
		count++;
		num = num % d;
		d = d / 10;
	}
	return (count);
}

int	ft_print_unsigned(int n)
{
	unsigned int	num;

	num = n;
	return (ft_putnbr_count (num));
}
