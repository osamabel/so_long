/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:06:00 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/03 20:54:42 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "get_next_line.h"
#include <stdio.h>
#define WIDHT_IMG 99
#define HIGHT_IMG 99

typedef struct s_data{
	void 	*mlx_ptr;
	void 	*mlx_win;
	void 	*img;
	char 	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	widht;
	int 	hight;
	int		x;
	int		y;
	int		X;
	int		Y;
}	t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	backgroud_3d3550(t_data *info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < info->widht)
	{
		y = 0;
		while (y < info->hight)
		{
			my_mlx_pixel_put(info, x, y, 0x3d3550);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(info->mlx_ptr ,info->mlx_win, info->img, 0, 0);
}


void	read_map(int fd, t_data *info, char **map)
{
	char	*buf;

	info->hight = 0;
	buf = get_next_line(fd);
	info->widht = ft_strlen(buf) - 1;
	while (buf)
	{
		info->hight++;
		ft_strjoin1(map, &buf);
		buf = get_next_line(fd);
	}
	info->X = info->widht;
	info->Y = info->hight;
}

char	*verify_map(int fd, t_data *info, char **map)
{
	int	person;

	person = 0;
	info->x = 0;
	info->y = 0;
	read_map(fd, info, map);
	while (info->y <= info->hight)
	{
		while (*(*map + info->x) != '\n' && *(*map + info->x))
		{
			if ((info->y == 0 || info->y == info->hight) && *(*map + info->x) != '1')
				return (0);
			if (info->y > 0 && info->y <= info->hight)
			{
				if (*(*map + info->x - 1) == '\n' && *(*map + info->x) != '1')
					return (0);
				if (*(*map + info->x - 1) == '\n' && *(*map + info->x - 2) != '1')
					return (0);
				if (*(*map + info->x) != '1' && *(*map + info->x) != '0' && *(*map + info->x)\
				 != 'c' && *(*map + info->x) != 'p' && *(*map + info->x) != 'e')
					return (0);
			}
			info->x++;
			if (*(*map + info->x) == 'p')
				person++;
			if (person > 1)
				return (0);
		}
		info->x++;
		info->y++;
	}
	return (*map);
}
void	draw_corner_top_left(t_data *info)
{
	info->img = mlx_xpm_file_to_image(info->mlx_ptr,"Textures/corner_top_left.xpm",&info->x,&info->y);
	mlx_put_image_to_window(info->mlx_ptr ,info->mlx_win, info->img, info->x, info->y);
	info->y -= 99;
}

void	draw_corner_top_right(t_data *info)
{
	info->img = mlx_xpm_file_to_image(info->mlx_ptr,"Textures/corner_top_right.xpm",&info->X,&info->Y);
	mlx_put_image_to_window(info->mlx_ptr ,info->mlx_win, info->img, info->x, info->y);
	info->y += 99;
	info->x = 0;
}
void	draw_corner_buttom_right(t_data *info)
{
	info->img = mlx_xpm_file_to_image(info->mlx_ptr,"Textures/corner_buttom_right.xpm",&info->X,&info->Y);
	mlx_put_image_to_window(info->mlx_ptr ,info->mlx_win, info->img, info->x, info->y);
}
void	draw_corner_buttom_left(t_data *info)
{
	info->img = mlx_xpm_file_to_image(info->mlx_ptr,"Textures/corner_buttom_left.xpm",&info->X,&info->Y);
	mlx_put_image_to_window(info->mlx_ptr ,info->mlx_win, info->img, info->x, info->y);
	info->x += 99;
}
void	draw_wall_top(t_data *info)
{
	info->img = mlx_xpm_file_to_image(info->mlx_ptr,"Textures/wall_top.xpm",&info->X,&info->Y);
	mlx_put_image_to_window(info->mlx_ptr ,info->mlx_win, info->img, info->x, info->y);
	info->x += 99;
}
void	draw_wall_buttom(t_data *info)
{
	info->img = mlx_xpm_file_to_image(info->mlx_ptr,"Textures/wall_buttom.xpm",&info->X,&info->Y);
	mlx_put_image_to_window(info->mlx_ptr ,info->mlx_win, info->img, info->x, info->y);
	info->x += 99;
}
void	draw_wall_right(t_data *info)
{
	info->img = mlx_xpm_file_to_image(info->mlx_ptr,"Textures/wall_right.xpm",&info->widht,&info->hight);
	mlx_put_image_to_window(info->mlx_ptr ,info->mlx_win, info->img, info->x, info->y);
	info->y += 99;
}
void	draw_wall_left(t_data *info)
{
	info->img = mlx_xpm_file_to_image(info->mlx_ptr,"Textures/wall_left.xpm",&info->X,&info->Y);
	mlx_put_image_to_window(info->mlx_ptr ,info->mlx_win, info->img, info->x, info->y);
	info->y += 99;
}
void	draw_wall_box(t_data *info)
{
	info->img = mlx_xpm_file_to_image(info->mlx_ptr,"Textures/wall_box.xpm",&info->X,&info->Y);
	mlx_put_image_to_window(info->mlx_ptr ,info->mlx_win, info->img, info->x, info->y);
	info->x += 99;
}


void	draw_map(t_data *info, char *map)
{
	int i;
	int j;

	//draw_corner_top_right(info);
	// while (info->y <= info->hight)
	// {
	// 	while (info->x <= info->widht)
	// 	{
	// 		if (*(map + info->x) == '1')
	// 		{
	// 			if (info->x == 0 && info->y == 0)
	// 				draw_corner_top_left(info);
	// 			if (info->x == info->widht - 99 && info->y == 0)
	// 				draw_corner_top_right(info);
	// 			if (info->x == 0 && info->y == info->hight - 99)
	// 				draw_corner_buttom_left(info);
	// 			if (info->x == info->widht - 99 && info->y == info->hight - 99)
	// 				draw_corner_buttom_right(info);
	// 			if (info->x < info->widht - 99 && info->x > 99)
	// 			{
	// 				if (info->y == 0)
	// 					draw_wall_top(info);
	// 				if (info->y == info->hight - 99)
	// 					draw_wall_buttom(info);
	// 			}
	// 			if (info->y < info->hight - 99 && info->y > 99)
	// 			{
	// 				if (info->x == 0)
	// 					draw_wall_left(info);
	// 				if (info->x == info->hight - 99)
	// 					draw_wall_right(info);
	// 			}
	// 			if (info->x > 99 && info->y > 99)
	// 			{
	// 				if(info->x < info->widht - 99 && info->y < info->hight - 99)
	// 					draw_wall_box(info);
	// 			}
	// 		}
	// 		//info->x++;
	// 	}
	// 	info->y++;
	// }
}


void so_long(char *map_path)
{
	t_data	info;
	char *map;
	int fd;

	map = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror(map_path);
		exit(2);
	}
	read_map(fd, &info, &map);

	if (verify_map(fd, &info, &map))
	{
		info.widht *= WIDHT_IMG;
		info.hight *= HIGHT_IMG;
		info.x = 0;
		info.y = 0;
		info.mlx_ptr = mlx_init();
		info.mlx_win = mlx_new_window(info.mlx_ptr ,info.widht, info.hight, "game");
		info.img = mlx_new_image(info.mlx_ptr, info.widht, info.hight);
		info.addr = mlx_get_data_addr(info.img, &info.bits_per_pixel, &info.line_length, &info.endian);
		backgroud_3d3550(&info);
		draw_map(&info, map);

		mlx_loop(info.mlx_ptr);
	}
	else
		printf("wrong map");
}


int main (int argc, char *argv[])
{
	if (argc == 2)
		so_long(argv[1]);
	return 0;
}
