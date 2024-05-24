/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:16:18 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/24 08:35:03 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *join_expand(char *input, t_env *env)
{
	int i = 0;
	char *ret = ft_strdup("");
	char **args = ft_split(input, ' ');

	while (args[i])
	{
		if (ft_strchr(args[i], '$'))
		{
			ret = ft_strjoin(ret, getenv(args[i] + 1));
			ret = ft_strjoin(ret, " ");
			i++;
			continue;
		}
		ret = ft_strjoin(ret, args[i]);
		ret = ft_strjoin(ret, " ");
		i++;
	}
	return (ret);
}
