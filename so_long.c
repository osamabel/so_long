/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:57:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/06 16:00:17 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

char	*read_map(int fd, t_data *data)
{
	char	*buf;
	char	*map;
	int		widht;

	data->height = 0;
	map = NULL;
	buf = get_next_line(fd);
	data->widht = check_end_of_line(buf);
	while (buf)
	{
		data->height++;
		ft_strjoin(&map, &buf);
		buf = get_next_line(fd);
		widht = check_end_of_line(buf);
		if (data->widht != widht && buf)
			return (0);
	}
	data->X_block = data->widht;
	data->Y_block = data->height;
	return (map);
}

void	so_long(char	*map_path)
{
	int		fd;
	char	*map;
	t_data	data;

	 fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror(map_path);
		exit(2);
	}
	map = read_map(fd, &data);
	if (map && verify_map(&map, &data))
	{
		data.widht *= BLOCK;
		data.height *= BLOCK;
		data.x = 0;
		data.y = 0;
		data.mlx_ptr = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx_ptr ,data.widht, data.height, "game");
		data.img = mlx_new_image(data.mlx_ptr, data.widht, data.height);
		data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
		backgroud_3d3550(&data);
		//GRID 99
		// {
		// 	int x = 0;
		// 	int y = 0;
		// 	while(x <= data.widht)
		// 	{
		// 		y = 0;
		// 		while (y <= data.height)
		// 		{
		// 			if (x % 74 == 0 || y % 74 == 0)
		// 			{
		// 				my_mlx_pixel_put(&data, x, y, 0xffffff);
		// 			}
		// 			y++;
		// 		}
		// 		x++;
		// 	}
		// 	mlx_put_image_to_window(data.mlx_ptr ,data.mlx_win, data.img, 0, 0);
		// }
		mlx_hook(data.mlx_win, 2, 0, key_hook, &data);
		// mlx_hook(data.mlx_win, 2, 0, key_hook, &data);
		//draw_map(&data, map);
		mlx_loop(data.mlx_ptr);
		free(map);
	}
	else
		printf("Wrong Map");
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		so_long(argv[1]);
	else
		printf("missing One argument");
	return (0);
}