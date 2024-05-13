/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:24:33 by jveras            #+#    #+#             */
/*   Updated: 2024/04/29 10:10:14 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	char_counter;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	char_counter = 0;
	while (*s)
	{
		write(fd, s++, 1);
		char_counter++;
	}
	return (char_counter);
}
