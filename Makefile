FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
HEADER = ft_printf.h
SRC = ft_printf.c print_upxsc.c print_di.c itoa_b.c helpers.c string_utils.c list_utils.c utils.c
OBJ = $(SRC:.c=.o)
all: $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean:	clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
