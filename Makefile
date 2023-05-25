CC = CC
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
NAME_BON = pipex_bonus

SRCS = ./pipex_utils/utils.c ./pipex_utils/forks.c

MAND = ./pipex_utils/pipex.c

BON = ./pipex_utils/pipex_bonus.c

OBJS = $(SRCS:.c=.o)

MAND_OBJ = $(MAND:.c=.o)

BON_OBJ = $(BON:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MAND_OBJ)
	@cd includes && make
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MAND_OBJ) ./includes/includes.a

clean:
	@cd includes && make fclean
	@rm -f $(OBJS)
	@cd pipex_utils && rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BON)

re: fclean all

bonus: $(NAME_BON)

$(NAME_BON): $(OBJS) $(BON_OBJ)
	@cd includes && make
	@$(CC) $(CFLAGS) -o $(NAME_BON) $(OBJS) $(BON_OBJ) ./includes/includes.a