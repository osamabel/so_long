/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:00:56 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/08 19:08:10 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	draw_items(t_data *data, char c, int x, int y)
{
	if (c == '1')
		draw_wall_box(data, x, y);
	if (c == 'C')
	{
		data->i = 296;
		data->j = 74;
		mlx_loop_hook(data->mlx_ptr, draw_coupon, data);
	}
	if (c == 'P')
	{
		data->i = 148;
		data->j = 222;
		mlx_loop_hook(data->mlx_ptr, idle_right, data);
	}
	if (c == '0')
	{
		data->img = mlx_xpm_file_to_image(data->mlx_ptr, "coupon/test.xpm", &data->x, &data->y);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 74, 74);
	}
	//mlx_loop_hook(data->mlx_ptr, draw_exit, data);
	return (0);
}