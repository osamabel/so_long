/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ckeck_box.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:17:40 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/18 21:03:11 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_header.h"

void	ckeck_exit_axes(t_data *data, int X, int Y)
{
	int	j;

	j = 0;
	while (j < data->exit_games && data->next_block->boolen)
	{
		if (Y == data->exit_games_axes[j].y && X == data->exit_games_axes[j].x)
		{
			data->next_block->boolen = 0;
			break ;
		}
		j++;
	}
}

void	ckeck_wall_axes(t_data *data, int X, int Y)
{
	int	j;

	j = 0;
	while (j < data->box && data->next_block->boolen)
	{
		if (X == data->box_axes[j].x && Y == data->box_axes[j].y)
		{
			data->next_block->boolen = 0;
			break ;
		}
		j++;
	}
}

void	left_right(t_data *data)
{
	if (data->next_block->next_y + 55 > data->next_block->next_y_max)
	{
		ckeck_wall_axes(data, data->next_block->next_x_min, \
		data->next_block->next_y_max);
		ckeck_exit_axes(data, data->next_block->next_x_min, \
		data->next_block->next_y_max);
	}
	if (data->next_block->boolen && !ft_strcmp(data->arrows, "run_left"))
		data->person_axes[0].x -= SPEED;
	if (data->next_block->boolen && !ft_strcmp(data->arrows, "run_right"))
		data->person_axes[0].x += SPEED;
}

void	up_down(t_data *data)
{
	if (data->next_block->next_x + 55 > data->next_block->next_x_max)
	{
		ckeck_wall_axes(data, data->next_block->next_x_max, \
		data->next_block->next_y_min);
		ckeck_exit_axes(data, data->next_block->next_x_max, \
		data->next_block->next_y_min);
	}
	if (data->next_block->boolen && !ft_strcmp(data->arrows, "run_up"))
		data->person_axes[0].y -= SPEED;
	if (data->next_block->boolen && !ft_strcmp(data->arrows, "run_down"))
		data->person_axes[0].y += SPEED;
}

void	check_box(t_data *data)
{
	static int	moves;

	data->next_block->enimy = 0;
	ckeck_wall_axes(data, data->next_block->next_x_min, \
	data->next_block->next_y_min);
	ckeck_exit_axes(data, data->next_block->next_x_min, \
	data->next_block->next_y_min);
	if (!ft_strcmp(data->arrows, "run_left") || \
	!ft_strcmp(data->arrows, "run_right"))
		left_right(data);
	if (!ft_strcmp(data->arrows, "run_up") || \
	!ft_strcmp(data->arrows, "run_down"))
		up_down(data);
	if (data->next_block->boolen)
	{
		data->img = mlx_xpm_file_to_image(data->mlx_ptr, "image/wall_top.xpm", \
		&data->x, &data->y);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 74, 0);
		data->img = mlx_xpm_file_to_image(data->mlx_ptr, \
		"image/corner_top_left.xpm", &data->x, &data->y);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
		mlx_string_put ( data->mlx_ptr, data->mlx_win, 74, 50, 0x000000, \
		ft_itoa(moves));
		moves++;
	}
}
