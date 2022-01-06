SRC= so_long.c get_next_line.c get_next_line_utils.c so_long_utils.c draw_map_utils.c so_long_draw.c so_long_hook.c
SRC1= get_next_line.c get_next_line_utils.c so_long_utils.c draw_map_utils.c so_long_draw.c so_long_hook.c
OBJ=$(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
NAME=so_long.out
MLX=libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX) so_long_header.h
	gcc $(CFLAGS) so_long.c -o $(NAME) $(SRC1) -lmlx -framework OpenGL -framework AppKit

.c.o: so_long_header.h
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


#1111111111111111 \n 1C000011C0C11111 \n 11111011011110E1 \n 1111001100111011 \n 1111000000000011 \n 10000111110110C1 \n 1P00C111110C1111 \n 1111111111111111
