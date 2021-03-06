/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_verify_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:03:46 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/20 13:33:32 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_header.h"

int	check_items(char c)
{
	return (c != '1' && c != '0' && c != 'C' && c != 'P' && c != 'E');
}

int	verify_map_wall(t_data *data, int x, int y)
{
	if ((y == 0 || y == data->y_block - 1) && data->map[y][x] != '1')
		return (0);
	if (y > 0 && y < data->y_block - 1)
	{
		if ((x == 0 || x == data->x_block - 1) && data->map[y][x] != '1')
			return (0);
		if (x > 0 && x < data->x_block - 1)
		{
			if (check_items(data->map[y][x]))
				return (0);
			if (data->map[y][x] == 'P')
				data->person++;
			if (data->map[y][x] == 'C')
				data->collectibles++;
			if (data->map[y][x] == 'E')
				data->exit_games++;
		}
	}
	return (1);
}

int	verify_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (!data->map)
		return (0);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				data->box++;
			if (!verify_map_wall(data, x, y))
				return (0);
			x++;
		}
		y++;
	}
	if (data->person > 1 || data->person < 1 || data->collectibles == 0 || \
	data->exit_games == 0)
		return (0);
	return (1);
}

void	str_to_split_utils(char *str, int *i, int *j, char c)
{
	while (str[*i] && str[*i] == c)
		(*i)++;
	*j = *i;
	while (str[*j] && str[*j] != c)
		(*j)++;
}
