#include "../../includes/minishell.h"

static void	exec_on_child(char **commands, int *fd, int current_fd, t_env *env)
{
	dup2(current_fd, STDIN_FILENO);
	if (*(commands + 1) != NULL)
		dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	if(is_builtin(*commands, env))
	{
		call_redirects(*commands, env);
		exit(EXIT_SUCCESS);
	}
	if (execve(ft_strjoin("/bin/", first_word(*commands)),
		ft_split(*commands, ' '), env_list_to_sstrs(env)) == -1)
	{
		printf("minishell: command not found: %s\n", first_word(*commands));
		exit(EXIT_FAILURE);
	}
}

void	pipe_exec(char *input, t_env *env, int *fd)
{
	int		current_fd;
	char	**commands;
	__pid_t	pid;

	commands = pipe_split(input);
	current_fd = 0;
	while (*commands != NULL)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
			exec_on_child(commands, fd, current_fd, env);
		waitpid(pid, NULL, 0);
		close(fd[1]);
		current_fd = fd[0];
		commands++;
	}
}
