/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_run_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:13:09 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/11 21:18:31 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	run_right(t_data *data)
{
	static int	i;
	static int	frams;

	draw_coupon(data);
	draw_wall_box(data);
	if (frams < FRAMS && i == 0)
		draw_position(data, &i, &frams, "saitama55/right_run1.xpm");
	else if (frams < FRAMS && i == 1)
		draw_position(data, &i, &frams, "saitama55/right_run2.xpm");
	else if (frams < FRAMS && i == 2)
		draw_position(data, &i, &frams, "saitama55/right_run3.xpm");
	else if (frams < FRAMS && i == 3)
		draw_position(data, &i, &frams, "saitama55/right_run4.xpm");
	// if (data->person_axes[0].x < BLOCK * (data->X_block - 2) + 19)
		data->person_axes[0].x += 3;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, data->person_axes[0].x, data->person_axes[0].y);
	return (0);
}

int	run_right_place(t_data *data)
{
	static int	i;
	static int	frams;

	draw_coupon(data);
	draw_wall_box(data);
	if (frams < FRAMS && i == 0)
		draw_position(data, &i, &frams, "saitama55/right_run1.xpm");
	else if (frams < FRAMS && i == 1)
		draw_position(data, &i, &frams, "saitama55/right_run2.xpm");
	else if (frams < FRAMS && i == 2)
		draw_position(data, &i, &frams, "saitama55/right_run3.xpm");
	else if (frams < FRAMS && i == 3)
		draw_position(data, &i, &frams, "saitama55/right_run4.xpm");
	if (data->person_axes[0].x < BLOCK * (data->X_block - 2) + 19)
		data->person_axes[0].x += 3;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, data->person_axes[0].x, data->person_axes[0].y);
	return (0);
}
