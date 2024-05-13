#include "../../includes/minishell.h"

static void	custom_chdir(char *path, char *command)
{
	if (chdir(path) == -1)
		ft_printf("%s: no such file or directory: %s\n", command, path);
}

t_bool	cd_command(char *input, t_env *env)
{
	t_env	*current;

	if (ft_strncmp("cd", input, ft_strlen(input)) == 0
		|| ft_strncmp("cd ~", input, ft_strlen(input)) == 0)
	{
		current = env;
		while (current)
		{
			if (current->env_var_s && ft_strncmp(current->env_var_s, "HOME=", 5) == 0)
				chdir(current->env_var_s + 5);
			current = current->next;
		}
		return (TRUE);
	}
	else if (ft_strncmp("cd ..", input, ft_strlen(input)) == 0
		|| (ft_strncmp("cd", input, 2) == 0 && ft_strlen(input) > 3))
	{
		custom_chdir(remove_extra_spaces(input, FALSE) + 3, first_word(input));
		return (TRUE);
	}
	return (FALSE);
}
