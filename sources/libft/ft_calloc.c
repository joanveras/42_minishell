/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:07:58 by jveras2           #+#    #+#             */
/*   Updated: 2024/04/05 10:33:41 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*list;
	size_t	total_size;

	total_size = nmemb * size;
	list = malloc(total_size);
	if (list != NULL)
		ft_memset(list, 0, total_size);
	return (list);
}
