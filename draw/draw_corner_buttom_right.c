/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_corner_buttom_right.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:38:59 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/10 18:53:50 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	draw_corner_buttom_right(t_data *data, int x, int y)
{
	char	*path;

	path = "image2/corner_buttom_right.xpm";
	data->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->x, &data->y);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, x, y);
}
