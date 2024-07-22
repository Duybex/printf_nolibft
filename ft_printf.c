/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohen <acohen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:37:47 by acohen            #+#    #+#             */
/*   Updated: 2024/07/22 19:48:57 by acohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr_count(char *s)
{
	int	count;

	count = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (count);
}

static int	ft_putchar_count(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_arg(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count = ft_putchar_count(va_arg(args, int));
	else if (type == 'i' || type == 'd')
		count = ft_putnbr_count(va_arg(args, int));
	else if (type == 'X')
		count = ft_print_hex(va_arg(args, unsigned int), 1, 0);
	else if (type == 'x')
		count = ft_print_hex(va_arg(args, unsigned int), 0, 0);
	else if (type == 's')
		count = ft_putstr_count(va_arg(args, char *));
	else if (type == 'u')
		count = ft_put_unsigned(va_arg(args, unsigned int));
	else if (type == '%')
		count = ft_putchar_count('%');
	else if (type == 'p')
		count = ft_print_pointer(va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;
	int		i;

	printed = 0;
	i = 0;
	va_start (args, format);
	while (format[i])
	{
		if (format[i] != '%')
			printed = printed + ft_putchar_count(format[i++]);
		else if (format[i + 1])
		{
			i++;
			printed = printed + ft_print_arg(format[i], args);
			i++;
		}
	}
	va_end (args);
	return (printed);
}
