/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:57:23 by jveras            #+#    #+#             */
/*   Updated: 2023/11/07 08:23:21 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr_fd(int n, int fd);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);

int	ft_putaddr(unsigned long n);
int	ft_lower_hex(unsigned int n);
int	ft_upper_hex(unsigned int n);
int	ft_putuns_fd(unsigned int n, int fd);

int	ft_printf(const char *format, ...);
int	ft_check_args(const char *format, int i, int counter, va_list ap);

#endif