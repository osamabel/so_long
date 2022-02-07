/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ckeck_coupon.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:16:35 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/19 15:01:31 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_header.h"

void	get_taken(t_data *data, int j)
{
	data->collectibles_taken_axes[j].x = data->collectibles_axes[j].x;
	data->collectibles_taken_axes[j].y = data->collectibles_axes[j].y;
}

void	check_coupon(t_data *data)
{
	static int	z;
	int			j;

	j = 0;
	while (j < data->collectibles)
	{
		if (data->next_block->next_x_min == data->collectibles_axes[j].x && \
		(data->next_block->next_y_min == data->collectibles_axes[j].y || \
		data->next_block->next_y_max == data->collectibles_axes[j].y))
		{
			if (j == 0)
				get_taken(data, j);
			break ;
		}
		j++;
	}
	if (z != j && j < data->collectibles)
	{
		get_taken(data, j);
		z = j;
	}
}
