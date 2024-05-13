/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:53:41 by jveras2           #+#    #+#             */
/*   Updated: 2024/04/05 10:34:47 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*new_s;

	new_s = (char *) s;
	while (*new_s && *new_s != c)
		new_s++;
	if (*new_s == c)
		return (new_s);
	return (NULL);
}
