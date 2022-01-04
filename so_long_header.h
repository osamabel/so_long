/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:24:39 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/03 21:27:19 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_HEADER_H
# define SO_LONG_HEADER_H

# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>
# include<unistd.h>
#define BUFFER_SIZE 42

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

char	*get_next_line(int fd);
size_t	ft_strlen(const char	*str);
char	*read_and_store(int fd, char **line, char **lost);
size_t	check_end_of_line(char	*buf);
void	ft_strsplit(char *holder, char **first, char **secend, size_t check);
void	creat_line(char **line, char **lost, char **buffer);
char	*ft_strjoin(char **line, char **str);
void	ft_strncpy(char *dest, char *src, size_t len);
int		verify_map(char	**map, t_data *data);
#endif
