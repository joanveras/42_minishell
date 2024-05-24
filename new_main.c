#include "minishell.h"

void	wait_cmds(t_word *node)
{
	t_word				*aux;
	extern unsigned int	g_exit_status;

	if (!node)
		return ;
	aux = node;
	while (node)
	{
		if (node->pid != 0)
			waitpid(node->pid, &node->status, 0);
		node = node->next;
	}
	return ;
}

int	main(void)
{
	extern char **environ;
	char *input;
	int fd[2];
	t_env *env;
	t_word *list;

	env = init_env(environ);
	env->environ = environ;
	while (1)
	{
		input = readline("\x1b[1;36mminishell\u2192\x1b[0m ");
		input = ft_strtrim(join_expand(input, env), " \t");
		add_history(input);
		list = creat_list(input);
		token(list);
		executor(list, env);
		wait_cmds(list);
		// print_list(list);
		// Clean up (free memory)
	}
	return 0;
}
