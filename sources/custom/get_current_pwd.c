#include "../../includes/minishell.h"

char	*get_current_pwd(void)
{
	char	*path;
	char	*current_dir;

	path = getcwd(NULL, 0);
	if (ft_strrchr(path, '/'))
	{
		current_dir = ft_strrchr(path, '/');
		if (ft_strlen(current_dir) == 1)
				return (path);
		return (current_dir + 1);
	}
	return (path);
}
