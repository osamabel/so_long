/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_down.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:46:38 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/12 16:13:00 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	check_box_down(t_data *data)
{
	int	j;

	j = 0;
	update_block(data, 0, SPEED + 55, BLOCK * (data->Y_block - 1));
	while (j < data->box && data->next_block->boolen)
	{
		if (data->next_block->next_y_min == data->box_axes[j].y && \
		data->next_block->next_x_min == data->box_axes[j].x)
			data->next_block->boolen = 0;
		j++;
	}
	j = 0;
	while (j < data->box && data->next_block->boolen)
	{
		if (data->next_block->next_y_min == data->box_axes[j].y && \
		data->next_block->next_x_max == data->box_axes[j].x)
		{
			if (data->next_block->next_x + 55 > data->next_block->next_x_max)
				data->next_block->boolen = 0;
		}
		j++;
	}
	if (data->next_block->boolen)
		data->person_axes[0].y += SPEED;
	return (front_run(data));
}
