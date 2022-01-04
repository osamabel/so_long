/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:57:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/03 22:15:36 by obelkhad         ###   ########.fr       */
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
	printf("%s\n",map);
	if (map && verify_map(&map, &data))
	{
		printf("Clear map");
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