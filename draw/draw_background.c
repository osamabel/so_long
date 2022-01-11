/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:58:53 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/10 20:20:05 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	backgroud_3d3550(t_data *data)
{
	int	x;
	int	y;

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
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
}


void	block_3d3550(t_data *data)
{
	int	x;
	int	y;

	x = data->person_axes[0].x;
	y = data->person_axes[0].y;
	while (x < x + BLOCK)
	{
		while (y < y + BLOCK)
		{
			my_mlx_pixel_put(data, x, y, 0xffffff);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
}