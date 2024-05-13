#include "../../../includes/minishell.h"

t_env	*init_env(char **environ)
{
	t_env	*env;

	env = ft_calloc(sizeof(t_env), 0);
	if (!env)
	{
		ft_putstr_fd("Error: Alocating memory: init_env()\n", 2);
		return (NULL);
	}
	while (*environ)
	{
		append_env_var(env, *environ);
		*environ++;
	}
	return (env);
}

void	append_env_var(t_env *env, char *env_s)
{
	t_env	*current;
	t_env	*new_env_var;

	if (!env->env_var_s)
	{
		env->env_var_s = ft_strdup(env_s);
		env->next = NULL;
		return ;
	}
	current = env;
	while (current->next)
		current = current->next;
	new_env_var = ft_calloc(sizeof(t_env), 0);
	if (!new_env_var)
	{
		ft_putstr_fd("Error: Alocating memory: append_env_var()\n", 2);
		return ;
	}
	new_env_var->env_var_s = ft_strdup(env_s);
	new_env_var->next = NULL;
	current->next = new_env_var;
}

void	list_remove_if(t_env **env, char *str, \
	int (*cmp)(const char *, const char *, size_t))
{
	t_env	*current = *env;
	t_env	*previous = NULL;
	
	if (!env || !*env || !str || !cmp)
		return;
	while (current && cmp(str, current->env_var_s, ft_strlen(str)) != 0)
	{
		previous = current;
		current = current->next;
	}
	if (!current)
		return;
	if (previous)
	{
		previous->next = current->next;
		free(current);
		return ;
	}
	*env = current->next;
	free(current);
}

void	print_env(t_env *env)
{
	t_env	*current;

	current = env;
	while (current)
	{
		ft_printf("%s\n", current->env_var_s);
		current = current->next;
	}
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		free(tmp);
	}
	free(env);
}
