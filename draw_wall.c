/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:01:36 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/07 16:18:36 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	draw_corners(t_data *data)
{
	draw_corner_top_left(data, 0, 0);
	draw_corner_top_right(data, data->widht - BLOCK, 0);
	draw_corner_buttom_left(data, 0, data->height - BLOCK);
	draw_corner_buttom_right(data, data->widht - BLOCK, data->height - BLOCK);
}

void	draw_borders(t_data *data, int x, int y)
{
	if (y == 0 && x >= BLOCK && x < data->widht - BLOCK)
		draw_wall_top(data, x, y);
	if (y == data->height - BLOCK)
	{
		if (x >= BLOCK && x < data->widht - BLOCK)
			draw_wall_buttom(data, x, y);
	}
	if (y >= BLOCK && y < data->height - BLOCK)
	{
		if (x == 0)
			draw_wall_left(data, x, y);
		if (x == data->widht - BLOCK)
			draw_wall_right(data, x, y);
	}
}

void	draw_wall(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	draw_corners(data);
	while (y <= data->height)
	{
		x = 0;
		while (x <= data->widht)
		{
			draw_borders(data, x, y);
			x += BLOCK;
		}
		y += BLOCK;
	}
}
