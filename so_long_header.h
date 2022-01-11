/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:24:39 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/11 16:03:58 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_HEADER_H
# define SO_LONG_HEADER_H


# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>
# include<unistd.h>
# include<mlx.h>

#define S1 "saitama1"
#define S2 "saitama2"
#define S "saitama"
#define BUFFER_SIZE 30
#define BLOCK 74
#define FRAMS 10

typedef struct s_point{
	int		x;
	int		y;
}	t_point;

typedef struct s_data{
	void 	*mlx_ptr;
	void 	*mlx_win;
	void 	*img;
	char 	*addr;
	char	**map;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	widht;
	int 	height;
	int		X_block;
	int		Y_block;
	int		x;
	int		y;
	int		i;
	int		j;
	int		person;
	int		collectibles;
	int		exit_games;
	int		box;
	t_point	*person_axes;
	t_point	*collectibles_axes;
	t_point	*exit_games_axes;
	t_point	*box_axes;
}	t_data;

//GET NEXT LINE
char	*get_next_line(int fd);
size_t	ft_strlen(const char	*str);
char	*read_and_store(int fd, char **line, char **lost);
size_t	check_end_of_line(char	*buf);
void	ft_strsplit(char *holder, char **first, char **secend, size_t check);
void	creat_line(char **line, char **lost, char **buffer);
char	*ft_strjoin(char **line, char **str);
void	ft_strncpy(char *dest, char *src, size_t len);

//INITIAL CONNETION
void	initial_connection(t_data *data);

//VERIFY MAP
int		verify_map(t_data *data);
int		verify_map_wall(t_data *data, int x, int y);

//READ MAP
char	*read_map(int fd, t_data *data);
int		spliting_problem(char **result, int n);
int		wcount(char const *s, char c);
char	**str_to_split(char **result, char *str, char c);
char	**ft_split(char *s, char c);


//DRAW MAP
void	draw_map(t_data *data);
void	draw_wall(t_data *data);
void	backgroud_3d3550(t_data *data);
void	backgroud_ffffff(t_data *data);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		draw_wall_box(t_data *data);
void	draw_corner_top_left(t_data *data, int x, int y);
void	draw_corner_top_right(t_data *data, int x, int y);
void	draw_corner_buttom_right(t_data *data, int x, int y);
void	draw_corner_buttom_left(t_data *data, int x, int y);
void	draw_wall_top(t_data *data, int x, int y);
void	draw_wall_buttom(t_data *data, int x, int y);
void	draw_wall_right(t_data *data, int x, int y);
void	draw_wall_left(t_data *data, int x, int y);
void	draw_corners(t_data *data);
void	draw_borders(t_data *data, int x, int y);

//ANIMATION SAITAMA
void	draw_saitama_right_idle(t_data *data, int x, int y);
int		key_hook(int keycode, t_data *data);
int		run_right(t_data *info);
int		run_right_place(t_data *info);
int		run_left(t_data *info);
int		run_left_place(t_data *info);
int		idle_right(t_data *data);
int		idle_left(t_data *data);
int		key_hook_loop(t_data *data);
int		key_hook_stop(int keycode, t_data *data);
int 	front_idle(t_data *data);
int 	back_idle(t_data *data);
int		front_run(t_data *data);
int		front_run_place(t_data *data);
int		back_run(t_data *data);
int		back_run_place(t_data *data);
void	draw_position(t_data *data, int *i, int *frams, char *path);

// GRID
void	draw_grid(t_data *data);

//DRAW ITEMS
int	draw_items(t_data *data, char c, int x, int y);

//DRAW COUPON
int		draw_coupon(t_data *data);

int	key_hook_coupon(int keycode, t_data *data);


void	get_data_axes(t_data *data);
int		draw_exit(t_data *data);
int		loop_items(t_data *data);
void	block_3d3550(t_data *data);
int	key_hook1(int keycode, t_data *data);
#endif
