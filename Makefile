SRC = long.c $(wildcard get/*.c) $(wildcard so_long/*.c) $(wildcard draw/*.c) $(wildcard animation/*.c)
SRC1 = $(wildcard get/*c) $(wildcard so_long/*.c) $(wildcard draw/*.c) $(wildcard animation/*.c)
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
NAME = long
# MLX = libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX) so_long_header.h
	gcc $(CFLAGS) -I . long.c -o $(NAME) $(SRC1) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

.c.o: so_long_header.h
	gcc $(CFLAGS) -I . -o $@ -c $<

# $(MLX):
# 	make -C minilibx
# 	make clean -C minilibx
# 	mv minilibx/libmlx.a .

clean:
	rm -f $(NAME) $(OBJ) *~

fclean: clean
	rm -f $(NAME)
#	rm -f $(MLX)

re: fclean all