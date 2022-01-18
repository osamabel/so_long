SRC = long.c $(wildcard get/*.c) $(wildcard so_long/*.c) $(wildcard draw/*.c) $(wildcard animation/*.c)
SRC1 = $(wildcard get/*c) $(wildcard so_long/*.c) $(wildcard draw/*.c) $(wildcard animation/*.c)
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
NAME = long

all: $(NAME)

$(NAME): $(OBJ) $(MLX) so_long_header.h
	gcc $(CFLAGS) -I . long.c -o $(NAME) $(SRC1) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

.c.o: so_long_header.h
	gcc $(CFLAGS) -I . -o $@ -c $<

clean:
	rm -f $(NAME) $(OBJ) *~

fclean: clean
	rm -f $(NAME)

re: fclean all