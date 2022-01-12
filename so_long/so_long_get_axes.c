/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_get_axes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:36:06 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/12 19:17:09 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	items_allocation(t_data *data)
{
	data->person_axes = malloc(sizeof(t_point));
	data->collectibles_axes = malloc(sizeof(t_point) * data->collectibles);
	data->collectibles_taken_axes = malloc(sizeof(t_point) * data->collectibles);
	data->exit_games_axes = malloc(sizeof(t_point) * data->exit_games);
	data->box_axes = malloc(sizeof(t_point) * data->box);
}

void	get_data_axes(t_data *data)
{
	int	x;
	int	y;

	y = 1;
	items_allocation(data);
	while (y < data->Y_block - 1)
	{
		x = 1;
		while (x < data->X_block - 1)
		{
			if (data->map[y][x] == 'P')
				peson_xy(data, x, y);
			if (data->map[y][x] == 'C')
				collectibes_xy(data, x, y);
			if (data->map[y][x] == 'E')
				exit_xy(data, x, y);
			if (data->map[y][x] == '1')
				box_xy(data, x, y);
			x++;
		}
		y++;
	}
}
