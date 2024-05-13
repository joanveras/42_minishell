/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:23:55 by jveras            #+#    #+#             */
/*   Updated: 2024/04/29 10:10:47 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

static int	is_zero(void)
{
	write(1, "(nil)", 5);
	return (5);
}

static	int	print(char *hex, int i)
{
	int	char_counter;

	char_counter = 0;
	while (i--)
	{
		ft_putchar_fd(hex[i], 1);
		char_counter++;
	}
	return (char_counter);
}

int	ft_putaddr(unsigned long n)
{
	int		i;
	char	rem;
	char	hex[16];

	if (n == 0)
		return (is_zero());
	i = 0;
	while (n > 0)
	{
		rem = n % 16;
		if (rem < 10)
			hex[i] = rem + '0';
		else
			hex[i] = rem + ('7' + 32);
		n = n / 16;
		i++;
	}
	hex[i++] = 'x';
	hex[i++] = '0';
	return (print(hex, i));
}
