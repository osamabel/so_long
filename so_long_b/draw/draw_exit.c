/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:44:36 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/19 16:21:35 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_header.h"

int	draw_exit_befor(t_data *data)
{
	int	j;

	j = 0;
	data->img = mlx_xpm_file_to_image(data->mlx_ptr, "image/exit/exit.xpm", \
	&data->x, &data->y);
	while (j < data->exit_games)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, \
		data->exit_games_axes[j].x, data->exit_games_axes[j].y);
		j++;
	}
	return (0);
}

int	draw_exit_after(t_data *data)
{
	static int	i;
	static int	frams;
	int			j;

	j = 0;
	if (frams < FRAMS && i == 0)
		draw_position(data, &i, &frams, "image/exit/exit1.xpm");
	else if (frams < FRAMS && i == 1)
		draw_position(data, &i, &frams, "image/exit/exit2.xpm");
	else if (frams < FRAMS && i == 2)
		draw_position(data, &i, &frams, "image/exit/exit3.xpm");
	else if (frams < FRAMS && i == 3)
		draw_position(data, &i, &frams, "image/exit/exit4.xpm");
	while (j < data->exit_games)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, \
		data->exit_games_axes[j].x, data->exit_games_axes[j].y);
		j++;
	}
	return (0);
}
