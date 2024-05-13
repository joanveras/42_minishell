/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:20:51 by jveras2           #+#    #+#             */
/*   Updated: 2024/04/05 10:34:53 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*new_s;

	size = ft_strlen(s);
	new_s = malloc(sizeof(char) * size + 1);
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s, size + 1);
	return (new_s);
}
