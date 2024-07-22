/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohen <acohen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:42:00 by acohen            #+#    #+#             */
/*   Updated: 2024/07/22 19:44:09 by acohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		d;
	long	num;

	num = n;
	d = 1;
	if (num < 0)
	{
		write (fd, "-", 1);
		num = -num;
	}
	while (num / d >= 10)
		d = d * 10;
	while (d != 0)
	{
		c = '0' + (num / d);
		write (fd, &c, 1);
		num = num % d;
		d = d / 10;
	}
}

void	ft_putstr_fd(char *str, int fd)
{
	if (str != NULL)
	{
		while (*str)
			write(fd, str++, 1);
	}
	else
		(ft_putstr_fd ("(null)", fd));
}

size_t	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	if (str == NULL)
		return (6);
	while (str [c] != '\0')
	{
		c++;
	}
	return (c);
}
