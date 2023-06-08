CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = pipex

SRCS = ./pipex_utils/utils.c ./pipex_utils/forks.c ./pipex_utils/pipex.c ./pipex_utils/get_check_and_awk.c

OBJS = $(SRCS:.c=.o)

MANDATORY_SRC = ./pipex_utils/mandatory_main.c

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

BONUS_SRC = ./pipex_utils/bonus_main.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MANDATORY_OBJ)
	@rm -f $(BONUS_OBJ)
	@cd includes && make
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MANDATORY_OBJ) ./includes/includes.a

clean:
	@cd includes && make fclean
	@rm -f $(OBJS)
	@rm -f $(MANDATORY_OBJ)
	@rm -f $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(BONUS_OBJ)
	@rm -f $(MANDATORY_OBJ)
	@cd includes && make
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(BONUS_OBJ)  ./includes/includes.a