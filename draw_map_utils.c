/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:20:27 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/04 18:50:10 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	draw_map_wall(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	draw_corner_top_left(data, 0, 0);
	draw_corner_top_right(data, data->widht - BLOCK, 0);
	draw_corner_buttom_left(data, 0, data->height - BLOCK);
	draw_corner_buttom_right(data, data->widht - BLOCK, data->height - BLOCK);
	while (y <= data->height)
	{
		x = 0;
		while (x <= data->widht)
		{
			if (y == 0 && x >= BLOCK && x < data->widht - BLOCK)
				draw_wall_top(data, x, y);
			if (y == data->height - BLOCK && x >= BLOCK && x < data->widht - BLOCK)
				draw_wall_buttom(data, x, y);
			if (y >= BLOCK && y < data->height - BLOCK)
			{
				if (x == 0)
					draw_wall_left(data, x, y);
				if (x == data->widht - BLOCK)
					draw_wall_right(data, x, y);
			}
			x += BLOCK;
		}
		y += BLOCK;
	}
}

void	draw_map(t_data *data, char *map)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	draw_map_wall(data);
	while (y <= data->height)
	{
		x = 0;
		while (x <= data->widht)
		{
			if (x >= BLOCK && x < data->widht - BLOCK && y >= BLOCK && y < data->height - BLOCK)
			{
				if (map[i] == '1')
					draw_wall_box(data, x, y);
			}
			i++;
			x += BLOCK;
		}
		y += BLOCK;
	}
}

void	backgroud_3d3550(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < data->widht)
	{
		y = 0;
		while (y < data->height)
		{
			my_mlx_pixel_put(data, x, y, 0x3d3550);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr ,data->mlx_win, data->img, 0, 0);
}