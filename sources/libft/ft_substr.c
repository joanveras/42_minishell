/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:51:24 by jveras2           #+#    #+#             */
/*   Updated: 2024/04/05 10:35:43 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*subs;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	subs = malloc((sizeof(char) * len) + 1);
	if (!s || !subs)
		return (NULL);
	i = 0;
	while (s[start] && len--)
		subs[i++] = s[start++];
	subs[i] = '\0';
	return (subs);
}
