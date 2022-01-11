/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_idle_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:12:06 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/11 13:51:01 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	back_idle(t_data *data)
{
	static int	i;
	static int	frams;

	draw_coupon(data);
	draw_wall_box(data);
	if (frams < FRAMS && i == 0)
		draw_position(data, &i, &frams, "saitama55/back_idle1.xpm");
	else if (frams < FRAMS && i == 1)
		draw_position(data, &i, &frams, "saitama55/back_idle2.xpm");
	else if (frams < FRAMS && i == 2)
		draw_position(data, &i, &frams, "saitama55/back_idle3.xpm");
	else if (frams < FRAMS && i == 3)
		draw_position(data, &i, &frams, "saitama55/back_idle2.xpm");
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, data->person_axes[0].x, data->person_axes[0].y);
	return (0);
}
