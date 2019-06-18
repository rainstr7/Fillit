NAME = fillit

SRC = 	main.c \
		solve.c \
		input.c\
		output.c\
		accessories.c

LIB_DIR = ./libft
LIB		= -lft

HEADER = fillit.h

DEL = rm -f
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) $(LIB_DIR)/libft.a
	@gcc $(FLAGS) $(SRC) -L$(LIB_DIR) $(LIB) -o $(NAME)

$(LIB_DIR)/libft.a:
	@make -C $(LIB_DIR)

all: $(NAME)

clean:
	@$(DEL) $(OBJ)
	@make -C $(LIB_DIR) clean
fclean: clean
	@$(DEL) $(NAME)
	@make -C $(LIB_DIR) fclean
re: fclean all