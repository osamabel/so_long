/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_verify_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:03:46 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/07 18:59:06 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	verify_map_body(t_data *data, char **map, int x, int y)
{
	if (y > 0 && y < data->Y_block)
	{
		if (*(*map + x - 1) == '\n' && *(*map + x) != '1')
			return (0);
		if (*(*map + x + 1) == '\n' && *(*map + x) != '1')
			return (0);
		if (*(*map + x) != '1' && *(*map + x) != '0' && *(*map + x) != 'C' \
		&& *(*map + x) != 'P' && *(*map + x) != 'E')
			return (0);
	}
	return (1);
}

int	check_pce(t_data *data, char c, int y)
{
	static int	person;
	static int	collectibale;
	static int	exit_game;

	if (c == 'P')
		person++;
	if (c == 'C')
		collectibale++;
	if (c == 'E')
		exit_game++;
	if (person > 1)
		return (0);
	if (collectibale == 0 && y == data->Y_block - 1)
		return (0);
	if (exit_game == 0 && y == data->Y_block - 1)
		return (0);
	return (1);
}

int	verify_map(char	**map, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->Y_block)
	{
		while (*(*map + x) != '\n' && *(*map + x))
		{
			if ((y == 0 || y == data->Y_block - 1) && *(*map + x) != '1')
				return (0);
			if (!verify_map_body(data, map, x, y))
				return (0);
			x++;
			if (!check_pce(data, *(*map + x), y))
				return (0);
		}
		x++;
		y++;
	}
	return (1);
}
