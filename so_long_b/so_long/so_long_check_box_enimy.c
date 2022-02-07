/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_box_enimy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:36:44 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/19 23:01:11 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_header.h"

void	left_right_enimy(t_data *data)
{
	if (data->next_block->next_y + 55 > data->next_block->next_y_max)
	{
		ckeck_wall_axes(data, data->next_block->next_x_min, \
		data->next_block->next_y_max);
		ckeck_exit_axes(data, data->next_block->next_x_min, \
		data->next_block->next_y_max);
	}
	if (data->next_block->boolen && !ft_strcmp(data->arrows_enimy, "left"))
		data->enimy_axes[data->z].x -= 4;
	if (data->next_block->boolen && !ft_strcmp(data->arrows_enimy, "right"))
		data->enimy_axes[data->z].x += 4;
}

void	up_down_enimy(t_data *data)
{
	if (data->next_block->next_x + 55 > data->next_block->next_x_max)
	{
		ckeck_wall_axes(data, data->next_block->next_x_max, \
		data->next_block->next_y_min);
		ckeck_exit_axes(data, data->next_block->next_x_max, \
		data->next_block->next_y_min);
	}
	if (data->next_block->boolen && !ft_strcmp(data->arrows_enimy, "up"))
		data->enimy_axes[data->z].y -= 4;
	if (data->next_block->boolen && !ft_strcmp(data->arrows_enimy, "down"))
		data->enimy_axes[data->z].y += 4;
}

void	check_box_enimy(t_data *data)
{
	ckeck_wall_axes(data, data->next_block->next_x_min, \
	data->next_block->next_y_min);
	ckeck_exit_axes(data, data->next_block->next_x_min, \
	data->next_block->next_y_min);
	if ((!ft_strcmp(data->arrows_enimy, "left") || \
	!ft_strcmp(data->arrows_enimy, "right")))
		left_right_enimy(data);
	if ((!ft_strcmp(data->arrows_enimy, "up") || \
	!ft_strcmp(data->arrows_enimy, "down")))
		up_down_enimy(data);
}
