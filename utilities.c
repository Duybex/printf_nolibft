/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohen <acohen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:18:17 by acohen            #+#    #+#             */
/*   Updated: 2024/07/22 19:49:04 by acohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_to_hex_char_lower(unsigned long long digit)
{
	char	c;

	if (digit < 10)
		c = digit + '0';
	else
		c = digit - 10 + 'a';
	return (c);
}

static char	ft_to_hex_char_upper(unsigned long long digit)
{
	char	c;

	if (digit < 10)
		c = digit + '0';
	else
		c = digit - 10 + 'A';
	return (c);
}

static void	ft_reverse_ptr(char *s)
{
	int		start;
	int		end;
	char	temp;

	end = ft_strlen (s) - 1;
	start = 2;
	while (end > start)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
}

unsigned int	ft_print_pointer(void *p)
{
	unsigned long long	addr;
	char				buffer[20];
	char				c;
	int					i;

	if (p == NULL)
		return (ft_printf ("(nil)"));
	addr = (unsigned long long)p;
	i = 2;
	buffer [0] = '0';
	buffer [1] = 'x';
	while (addr != 0)
	{
		c = addr % 16;
		buffer[i] = ft_to_hex_char_lower(c);
		addr /= 16;
		i++;
	}
	buffer [i] = '\0';
	ft_reverse_ptr (buffer);
	ft_putstr_fd(buffer, 1);
	return (ft_strlen(buffer));
}

int	ft_print_hex(unsigned int num, int is_upper, int count)
{
	char	c;

	if (num == 0 && count == 0)
	{
		write (1, "0", 1);
		count++;
	}
	if (num > 0)
	{
		if (is_upper == 1)
			c = ft_to_hex_char_upper(num % 16);
		else
			c = ft_to_hex_char_lower(num % 16);
		count = ft_print_hex(num / 16, is_upper, count + 1);
		ft_putchar_fd(c, 1);
	}
	return (count);
}
