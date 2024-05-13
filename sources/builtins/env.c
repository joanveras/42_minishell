#include "../../includes/minishell.h"

t_bool	env_command(char *input, t_env *env)
{
	char	**args;

	args = ft_split(input, ' ');
	if (ft_strncmp(args[0], "env", ft_strlen(args[0])) == 0)
	{
		if (!ft_strchr(input, '>'))
			print_env(env);
		return (TRUE);
	}
	return (FALSE);
}
