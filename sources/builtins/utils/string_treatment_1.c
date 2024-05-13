#include "../../../includes/minishell.h"

char	*echo_output_delimeter(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>' || str[i] == '<')
		{
			str[i] = '\0';
			return (str);
		}
		i++;
	}
	return (str);
}

size_t	count_single_quotes(char *str)
{
	int		i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == SINGLE_QUOTE)
			counter++;
		i++;
	}
	return (counter);
}

char	*str_remove_q(char *str)
{
	int		i;
	int		j;
	char	*cmd;

	if (count_single_quotes(str) % 2 == 0)
	{
		cmd = malloc((ft_strlen(str) - count_single_quotes(str)) + 1);
		j = 0;
		i = 0;
		while (str[i])
		{
			if (str[i] == DOUBLE_QUOTES || str[i] == SINGLE_QUOTE)
			{
				i++;
				continue ;
			}
			cmd[j++] = str[i++];
		}
		cmd[j] = '\0'; 
		return (cmd);
	}
	return (NULL);
}

static void	maintain_double_quotes_spaces(char **str, int *i, int *j)
{
	if ((*str)[*i] && (*str)[*i] == DOUBLE_QUOTES)
	{
		(*i)++;
		while ((*str)[*i] && (*str)[*i] != DOUBLE_QUOTES)
		{
			(*str)[*j] = (*str)[*i];
			(*j)++;
			(*i)++;
		}
		(*i)++;
		(*str)[(*j)++] = ' ';
	}
}

char	*remove_extra_spaces(char *str, t_bool maintain_double_q_spaces)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (maintain_double_q_spaces)
			maintain_double_quotes_spaces(&str, &i, &j);
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
		{
			if (str[i] == DOUBLE_QUOTES && maintain_double_q_spaces)
				maintain_double_quotes_spaces(&str, &i, &j);
			str[j] = str[i];
			if (str[i + 1] == ' ' || str[i + 1] == '\t')
				str[++j] = ' ';
			j++;
			i++;
		}
	}
	if (str[j - 1] == ' ' || str[j - 1] == '\t')
		j--;
	str[j] = '\0';
	return (str);
}

