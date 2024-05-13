#include "../../includes/minishell.h"

t_bool	export_command(char *input, t_env *env)
{
	char	**args;
	char	*env_var_name;

	args = ft_split(input, ' ');
	if (!args[1] && ft_strncmp("export", args[0], ft_strlen(args[0])) == 0)
		return (TRUE); // implement function to print ENV in alphabetical order
	else if (ft_strncmp("export", args[0], ft_strlen(args[0])) == 0)
	{
		append_env_var(env, remove_extra_spaces(input, TRUE) + 7);
		return (TRUE);
	}
	// free ARGS
	return (FALSE);
}
