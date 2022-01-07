/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:54:26 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/07 16:51:57 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	draw_grid(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= data->widht)
	{
		y = 0;
		while (y <= data->height)
		{
			if (x % 74 == 0 || y % 74 == 0)
			{
				my_mlx_pixel_put(data, x, y, 0xffffff);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
}
