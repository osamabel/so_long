/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_idle_right.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:10:50 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/07 17:19:16 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	idle_right(t_data *data)
{
	static int	i;
	static int	frams;

	if (frams < FRAMS && i == 0)
		draw_position(data, &i, &frams, "saitama/right_idle1.xpm");
	else if (frams < FRAMS && i == 1)
		draw_position(data, &i, &frams, "saitama/right_idle2.xpm");
	else if (frams < FRAMS && i == 2)
		draw_position(data, &i, &frams, "saitama/right_idle3.xpm");
	else if (frams < FRAMS && i == 3)
		draw_position(data, &i, &frams, "saitama/right_idle2.xpm");
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 74, 74);
	return (0);
}
