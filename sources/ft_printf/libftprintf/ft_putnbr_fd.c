/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:24:21 by jveras            #+#    #+#             */
/*   Updated: 2024/04/29 10:12:17 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

static	int	print_numbers(int *list, long n, int counter, int fd)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		list[i] = n % 10;
		n = n / 10;
		i++;
	}
	while (i > 0)
	{
		list[i - 1] = list[i - 1] + '0';
		ft_putchar_fd(list[i - 1], fd);
		counter++;
		i--;
	}
	return (counter);
}

int	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	int		nlist[10];
	int		char_counter;

	char_counter = 0;
	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		char_counter++;
		nbr = -nbr;
	}
	else if (nbr == 0)
	{
		ft_putchar_fd('0', 1);
		char_counter++;
	}
	return (print_numbers(nlist, nbr, char_counter, fd));
}
