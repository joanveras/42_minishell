#include "../../includes/minishell.h"

t_bool	pwd_command(char *input)
{
	char	**args;

	args = ft_split(input, ' ');
	if (ft_strncmp(args[0], "pwd", ft_strlen(args[0])) == 0)
		return (TRUE);
	//free ARGS
	return (FALSE);
}
