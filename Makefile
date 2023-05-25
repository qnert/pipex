CC = CC
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

SRCS = ./pipex_utils/pipex_utils.c ./pipex_utils/pipex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@cd includes && make
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./includes/includes.a

clean:
	@cd includes && make fclean
	@rm -f $(OBJS)
	@cd pipex_utils && rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all