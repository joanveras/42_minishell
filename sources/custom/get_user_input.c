#include "../../includes/minishell.h"

char	*get_user_input(void)
{
	char	*path;
	char	*raw_input;

	path = get_current_pwd();
	ft_printf("%s#%s  %s%s%s\n%s$%s", \
		BWHT, RESET_COLOR, BMAG, path, \
		RESET_COLOR, BGRN, RESET_COLOR);
	raw_input = readline("  ");
	return (raw_input);
}
