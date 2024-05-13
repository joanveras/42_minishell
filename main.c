#include "includes/minishell.h"

int	main(void)
{
	int			fd[2];
	char		*raw_input;
	extern char	**__environ;
	t_env		*env;

	env = init_env(__environ);
	while (TRUE)
	{
		raw_input = get_user_input();
		add_history(raw_input);
		if (ft_strchr(raw_input, '|'))
		{
			pipe_exec(raw_input, env, fd);
			free(raw_input);
			continue ;
		}
		if (is_builtin(raw_input, env))
		{
			call_redirects(raw_input, env);
			continue ;
		}
		bash_execs(raw_input, ft_split(raw_input, ' '), env);
		free(raw_input);
	}
	return (0);
}
