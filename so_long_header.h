/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:24:39 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/18 20:42:00 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_HEADER_H
# define SO_LONG_HEADER_H

# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>
# include<unistd.h>
# include<mlx.h>

#define BUFFER_SIZE 30
#define BLOCK 74
#define FRAMS 13
#define SPEED 4

typedef struct s_point{
	int		x;
	int		y;
}	t_point;

typedef struct s_next_block{
	int		next_x;
	int		next_y;
	int		next_x_min;
	int		next_x_max;
	int		next_y_min;
	int		next_y_max;
	int		boolen;
	int		enimy;
}	t_next_block;

typedef struct s_data{
	void 			*mlx_ptr;
	void 			*mlx_win;
	void 			*img;
	char 			*addr;
	char			*map_str;
	char			**map;
	char			*arrows;
	char			*arrows_enimy;
	t_point			*person_axes;
	t_point			*collectibles_axes;
	t_point			*collectibles_taken_axes;
	t_point			*exit_games_axes;
	t_point			*box_axes;
	t_point			*enimy_axes;
	t_next_block	*next_block;
	int				*taken_coll;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int 			widht;
	int 			height;
	int				X_block;
	int				Y_block;
	int				x;
	int				y;
	int				person;
	int				collectibles;
	int				exit_games;
	int				enimy;
	int				box;
	int				z;
}	t_data;

//	LONG_C
void	so_long(char	*map_path);

//	ANIMATION_C
void	draw_position(t_data *data, int *i, int *frams, char *path);
int		back_idle(t_data *data);
int		front_idle(t_data *data);
int		left_idle(t_data *data);
int		right_idle(t_data *data);
int		back_run(t_data *data);
int		front_run(t_data *data);
int		left_run(t_data *data);
int		right_run(t_data *data);

//	DRAW_C
void	backgroud_3d3550(t_data *data);
void	draw_corner_buttom_left(t_data *data, int x, int y);
void	draw_corner_buttom_right(t_data *data, int x, int y);
void	draw_corner_top_left(t_data *data, int x, int y);
void	draw_corner_top_right(t_data *data, int x, int y);
int		draw_coupon(t_data *data);
int		draw_exit_befor(t_data *data);
int		draw_exit_after(t_data *data);
void	draw_grid(t_data *data);
int		draw_map(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_wall(t_data *data);
void	draw_borders(t_data *data, int x, int y);
void	draw_corners(t_data *data);
int		draw_wall_box(t_data *data);
void	draw_wall_buttom(t_data *data, int x, int y);
void	draw_wall_left(t_data *data, int x, int y);
void	draw_wall_right(t_data *data, int x, int y);
void	draw_wall_top(t_data *data, int x, int y);
int		taking(t_data *data, int index);
int		check_tacking_coll(t_data *data);
int		draw_enimy(t_data *data);
void	draw_position_enimy(t_data *data, int *i, int *frams, char *path);
void	tracking_person(t_data *data);

//	GET_C
char	*get_next_line(int fd);
char	*read_and_store(int fd, char **line, char **lost);
void	ft_strsplit(char *holder, char **first, char **secend, size_t check);
void	creat_line(char **line, char **lost, char **buffer);
char	*ft_strdup(char	*str);
void	ft_strncpy(char *dest, char *src, size_t len);
char	*ft_strjoin(char **line, char **str);
size_t	ft_strlen(const char	*str);
size_t	check_end_of_line(char	*buf);
void	malloc_error(void);

//	SO_LONG_C
int		check_box_down(t_data *data);
int		check_box_left(t_data *data);
int		check_box_right(t_data *data);
int		check_box_up(t_data *data);
void	get_data_axes(t_data *data);
void	items_allocation(t_data *data);
void	peson_xy(t_data *data, int x, int y);
void	collectibes_xy(t_data *data, int x, int y);
void	exit_xy(t_data *data, int x, int y);
void	box_xy(t_data *data, int x, int y);
void	enimy_xy(t_data *data, int x, int y);
int		ft_strcmp(char *str1, char *str2);
int		event_on(int keycode, t_data *data);
int		event_stop(int keycode, t_data *data);
int		key_hook(t_data *data);
void	initial_connection(t_data *data);
void	initial_struct(t_data *data);
char	*read_map(int fd, t_data *data);
int		wcount(char const *s, char c);
int		spliting_problem(char **result, int n);
char	**str_to_split(char **result, char *str, char c);
char	**ft_split(char *s, char c);
void	str_to_split_utils(char *str, int *i, int *j, char c);
void	update_block(t_data *data, int speedx, int speedy, int block);
int		verify_map(t_data *data);
int		verify_map_wall(t_data *data, int x, int y);
int		check_items(char c);
void	check_box(t_data *data);
void	check_coupon(t_data *data);
void	update_block_enimy(t_data *data, int speedx, int speedy, int block);
void	check_box_enimy(t_data *data);
void	up_down_enimy(t_data *data);
void	left_right_enimy(t_data *data);
void	ckeck_wall_axes(t_data *data, int X, int Y);
void	ckeck_exit_axes(t_data *data, int X, int Y);
void	ckeck_wall_axes(t_data *data, int X, int Y);
void	free_game(t_data *data);
char	*ft_itoa(int n);

#endif
