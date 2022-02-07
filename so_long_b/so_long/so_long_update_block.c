/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_update_block.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:01:26 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/19 16:01:45 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_header.h"

void	update_min_max(t_data *data, int speedx, int speedy, int block)
{
	if (!speedx && speedy < 0 && data->next_block->next_y < block)
		data->next_block->boolen = 0;
	if (!speedx && speedy > 0 && data->next_block->next_y > block)
		data->next_block->boolen = 0;
	if (!speedy && speedx < 0 && data->next_block->next_x < block)
		data->next_block->boolen = 0;
	if (!speedy && speedx > 0 && data->next_block->next_x > block)
		data->next_block->boolen = 0;
	if (data->next_block->boolen)
	{
		while (data->next_block->next_x_min % BLOCK != 0)
			data->next_block->next_x_min--;
		while (data->next_block->next_x_max % BLOCK != 0)
			data->next_block->next_x_max++;
		while (data->next_block->next_y_min % BLOCK != 0)
			data->next_block->next_y_min--;
		while (data->next_block->next_y_max % BLOCK != 0)
			data->next_block->next_y_max++;
	}
}

void	update_block(t_data *data, int speedx, int speedy, int block)
{
	data->next_block->boolen = 1;
	data->next_block->next_x = data->person_axes[0].x + speedx;
	data->next_block->next_y = data->person_axes[0].y + speedy;
	data->next_block->next_x_min = data->next_block->next_x;
	data->next_block->next_x_max = data->next_block->next_x;
	data->next_block->next_y_min = data->next_block->next_y;
	data->next_block->next_y_max = data->next_block->next_y;
	update_min_max(data, speedx, speedy, block);
}

void	update_block_enimy(t_data *data, int speedx, int speedy, int block)
{
	data->next_block->boolen = 1;
	data->next_block->next_x = data->enimy_axes[data->z].x + speedx;
	data->next_block->next_y = data->enimy_axes[data->z].y + speedy;
	data->next_block->next_x_min = data->next_block->next_x;
	data->next_block->next_x_max = data->next_block->next_x;
	data->next_block->next_y_min = data->next_block->next_y;
	data->next_block->next_y_max = data->next_block->next_y;
	update_min_max(data, speedx, speedy, block);
}
