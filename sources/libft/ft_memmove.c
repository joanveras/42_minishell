/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:11:28 by jveras2           #+#    #+#             */
/*   Updated: 2024/04/05 10:34:12 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*new_dest;
	char	*new_src;

	if (!dest && !src)
		return (NULL);
	new_dest = dest;
	new_src = (char *) src;
	i = 0;
	if (new_dest < new_src)
	{
		ft_memcpy(new_dest, new_src, n);
	}
	else
	{
		i = n - 1;
		while (n--)
		{
			new_dest[i] = new_src[i];
			i--;
		}
	}
	return (new_dest);
}
