#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "libft.h"
# include "libftprintf.h"

// color codes
# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"
# define UBLK "\e[4;30m"
# define URED "\e[4;31m"
# define UGRN "\e[4;32m"
# define UYEL "\e[4;33m"
# define UBLU "\e[4;34m"
# define UMAG "\e[4;35m"
# define UCYN "\e[4;36m"
# define UWHT "\e[4;37m"
# define RESET_COLOR "\e[0m"

# define DOUBLE_QUOTES 34
# define SINGLE_QUOTE 39

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_env
{
	char			*env_var_s;
	struct s_env	*next;
}	t_env;

void	redirect(char **args);
void	print_env(t_env *env);
void	redirect_pwd(char *input);
void	redirect_echo(char *input);
void	redirect_env(char *input, t_env *env);
void	append_env_var(t_env *env, char *env_s);
void	call_redirects(char *input, t_env * env);
void	pipe_exec(char *input, t_env *env, int *fd);
void	bash_execs(char *input, char **args, t_env *env);
void	list_remove_if(t_env **env, char *str, \
	int (*cmp)(const char *, const char *, size_t));

char	*get_user_input(void);
char	*first_word(char *str);
char	*get_current_pwd(void);
char	*str_remove_q(char *str);
char	*echo_output_delimeter(char *str);
char	*remove_extra_spaces(char *str, t_bool maintain_double_q_spaces);

char	**pipe_split(char *input);
char	**env_list_to_sstrs(t_env *env);

size_t	list_size(t_env *env);
size_t	count_double_quotes(char *str);
size_t	count_single_quotes(char *str);

t_bool	pwd_command(char *input);
t_bool	echo_command(char *input);
t_bool	cd_command(char *input, t_env *env);
t_bool	is_builtin(char *input, t_env *env);
t_bool	env_command(char *input, t_env *env);
t_bool	unset_command(char *input, t_env *env);
t_bool	export_command(char *input, t_env *env);

t_env	*init_env(char **environ);

#endif