#include "../../includes/minishell.h"

char	*first_word(char *str)
{
	char	*first_word;
	size_t	word_len;
	
	first_word = remove_extra_spaces(str, FALSE);
	if (ft_strchr(first_word, ' '))
	{
		word_len = ft_strlen(first_word) - ft_strlen(ft_strchr(first_word, ' ') + 1);
		ft_strlcpy(first_word, first_word, word_len);
	}
	return (first_word);
}
