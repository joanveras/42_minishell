#include "../../includes/minishell.h"

t_bool	echo_command(char *input)
{
	char	**args;

	args = ft_split(input, ' ');
	if (!args[1] && ft_strncmp("echo", args[0], ft_strlen(args[0])) == 0)
		return (TRUE);
	else if (ft_strncmp("echo", args[0], ft_strlen(args[0])) == 0
		&& ft_strncmp("-n", args[1], ft_strlen(args[1])) == 0)
		return (TRUE);
	else if (ft_strncmp("echo", args[0], ft_strlen(args[0])) == 0)
		return (TRUE);
	//free ARGS
	return (FALSE);
}
