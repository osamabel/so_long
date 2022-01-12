/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:46:34 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/12 16:14:53 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	check_box_up(t_data *data)
{
	int	j;

	j = 0;
	update_block(data, 0, -SPEED, BLOCK);
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
		data->person_axes[0].y -= SPEED;
	return (back_run(data));
}
