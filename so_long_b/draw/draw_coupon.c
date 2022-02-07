/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_coupon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:24:06 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/19 16:21:35 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_header.h"

int	taking(t_data *data, int index)
{
	return (data->collectibles_axes[index].x == \
	data->collectibles_taken_axes[index].x && data->collectibles_axes[index].y \
	== data->collectibles_taken_axes[index].y);
}

void	make_coupon_desippear(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->collectibles)
	{
		if (taking(data, j) && !data->taken_coll[j])
		{
			data->img = mlx_xpm_file_to_image(data->mlx_ptr, "image/bg.xpm", \
			&data->x, &data->y);
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, \
			data->collectibles_axes[j].x, data->collectibles_axes[j].y);
			data->taken_coll[j] = 1;
		}
		else if (!data->taken_coll[j])
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, \
			data->collectibles_axes[j].x, data->collectibles_axes[j].y);
		j++;
	}
}

int	draw_coupon(t_data *data)
{
	static int	i;
	static int	frams;

	if (frams < FRAMS && i == 0)
		draw_position(data, &i, &frams, "image/coupon/coupon1.xpm");
	else if (frams < FRAMS && i == 1)
		draw_position(data, &i, &frams, "image/coupon/coupon2.xpm");
	else if (frams < FRAMS && i == 2)
		draw_position(data, &i, &frams, "image/coupon/coupon3.xpm");
	else if (frams < FRAMS && i == 3)
		draw_position(data, &i, &frams, "image/coupon/coupon4.xpm");
	make_coupon_desippear(data);
	return (0);
}
