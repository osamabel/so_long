/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_read_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:19:53 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/07 18:19:56 by obelkhad         ###   ########.fr       */
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