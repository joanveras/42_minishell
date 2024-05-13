#include "../../includes/minishell.h"

void	redirect_echo(char *input)
{
	__pid_t	pid;
	char	**args;

	args = ft_split(input, ' ');
	pid = fork();
	if (pid == 0)
	{	
		redirect(args);
		if (!args[1] && ft_strncmp("echo", args[0], ft_strlen(args[0])) == 0)
			ft_printf("\n");
		else if (ft_strncmp("echo", args[0], ft_strlen(args[0])) == 0
			&& ft_strncmp("-n", args[1], ft_strlen(args[1])) == 0)
			ft_printf("%s", remove_extra_spaces( \
				echo_output_delimeter(input), TRUE) + 8);
		else if (ft_strncmp("echo", args[0], ft_strlen(args[0])) == 0)
			ft_printf("%s\n", remove_extra_spaces( \
				echo_output_delimeter(input), TRUE) + 5);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, NULL, 0);
	//free ARGS
}

void	redirect_env(char *input, t_env *env)
{
	int		i;
	int		fd;
	char	*output_fd;
	char	**args;
	t_env	*current;

	args = ft_split(input, ' ');
	if (ft_strncmp(args[0], "env", ft_strlen(args[0])) == 0)
	{
		i = 0;
		while (args[i])
		{
			if (ft_strncmp(args[i], ">", ft_strlen(args[i])) == 0)
			{
				fd = open(args[i + 1], O_WRONLY, O_CREAT, O_APPEND, 0666);
				args[i] = NULL;
			}
			i++;
		}
		current = env;
		while (current)
		{
			write(fd, ft_strjoin(current->env_var_s, "\n"),
				ft_strlen(ft_strjoin(current->env_var_s, "\n")));
			current = current->next;
		}
		close(fd);
	}
}

void	redirect_pwd(char *input)
{
	char	*path;
	char	**args;
	__pid_t	pid;

	pid = fork();
	args = ft_split(input, ' ');
	if (pid == 0)
	{
		if (ft_strncmp(args[0], "pwd", ft_strlen(args[0])) == 0)
		{
			redirect(ft_split(input, ' '));
			path = getcwd(NULL, 0);
			if (path)
			{
				ft_printf("%s\n", path);
				free(path);
			}
			exit(EXIT_SUCCESS);
		}
	}
	waitpid(pid, NULL, 0);
	//free ARGS
}

void	call_redirects(char *input, t_env * env)
{
	redirect_echo(input);
	redirect_pwd(input);
	redirect_env(input, env);
}
