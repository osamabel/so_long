/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:20:27 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/07 16:12:48 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	draw_map(t_data *data, char *map)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	draw_wall(data);
	while (y <= data->height)
	{
		x = 0;
		while (x <= data->widht)
		{
			if (x >= BLOCK && x < data->widht - BLOCK)
			{
				if (y >= BLOCK && y < data->height - BLOCK)
				{
					if (map[i] == '1')
						draw_wall_box(data, x, y);
				}
			}
			i++;
			x += BLOCK;
		}
		y += BLOCK;
	}
}
