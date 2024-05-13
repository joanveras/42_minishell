#include "../../../includes/minishell.h"

size_t	count_double_quotes(char *str)
{
	int		i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == DOUBLE_QUOTES)
			counter++;
		i++;
	}
	return (counter);
}

static int count_words(const char *str)
{
	int		i;
	int		count;
	t_bool	between_dq;

	count = 0;
	between_dq = FALSE;
	i = 0;
	while (str[i])
	{
		if (str[i] == DOUBLE_QUOTES)
			between_dq = !between_dq;
		else if (str[i] == '|' && !between_dq)
		{
			if (str[i] && str[i + 1] && str[i - 1] != DOUBLE_QUOTES)
				count++;
		}
		i++;
	}
	if (!between_dq)
		count++;
	return (count);
}

static void	ignore_double_q(char *str, int *index, size_t *len)
{
	if (count_double_quotes(str) % 2 == 0
		&& str[*index] == DOUBLE_QUOTES)
	{
		if (str[*index] == DOUBLE_QUOTES)
		{
			(*len)++;
			(*index)++;
		}
		while (str[*index] && str[*index] != DOUBLE_QUOTES)
		{
			(*len)++;
			(*index)++;
		}
	}
}

static void	cpy(char *input, int *index, char *substr)
{
	int	i;

	i = 0;
	while (input[*index] && input[*index] != '|')
	{
		if (input[*index] == DOUBLE_QUOTES)
		{
			substr[i] = input[*index];
			i++;
			(*index)++;
			while (input[*index] && input[*index] != DOUBLE_QUOTES)
			{
				substr[i] = input[*index];
				i++;
				(*index)++;
			}
		}
		substr[i] = input[*index];
		i++;
		(*index)++;
	}
	substr[i] = '\0';
	(*index)++;
}

static char	*alloc_substr(char *input, int *index)
{
	int		i;
	size_t	len;
	char	*substr;

	len = 0;
	i = *index;
	while (input[i] && input[i] != '|')
	{
		ignore_double_q(input, &i, &len);
		len++;
		i++;
	}
	substr = malloc(len + 1);
	cpy(input, index, substr);
	return (substr);
}

char	**pipe_split(char *input)
{
	int		i;
	int		j;
	int		k;
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * count_words(input) + 1);
	k = 0;
	j = 0;
	i = 0;
	while (i < count_words(input))
	{
		if(input[k])
		{
			strs[j] = alloc_substr(input, &k);
			j++;
		}
		i++;
	}
	strs[j] = NULL;
	return (strs);
}
