#include "../../includes/minishell.h"

t_bool	unset_command(char *input, t_env *env)
{
	char	**args;

	args = ft_split(input, ' ');
	if (!args[1] && ft_strncmp("unset", args[0], ft_strlen(args[0])) == 0)
	{
		ft_printf("%s: not enough arguments\n", args[0]);
		return (TRUE);
	}
	else if (ft_strncmp("unset", args[0], ft_strlen(args[0])) == 0)
	{
		list_remove_if(&env, args[1], ft_strncmp);
		return (TRUE);
	}
	// free ARGS
	return (FALSE);
}
