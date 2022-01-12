/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:20:27 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/12 19:31:48 by obelkhad         ###   ########.fr       */
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
	mlx_loop_hook(data->mlx_ptr, loop_items, data);
}
