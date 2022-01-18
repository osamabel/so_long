/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ckeck_coupon.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:16:35 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/15 20:32:54 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_header.h"

void	check_coupon(t_data *data)
{
	static int	z;
	int	j;

	j = 0;
	while (j < data->collectibles)
	{
		if (data->next_block->next_x_min == data->collectibles_axes[j].x &&	data->next_block->next_y_min == data->collectibles_axes[j].y)
		{
			if (j == 0)
			{
				data->collectibles_taken_axes[j].x = data->collectibles_axes[j].x;
				data->collectibles_taken_axes[j].y = data->collectibles_axes[j].y;
			}
			break;
		}
		j++;
	}
	if (z != j && j < data->collectibles)
	{
		data->collectibles_taken_axes[j].x = data->collectibles_axes[j].x;
		data->collectibles_taken_axes[j].y = data->collectibles_axes[j].y;
		z = j;
	}
}
