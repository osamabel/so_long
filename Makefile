SRC = long.c get*.c so_long*.c draw*.c animation*.c
SRC1 = get*c so_long*.c draw*.c animation*.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
NAME = long
#MLX = libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX) so_long_header.h
	gcc $(CFLAGS) long.c -o $(NAME) $(SRC1) -lmlx -framework OpenGL -framework AppKit

.c.o: so_long_header.h
	gcc $(CFLAGS) -o $@ -c $<

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