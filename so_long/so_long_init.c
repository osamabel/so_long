/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:24:09 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/12 16:34:56 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	initial_connection(t_data *data)
{
	data->widht = BLOCK * data->X_block;
	data->height = BLOCK * data->Y_block;
	data->x = 0;
	data->y = 0;
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->widht, \
	data->height, "game");
	data->img = mlx_new_image(data->mlx_ptr, data->widht, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
}
