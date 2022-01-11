/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_coupon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:24:06 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/11 13:34:13 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	draw_coupon(t_data *data)
{
	static int	i;
	static int	frams;
	int	j;

	j = 0;
	if (frams < FRAMS && i == 0)
		draw_position(data, &i, &frams, "coupon/coupons1.xpm");
	else if (frams < FRAMS && i == 1)
		draw_position(data, &i, &frams, "coupon/coupons2.xpm");
	else if (frams < FRAMS && i == 2)
		draw_position(data, &i, &frams, "coupon/coupons3.xpm");
	else if (frams < FRAMS && i == 3)
		draw_position(data, &i, &frams, "coupon/coupons4.xpm");

	while (j < data->collectibles)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, data->collectibles_axes[j].x, data->collectibles_axes[j].y);
		j++;
	}
	return (0);
}