/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:30:11 by felperei          #+#    #+#             */
/*   Updated: 2024/06/07 15:23:29 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

unsigned int	g_exit_status;

int	main(void)
{
	extern char	**environ;
	char		*input;
	t_env		*env;
	t_word		*data;

	input = ft_strdup("");
	data = NULL;
	env = init_env(environ);
	env->environ = environ;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	implemente_prompt(input, data, env);
	free_env(env);
	return (0);
}
