/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:20:30 by jveras            #+#    #+#             */
/*   Updated: 2024/04/29 10:12:11 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

int	ft_check_args(const char *format, int i, int counter, va_list ap)
{
	if (format[i + 1] == 'c')
		counter += ft_putchar_fd(va_arg(ap, int), 1);
	else if (format[i + 1] == 's')
		counter += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (format[i + 1] == 'p')
		counter += ft_putaddr(va_arg(ap, unsigned long));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		counter += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (format[i + 1] == 'u')
		counter += ft_putuns_fd(va_arg(ap, unsigned int), 1);
	else if (format[i + 1] == 'x')
		counter += ft_lower_hex(va_arg(ap, unsigned int));
	else if (format[i + 1] == 'X')
		counter += ft_upper_hex(va_arg(ap, unsigned int));
	else if (format[i + 1] == '%')
		counter += ft_putchar_fd('%', 1);
	return (counter);
}
