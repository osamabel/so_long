/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:57:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/18 17:19:22 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	so_long(char	*map_path)
{
	int		fd;
	t_data	data;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror(map_path);
		exit(2);
	}
	initial_struct(&data);
	data.map_str = read_map(fd, &data);
	data.map = ft_split(data.map_str, '\n');
	if (verify_map(&data))
	{
		initial_connection(&data);
		get_data_axes(&data);
		backgroud_3d3550(&data);
		draw_wall(&data);
		mlx_loop_hook(data.mlx_ptr, draw_map, &data);
		mlx_hook(data.mlx_win, 2, 0, event_on, &data);
		mlx_hook(data.mlx_win, 3, 0, event_stop, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		printf("Wrong Map !");
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		so_long(argv[1]);
	else
		printf("missing One argument");
	return (0);
}
