/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_coupon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:24:06 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/08 17:46:13 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	draw_coupon(t_data *data)
{
	static int	i;
	static int	frams;
	if (frams < FRAMS && i == 0)
		draw_position(data, &i, &frams, "coupon/coupons1.xpm");
	else if (frams < FRAMS && i == 1)
		draw_position(data, &i, &frams, "coupon/coupons2.xpm");
	else if (frams < FRAMS && i == 2)
		draw_position(data, &i, &frams, "coupon/coupons3.xpm");
	else if (frams < FRAMS && i == 3)
		draw_position(data, &i, &frams, "coupon/coupons4.xpm");

	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, data->i, data->j);
	data->i += BLOCK;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, data->i, data->j);
	data->i += 6 * BLOCK;
	data->j += BLOCK;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, data->i, data->j);
	data->i -= 9 * BLOCK;
	data->j += BLOCK;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, data->i, data->j);
	data->i += 4 * BLOCK;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, data->i, data->j);
	data->i -= 2 * BLOCK;
	data->j -= 2 * BLOCK;
	return (0);
}