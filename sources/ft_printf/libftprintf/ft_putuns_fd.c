/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:24:49 by jveras            #+#    #+#             */
/*   Updated: 2024/04/05 13:22:41 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

int	ft_putuns_fd(unsigned int n, int fd)
{
	static int	char_counter;

	char_counter = 0;
	if (n == 4294967286)
		return (ft_putstr_fd("4294967286", fd));
	else if (n >= 10)
	{
		ft_putuns_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
		char_counter++;
	}
	else if (n < 10)
	{
		ft_putchar_fd((n % 10) + '0', fd);
		char_counter++;
	}
	return (char_counter);
}
