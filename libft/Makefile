NAME =	libft.a

SRC =	ft_bzero.c		ft_memccpy.c	ft_memcpy.c		ft_memmove.c\
		ft_memset.c		ft_tolower.c	ft_toupper.c	ft_isprint.c\
		ft_isascii.c	ft_isalnum.c	ft_isdigit.c	ft_isalpha.c\
		ft_atoi.c		ft_strncmp.c	ft_strlen.c		ft_memchr.c\
		ft_memcmp.c		ft_strchr.c		ft_strrchr.c	ft_calloc.c\
		ft_strdup.c		ft_strlcpy.c	ft_strlcat.c	ft_strnstr.c\
		ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_split.c\
		ft_itoa.c		ft_strmapi.c	ft_putchar_fd.c	ft_putstr_fd.c\
		ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr.c		ft_putchar.c\
		ft_strnew.c		ft_strncpy.c	ft_strcmp.c		ft_strcpy.c\
		ft_putnchar.c

SRC_B = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c

FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
HEADER = libft.h

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $@ $^

%.o: %.c 
	gcc $(FLAGS) -c $<

clean :
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@rm -f $(NAME)

re : fclean all

bonus : $(OBJ) $(OBJ_B) $(HEADER)
	ar rcs $(NAME) $^

.PHONY : all clean fclean re bonus
