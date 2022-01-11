/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_verify_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:03:46 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/10 14:31:29 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	verify_map_wall(t_data *data, int x, int y)
{
	if ((y == 0 || y == data->Y_block - 1) && data->map[y][x] != '1')
			return (0);
	if (y > 0 && y < data->Y_block - 1)
	{
		if ((x == 0 || x == data->X_block - 1) && data->map[y][x] != '1')
			return (0);
		if (x > 0 && x < data->X_block - 1)
		{
			if (data->map[y][x] != '1' && data->map[y][x] != '0' && data->map[y][x]\
				!= 'C' && data->map[y][x] != 'P' && data->map[y][x] != 'E')
				return (0);
			if (data->map[y][x] == 'P')
				data->person++;
			if (data->map[y][x] == 'C')
				data->collectibles++;
			if (data->map[y][x] == 'E')
				data->exit_games++;
			if (data->map[y][x] == '1')
				data->box++;
		}
	}
	return (1);
}

int	verify_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (!verify_map_wall(data, x, y))
				return (0);
			x++;
		}
		y++;
	}
	if (data->person > 1 || data->collectibles == 0 || data->exit_games == 0)
		return (0);
	return (1);
}
