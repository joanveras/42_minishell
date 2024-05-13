#include "../../../includes/minishell.h"

t_bool	is_builtin(char *input, t_env *env)
{
	if (env_command(input, env))
		return (TRUE);
	/*else if (cd_command(ft_strtrim(input, " 	"), env))
		return (TRUE);*/
	else if (export_command(ft_strtrim(input, " 	"), env))
		return (TRUE);
	else if (unset_command(ft_strtrim(input, " 	"), env))
		return (TRUE);
	else if (echo_command(ft_strtrim(input, " 	")))
		return (TRUE);
	else if (pwd_command(ft_strtrim(input, " 	")))
		return (TRUE);
	return (FALSE);
}
