/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:44:36 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/12 16:09:41 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	draw_exit(t_data *data)
{
	static int	i;
	static int	frams;
	int			j;

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
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, \
		data->collectibles_axes[j].x, data->collectibles_axes[j].y);
		j++;
	}
	return (0);
}
