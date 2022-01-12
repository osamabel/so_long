/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:46:03 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/12 19:37:03 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	check_box_left(t_data *data)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	update_block(data, -SPEED, 0, BLOCK);
	while (j < data->box && data->next_block->boolen)
	{
		if (data->next_block->next_x_min == data->box_axes[j].x && \
		data->next_block->next_y_min == data->box_axes[j].y)
			data->next_block->boolen = 0;
		j++;
	}
	j = 0;
	while (j < data->box && data->next_block->boolen)
	{
		if (data->next_block->next_x_min == data->box_axes[j].x && \
		data->next_block->next_y_max == data->box_axes[j].y)
		{
			if (data->next_block->next_y + 55 > data->next_block->next_y_max)
				data->next_block->boolen = 0;
		}
		j++;
	}
	if (data->next_block->boolen)
		data->person_axes[0].x -= SPEED;

	while (k < data->collectibles)
	{
		if (data->next_block->next_x_min == data->collectibles_axes[k].x &&	data->next_block->next_y_min == data->collectibles_axes[k].y)
		{
			
		}
		j++;
	}
	return (run_left(data));
}
