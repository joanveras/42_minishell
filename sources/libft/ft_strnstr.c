/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:29:47 by jveras2           #+#    #+#             */
/*   Updated: 2024/04/05 10:35:30 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *) big);
	i = 0;
	while (big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			while ((big[i + j] == little[j])
				&& big[i + j] && ((i + j) < len))
				j++;
			if (!little[j])
				return (((char *) big) + i);
		}
		i++;
	}
	return (NULL);
}
