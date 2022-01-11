/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_get_axes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:36:06 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/11 13:18:58 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	get_data_axes(t_data *data)
{
	int	x;
	int	y;
	int	c;
	int	e;
	int	b;

	c = 0;
	y = 1;
	e = 0;
	b = 0;
	data->person_axes = malloc(sizeof(t_point));
	data->collectibles_axes = malloc(sizeof(t_point) * data->collectibles);
	data->exit_games_axes = malloc(sizeof(t_point) * data->exit_games);
	data->box_axes = malloc(sizeof(t_point) * data->box);
	while (y < data->Y_block - 1)
	{
		x = 1;
		while (x < data->X_block - 1)
		{
			if (data->map[y][x] == 'P')
			{
				data->person_axes[0].x = x * BLOCK;
				data->person_axes[0].y = y * BLOCK + 19;
			}
			if (data->map[y][x] == 'C')
			{
				data->collectibles_axes[c].x = x * BLOCK;
				data->collectibles_axes[c].y = y * BLOCK;
				c++;
			}
			if (data->map[y][x] == 'E')
			{
				data->exit_games_axes[e].x = x * BLOCK;
				data->exit_games_axes[e].y = y * BLOCK;
				e++;
			}
			if (data->map[y][x] == '1')
			{
				data->box_axes[b].x = x * BLOCK;
				data->box_axes[b].y = y * BLOCK;
				b++;
			}
			x++;
		}
		y++;
	}
}
