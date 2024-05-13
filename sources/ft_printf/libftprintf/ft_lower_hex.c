/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:23:40 by jveras            #+#    #+#             */
/*   Updated: 2024/04/05 13:21:58 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

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

int	ft_lower_hex(unsigned int n)
{
	unsigned long	num;
	int				i;
	char			rem;
	char			hex[8];

	if (n == 0)
		return (ft_putchar_fd('0', 1));
	num = n;
	i = 0;
	while (num > 0)
	{
		rem = num % 16;
		if (rem < 10)
			hex[i] = rem + '0';
		else
			hex[i] = rem + ('7' + 32);
		num = num / 16;
		i++;
	}
	return (print(hex, i));
}
