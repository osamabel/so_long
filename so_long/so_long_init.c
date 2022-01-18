/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:24:09 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/18 17:57:19 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_header.h"

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

void	initial_struct(t_data *data)
{
	data->person = 0;
	data->enimy = 0;
	data->collectibles = 0;
	data->exit_games = 0;
	data->box = 0;
	data->x = 0;
	data->y = 0;
	data->z = 0;
	data->arrows = ft_strdup("idle_right");
}
