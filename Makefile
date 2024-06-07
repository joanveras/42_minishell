NAME = minishell.a

SRCS =	$(wildcard libft/*.c) \
		$(wildcard src/*.c) \
		$(wildcard src/utils/*.c) \
		$(wildcard src/utils/readline_custom/*.c) \
		$(wildcard src/redirects/*.c) \
		$(wildcard src/executor/*.c) \
		$(wildcard src/builtins/*.c) \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

# Colors and Effects ##################################################

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET_COLOR = \033[0m

# Rules ###############################################################

$(NAME): $(OBJS)
	@echo -e "$(YELLOW)Creating archive $(NAME)$(RESET_COLOR)"
	@ar rc $(NAME) $(OBJS) >/dev/null 2>&1
	@echo -e "$(YELLOW)Compiling minishell$(RESET_COLOR)"
	@$(CC) src/main.c $(CFLAGS) $(NAME) -o minishell -lreadline
	@echo -e "$(GREEN)minishell compiled successfully!$(RESET_COLOR)"

all: $(NAME)

%.o: %.c
	@echo -e "$(YELLOW)Compiling $<...$(RESET_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@ >/dev/null 2>&1

clean:
	@echo -e "$(RED)Cleaning object files...$(RESET_COLOR)"
	@$(RM) $(OBJS)

fclean: clean
	@echo -e "$(RED)Cleaning all files...$(RESET_COLOR)"
	@$(RM) $(NAME)
	@$(RM) minishell

re: fclean all

.PHONY: all clean fclean re
