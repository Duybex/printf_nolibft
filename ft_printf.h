/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohen <acohen@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:37:59 by acohen            #+#    #+#             */
/*   Updated: 2024/07/22 19:49:01 by acohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

unsigned int	ft_print_pointer(void *p);
int				ft_print_hex(unsigned int num, int is_upper, int count);
int				ft_printf(const char *format, ...);
int				ft_print_unsigned(int n);
int				ft_putnbr_count(int n);
int				ft_put_unsigned(int n);
size_t			ft_strlen(const char *str);
void			ft_putstr_fd(char *str, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);

#endif