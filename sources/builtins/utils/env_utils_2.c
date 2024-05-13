#include "../../../includes/minishell.h"

size_t	list_size(t_env *env)
{
	size_t	counter;
	t_env	*current;

	counter = 0;
	current = env;
	while (current)
	{
		counter++;
		current = current->next;
	}
	return (counter);
}

char	**env_list_to_sstrs(t_env *env)
{
	int		i;
	char	**sstrs;
	t_env	*current;

	sstrs = malloc(sizeof(char *) * list_size(env) + 1);
	current = env;
	i = 0;
	while (current)
	{
		sstrs[i] = current->env_var_s;
		current = current->next;
		i++;
	}
	sstrs[i] = NULL;
	return (sstrs);
}
