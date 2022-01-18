/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:01:36 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/18 19:37:01 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_header.h"

int	draw_wall_box(t_data *data)
{
	int	j;

	j = 0;
	data->img = mlx_xpm_file_to_image(data->mlx_ptr, "image/wall_box.xpm", \
	&data->x, &data->y);
	while (j < data->box)
	{
		if (data->box_axes[j].y > 0 && data->box_axes[j].y < BLOCK * \
		(data->Y_block - 1) && data->box_axes[j].x > 0 && data->box_axes[j].x \
		< BLOCK * (data->X_block - 1))
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, \
			data->box_axes[j].x, data->box_axes[j].y);
		j++;
	}
	return (0);
}

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
	draw_wall_box(data);
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
