/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:25:32 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/24 08:50:21 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int hidenp(char *cmd, char *input)
{
	int i = 0;
	int j = 0;

	while (input[j] && cmd[i])
	{
		if (input[j] == cmd[i])
		i++;
		j++;
	}
	if (cmd[i] == '\0')
		return 1;
	else
		return 0;
}

int check_builtin(char *input, t_env *env)
{
	if (hidenp("pwd", input) == 1)
		return 1;
	else if (hidenp("echo", input) == 1)
		return 1;
	else if (hidenp("export", input) == 1)
	{
		export_command(input, env);
		return 1;
	}
	else if (hidenp("unset", input) == 1)
	{
		unset_command(input, env);
		return 1;
	}
	else if (hidenp("env", input) == 1)
	{
		env_command(input, env);
		return 1;
	}
	else if (hidenp("cd", input) == 1)
	{
		cd(input);
		return 1;
	}
	return 0;
}
