/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_buttom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:40:10 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/15 11:47:12 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_header.h"

void	draw_wall_buttom(t_data *data, int x, int y)
{
	char	*path;

	path = "image/wall_buttom.xpm";
	data->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->x, &data->y);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, x, y);
}
