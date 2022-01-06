/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:24:39 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/06 15:57:12 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_HEADER_H
# define SO_LONG_HEADER_H

# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>
# include<unistd.h>
# include "minilibx/mlx.h"

#define BUFFER_SIZE 30
#define BLOCK 74

typedef struct s_data{
	void 	*mlx_ptr;
	void 	*mlx_win;
	void 	*img;
	char 	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	widht;
	int 	height;
	int		X_block;
	int		Y_block;
	int		x;
	int		y;
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

//VERIFY MAP
int		verify_map(char	**map, t_data *data);

//DRAW MAP
void	draw_map(t_data *data, char *map);
void	backgroud_3d3550(t_data *data);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_wall_box(t_data *data, int x, int y);
void	draw_corner_top_left(t_data *data, int x, int y);
void	draw_corner_top_right(t_data *data, int x, int y);
void	draw_corner_buttom_right(t_data *data, int x, int y);
void	draw_corner_buttom_left(t_data *data, int x, int y);
void	draw_wall_top(t_data *data, int x, int y);
void	draw_wall_buttom(t_data *data, int x, int y);
void	draw_wall_right(t_data *data, int x, int y);
void	draw_wall_left(t_data *data, int x, int y);

//DRAM SAITAMA
void	draw_saitama_right_idle(t_data *data, int x, int y);
int		key_hook(int keycode, t_data *data);
int		run_right(t_data *info);
int		run_left(t_data *info);
int		idle_right(t_data *data);
int		idle_left(t_data *data);

#endif
