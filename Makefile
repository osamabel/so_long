SRC= so_long.c get_next_line.c get_next_line_utils.c so_long_utils.c
SRC1= get_next_line.c get_next_line_utils.c so_long_utils.c
OBJ=$(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
NAME=so_long.out
MLX=libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	gcc $(CFLAGS) so_long.c -o $(NAME) $(SRC1) -lmlx -framework OpenGL -framework AppKit

.c.o:
	gcc $(CFLAGS) -o $@ -c $<

$(MLX):
	make -C minilibx
	make clean -C minilibx
	mv minilibx/libmlx.a .

clean:
	rm -f $(NAME) $(OBJ) *~

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX)

re: fclean all
