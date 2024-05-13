/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:46:52 by jveras2           #+#    #+#             */
/*   Updated: 2024/04/05 10:35:12 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	char	*s;

	s = (char *) src;
	i = 0;
	if (size == 0)
		return (ft_strlen(s));
	while (s[i] && i < size - 1)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(s));
}
