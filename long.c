/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:57:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/12 19:34:07 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	so_long(char	*map_path)
{
	int		fd;
	char	*map;
	t_data	data;

// iniitial;
	data.person = 0;
	data.collectibles = 0;
	data.exit_games = 0;
	data.box = 0;
	data.x = 0;
	data.y = 0;
	data.i = 0;
	data.j = 0;

	int i;
	i = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror(map_path);
		exit(2);
	}
	map = read_map(fd, &data);
	data.map = ft_split(map, '\n');
	if (map && verify_map(&data))
	{
		initial_connection(&data);
		backgroud_3d3550(&data);
		// draw_grid(&data);
		//front_idle(&data);
		draw_map(&data);
		mlx_hook(data.mlx_win, 2, 0, key_hook, &data);
		mlx_hook(data.mlx_win, 3, 0, key_hook_stop, &data);
		printf("data.prsoX >> %i\n", data.person_axes[0].y);
		printf("data.box >> %i\n", data.box);
		while (i < data.collectibles)
		{
			printf("%i -> = %i , %i\n", i,data.collectibles_axes[i].x, data.collectibles_axes[i].y);
			i++;
		}


		mlx_loop(data.mlx_ptr);
	}
	else
		printf("Wrong Map");
	free(map);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		so_long(argv[1]);
	else
		printf("missing One argument");
	return (0);
}