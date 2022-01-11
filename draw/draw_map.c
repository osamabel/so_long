/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:20:27 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/11 13:36:39 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	draw_map(t_data *data)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 1;
	x = 1;
	draw_wall(data);
	get_data_axes(data);
	// while (data->map[y])
	// {
	// 	x = 1;
	// 	while (data->map[y][x])
	// 	{
	// 		if (x < data->X_block - 1 && y < data->Y_block - 1 && data->map[y][x] == '1')
	// 			draw_wall_box(data, x * BLOCK, y * BLOCK);
	// 		x++;
	// 	}
	// 	y++;
	// }
	mlx_loop_hook(data->mlx_ptr, loop_items, data);
}
