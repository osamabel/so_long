SRC = so_long_m/animation/animation_frams.c so_long_m/animation/animation_idle_back.c so_long_m/animation/animation_idle_front.c so_long_m/animation/animation_idle_left.c so_long_m/animation/animation_idle_right.c \
	so_long_m/animation/animation_run_back.c so_long_m/animation/animation_run_front.c so_long_m/animation/animation_run_left.c so_long_m/animation/animation_run_right.c \
	\
	so_long_m/draw/draw_background.c so_long_m/draw/draw_corner_buttom_right.c so_long_m/draw/draw_corner_top_right.c so_long_m/draw/draw_exit.c so_long_m/draw/draw_pixel.c so_long_m/draw/draw_wall_buttom.c \
	so_long_m/draw/draw_wall_right.c so_long_m/draw/draw_corner_buttom_left.c so_long_m/draw/draw_corner_top_left.c  so_long_m/draw/draw_coupon.c so_long_m/draw/draw_map.c so_long_m/draw/draw_wall.c \
	so_long_m/draw/draw_wall_left.c so_long_m/draw/draw_wall_top.c \
	\
	so_long_m/get/get_next_line.c so_long_m/get/get_next_line_utils.c \
	\
	so_long_m/so_long/so_long_check_down.c so_long_m/so_long/so_long_check_right.c  so_long_m/so_long/so_long_ckeck_box.c so_long_m/so_long/so_long_get_axes.c so_long_m/so_long/so_long_hook.c \
	so_long_m/so_long/so_long_itoa.c so_long_m/so_long/so_long_update_block.c so_long_m/so_long/so_long_check_left.c so_long_m/so_long/so_long_check_up.c so_long_m/so_long/so_long_ckeck_coupon.c \
	so_long_m/so_long/so_long_get_axes_ulits.c so_long_m/so_long/so_long_init.c so_long_m/so_long/so_long_read_map.c so_long_m/so_long/so_long_verify_map.c

SRCB = so_long_b/animation/animation_frams.c so_long_b/animation/animation_idle_back.c so_long_b/animation/animation_idle_front.c so_long_b/animation/animation_idle_left.c so_long_b/animation/animation_idle_right.c \
	so_long_b/animation/animation_run_back.c so_long_b/animation/animation_run_front.c so_long_b/animation/animation_run_left.c so_long_b/animation/animation_run_right.c \
	\
	so_long_b/draw/draw_background.c so_long_b/draw/draw_corner_buttom_right.c so_long_b/draw/draw_corner_top_right.c so_long_b/draw/draw_exit.c so_long_b/draw/draw_pixel.c so_long_b/draw/draw_wall_buttom.c \
	so_long_b/draw/draw_wall_right.c so_long_b/draw/draw_corner_buttom_left.c so_long_b/draw/draw_corner_top_left.c  so_long_b/draw/draw_coupon.c so_long_b/draw/draw_map.c so_long_b/draw/draw_wall.c \
	so_long_b/draw/draw_wall_left.c so_long_b/draw/draw_wall_top.c so_long_b/draw/draw_enimy.c \
	\
	so_long_b/get/get_next_line.c so_long_b/get/get_next_line_utils.c \
	\
	so_long_b/so_long/so_long_check_box_enimy.c so_long_b/so_long/so_long_check_down.c so_long_b/so_long/so_long_check_right.c  so_long_b/so_long/so_long_ckeck_box.c so_long_b/so_long/so_long_get_axes.c so_long_b/so_long/so_long_hook.c \
	so_long_b/so_long/so_long_itoa.c so_long_b/so_long/so_long_update_block.c so_long_b/so_long/so_long_check_left.c so_long_b/so_long/so_long_check_up.c so_long_b/so_long/so_long_ckeck_coupon.c \
	so_long_b/so_long/so_long_get_axes_ulits.c so_long_b/so_long/so_long_init.c so_long_b/so_long/so_long_read_map.c so_long_b/so_long/so_long_verify_map.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ) so_long_header.h
	gcc $(CFLAGS) long.c -o $(NAME) $(OBJ) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

.c.o: so_long_header.h
	gcc $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

bonus:$(OBJB)
	gcc $(CFLAGS) long.c -o $(NAME) $(OBJB) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

re: fclean all
