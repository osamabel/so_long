/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_run_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:13:09 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/18 17:02:05 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_header.h"

int	right_run(t_data *data)
{
	static int	i;
	static int	frams;

	if (frams < FRAMS && i == 0)
		draw_position(data, &i, &frams, "image/saitama/right_run1.xpm");
	else if (frams < FRAMS && i == 1)
		draw_position(data, &i, &frams, "image/saitama/right_run2.xpm");
	else if (frams < FRAMS && i == 2)
		draw_position(data, &i, &frams, "image/saitama/right_run3.xpm");
	else if (frams < FRAMS && i == 3)
		draw_position(data, &i, &frams, "image/saitama/right_run4.xpm");
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, \
	data->person_axes[0].x, data->person_axes[0].y);
	return (0);
}
