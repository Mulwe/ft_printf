NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c

SRCS =./libft/ft*.c ./src/ft*.c

OBJECTS =ft*.o

LIB_PATH = ./libft

INCLUDES =./includes

all:$(NAME)

$(NAME):
	@make re -C $(LIB_PATH)
	@ gcc -g3 $(FLAGS) $(SRCS) -I$(INCLUDES)
	@ar rcs $(NAME) $(OBJECTS) $(LIB_PATH)/*.o

clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C $(LIB_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

bonus: re

.PHONY:	all clean fclean re
