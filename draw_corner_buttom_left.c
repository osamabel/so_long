/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_corner_buttom_left.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:39:19 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/07 16:47:29 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	draw_corner_buttom_left(t_data *data, int x, int y)
{
	char	*path;

	path = "image1/corner_buttom_left.xpm";
	data->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->x, &data->y);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, x, y);
}
