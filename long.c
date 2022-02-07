/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:57:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/20 13:47:06 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	exit_game(t_data *data)
{
	free_game(data);
	write(1, "EXIT _ GAME\n", 12);
	exit(0);
	return (0);
}

int	check_open(char	*map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		printf("%s : No such file or directory\n", map_path);
		exit(2);
	}
	return (fd);
}

void	so_long(char	*map_path)
{
	int		fd;
	t_data	data;

	fd = check_open(map_path);
	initial_struct(&data);
	data.map_str = read_map(fd, &data);
	data.map = ft_split(data.map_str, '\n');
	if (verify_map(&data) && data.map)
	{
		initial_connection(&data);
		get_data_axes(&data);
		backgroud_3d3550(&data);
		draw_wall(&data);
		mlx_loop_hook(data.mlx_ptr, draw_map, &data);
		mlx_hook(data.mlx_win, 2, 0, event_on, &data);
		mlx_hook(data.mlx_win, 3, 0, event_stop, &data);
		mlx_hook(data.mlx_win, 17, 0, exit_game, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		printf("Error\nWrong Map!");
	close(fd);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '.')
			i++;
		if (ft_strcmp(&argv[1][i], ".ber") != 0)
		{
			printf("bad map extontion !!!");
			return (0);
		}
		so_long(argv[1]);
	}
	else
		printf("missing One argument");
	return (0);
}
