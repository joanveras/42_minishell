/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:26:52 by jveras            #+#    #+#             */
/*   Updated: 2024/06/07 15:12:37 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*get_current_pwd(void)
{
	char	*path;
	char	*current_dir;

	path = getcwd(NULL, 0);
	if (ft_strrchr(path, '/'))
	{
		current_dir = ft_strrchr(path, '/');
		if (ft_strlen(current_dir) == 1)
			return (path);
		return (current_dir + 1);
	}
	return (path);
}

char	*get_user_input(void)
{
	char	*path;
	char	*raw_input;

	path = get_current_pwd();
	ft_printf("%s#%s  %s%s%s\n%s$%s", \
		BWHT, RESET_COLOR, BMAG, path, \
		RESET_COLOR, BGRN, RESET_COLOR);
	raw_input = readline("  ");
	return (raw_input);
}
