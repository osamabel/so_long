/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:57:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/07 18:26:52 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

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
		initial_connection(&data);
		backgroud_3d3550(&data);
		//darw_grid(&data);
		mlx_hook(data.mlx_win, 2, 0, key_hook, &data);
		mlx_hook(data.mlx_win, 3, 0, key_hook_stop, &data);
		draw_map(&data, map);
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