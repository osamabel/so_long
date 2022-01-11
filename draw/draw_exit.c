/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:44:36 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/09 16:52:41 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	draw_exit(t_data *data)
{
	static int	i;
	static int	frams;
	static int j;

	if (frams < FRAMS && i == 0)
		draw_position(data, &i, &frams, "coupon/exit1.xpm");
	else if (frams < FRAMS && i == 1)
		draw_position(data, &i, &frams, "coupon/exit2.xpm");
	else if (frams < FRAMS && i == 2)
		draw_position(data, &i, &frams, "coupon/exit3.xpm");
	else if (frams < FRAMS && i == 3)
		draw_position(data, &i, &frams, "coupon/exit4.xpm");

	while (j < data->exit_games)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, data->exit_games_axes[j].x, data->exit_games_axes[j].y);
		j++;
	}
	j = 0;
	return (0);
}