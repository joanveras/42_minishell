#include "../../includes/minishell.h"

static int	open_fd_to_read_from(char *file)
{
	int	input_fd;

	input_fd = open(file, O_RDONLY);
	if (input_fd == -1)
	{
		perror("Error: open()");
		exit(EXIT_FAILURE);
	}
	return (input_fd);
}

static int	open_fd_to_write_in(char *file)
{
	int	output_fd;

	output_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
	{
		perror("Error: open()");
		exit(EXIT_FAILURE);
	}
	return (output_fd);
}

static void	open_fds(char **args, int *input_fd, int *output_fd)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strncmp(args[i], "<", ft_strlen(args[i])) == 0)
		{
			*input_fd = open_fd_to_read_from(args[i + 1]);
			args[i] = NULL;
		}
		else if (ft_strncmp(args[i], ">", ft_strlen(args[i])) == 0)
		{
			*output_fd = open_fd_to_write_in(args[i + 1]);
			args[i] = NULL;
		}
		i++;
	}
}

void	redirect(char **args)
{
	int	input_fd;
	int	output_fd;
	int	i;

	input_fd = -1;
	output_fd = -1;
	open_fds(args, &input_fd, &output_fd);
	if (input_fd != -1)
	{
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}
	if (output_fd != -1)
	{
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
	}
}
