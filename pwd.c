/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:08:20 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/24 12:31:43 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void pwd(char *input, t_env *env)
{
	int pid = fork();
	char *current_directory;
	char **args;

	args = ft_split(input, ' ');
	if (pid == 0)
	{
		if (ft_strncmp(args[0], "pwd", ft_strlen(args[0])) == 0 && count_quotes(input) % 2 == 0)
		{
			redirect(ft_split(input, ' '));
			if (heredoc(ft_split(input, ' '), env))
				exit(1);
			current_directory = getcwd(NULL, 0);
			if (current_directory)
			{
				ft_printf("%s\n", current_directory);
				free(current_directory);
			}
			else
				perror("Erro ao obter o diretório de trabalho atual");
			exit(1);
		}
	}
	waitpid(pid, NULL, 0);
}
