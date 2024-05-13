/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:37:22 by jveras2           #+#    #+#             */
/*   Updated: 2024/04/05 10:34:00 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*new_s1;
	unsigned char	*new_s2;

	new_s1 = (unsigned char *) s1;
	new_s2 = (unsigned char *) s2;
	while (n--)
	{
		if (*new_s1 > *new_s2)
			return (1);
		else if (*new_s1 < *new_s2)
			return (-1);
		new_s1++;
		new_s2++;
	}
	return (0);
}
