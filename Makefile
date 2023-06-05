CC = CC
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

SRCS = ./pipex_utils/utils.c ./pipex_utils/forks.c ./pipex_utils/pipex.c ./pipex_utils/get_check_and_awk.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@cd includes && make
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./includes/includes.a

clean:
	@cd includes && make fclean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all