/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_run_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:12:30 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/11 21:18:37 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	front_run(t_data *data)
{
	static int	i;
	static int	frams;

	draw_coupon(data);
	draw_wall_box(data);
	if (frams < FRAMS && i == 0)
		draw_position(data, &i, &frams, "saitama55/front_run1.xpm");
	else if (frams < FRAMS && i == 1)
		draw_position(data, &i, &frams, "saitama55/front_run2.xpm");
	else if (frams < FRAMS && i == 2)
		draw_position(data, &i, &frams, "saitama55/front_run3.xpm");
	else if (frams < FRAMS && i == 3)
		draw_position(data, &i, &frams, "saitama55/front_run4.xpm");
	// if (data->person_axes[0].y < BLOCK * (data->Y_block - 2) + 19)
		data->person_axes[0].y += 3;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, data->person_axes[0].x, data->person_axes[0].y);
	return (0);
}

int	front_run_place(t_data *data)
{
	static int	i;
	static int	frams;

	draw_coupon(data);
	draw_wall_box(data);
	if (frams < FRAMS && i == 0)
		draw_position(data, &i, &frams, "saitama55/front_run1.xpm");
	else if (frams < FRAMS && i == 1)
		draw_position(data, &i, &frams, "saitama55/front_run2.xpm");
	else if (frams < FRAMS && i == 2)
		draw_position(data, &i, &frams, "saitama55/front_run3.xpm");
	else if (frams < FRAMS && i == 3)
		draw_position(data, &i, &frams, "saitama55/front_run4.xpm");
	if (data->person_axes[0].y < BLOCK * (data->Y_block - 2) + 19)
		data->person_axes[0].y += 3;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, data->person_axes[0].x, data->person_axes[0].y);
	return (0);
}
