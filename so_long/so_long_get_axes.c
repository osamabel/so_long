/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_get_axes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:36:06 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/17 22:25:59 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_header.h"

void	items_allocation(t_data *data)
{
	data->taken_coll = calloc(sizeof(int), data->collectibles);
	data->person_axes = calloc(sizeof(t_point), 1);
	data->next_block = calloc(sizeof(t_next_block), 1);
	data->collectibles_axes = calloc(sizeof(t_point), data->collectibles);
	data->collectibles_taken_axes = calloc(sizeof(t_point), data->collectibles);
	data->exit_games_axes = calloc(sizeof(t_point), data->exit_games);
	data->box_axes = calloc(sizeof(t_point), data->box);
	data->enimy_axes = calloc(sizeof(t_point), data->enimy);
	if (!data->taken_coll || !data->person_axes || !data->collectibles_axes || !data->next_block || !data->collectibles_taken_axes || !data->exit_games_axes || !data->box_axes || !data->enimy_axes)
	{
		write(2,"malloc error\n", 13);
		exit(5);
	}
}

void	get_data_axes(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	items_allocation(data);
	while (y < data->Y_block)
	{
		x = 0;
		while (x < data->X_block)
		{
			if (data->map[y][x] == 'P')
				peson_xy(data, x, y);
			if (data->map[y][x] == 'C')
				collectibes_xy(data, x, y);
			if (data->map[y][x] == 'E')
				exit_xy(data, x, y);
			if (data->map[y][x] == '1')
				box_xy(data, x, y);
			if (data->map[y][x] == 'X')
				enimy_xy(data, x, y);
			x++;
		}
		y++;
	}
}
