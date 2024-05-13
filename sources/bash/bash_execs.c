#include "../../includes/minishell.h"

void bash_execs(char *input, char **args, t_env *env)
{
	char	*path;
	__pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		redirect(args);
		path = ft_strjoin("/bin/", first_word(input));
		if (execve(path, args, env_list_to_sstrs(env)) == -1)
		{
			ft_printf("minishell: command not found: %s\n", first_word(input));
			exit(EXIT_FAILURE);
		}
	}
	waitpid(pid, NULL, 0);
}
