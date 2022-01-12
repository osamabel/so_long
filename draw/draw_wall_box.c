/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_box.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:37:13 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/12 16:11:12 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	draw_wall_box(t_data *data)
{
	static int	i;
	static int	frams;
	int			j;

	j = 0;
	if (frams < FRAMS && i == 0)
		draw_position(data, &i, &frams, "image2/wall_box.xpm");
	else if (frams < FRAMS && i == 1)
		draw_position(data, &i, &frams, "image2/wall_box.xpm");
	else if (frams < FRAMS && i == 2)
		draw_position(data, &i, &frams, "image2/wall_box.xpm");
	else if (frams < FRAMS && i == 3)
		draw_position(data, &i, &frams, "image2/wall_box.xpm");
	while (j < data->box)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, \
		data->box_axes[j].x, data->box_axes[j].y);
		j++;
	}
	return (0);
}
