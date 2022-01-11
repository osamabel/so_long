/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:31:33 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/11 21:40:25 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	check_box_up(t_data *data)
{
	int	i;

	int	next_y;
	int	next_y_max;
	int	next_y_min;
	int	next_x_max;
	int	next_x_min;

	i = 0;

	next_y = data->person_axes[0].y - 3;
	next_x_min = data->person_axes[0].x;
	next_x_max = data->person_axes[0].x;
	next_y_max = next_y;
	next_y_min = next_y;

	if (next_y <= BLOCK)
		return (0);
	while (next_y_max % BLOCK != 0)
		next_y_max++;
	while (next_y_min % BLOCK != 0)
		next_y_min--;
	while (next_x_min % BLOCK != 0)
		next_x_min--;
	while (next_x_max % BLOCK != 0)
		next_x_max++;
	while (i < data->box)
	{
		if (next_y_min == data->box_axes[i].y && (next_x_min == data->box_axes[i].x || next_x_max == data->box_axes[i].x))
		{
			if (next_y < next_y_max)
				return (0);
		}
		i++;
	}
	return (1);
}
int	check_box_down(t_data *data)
{
	int	i;
	int	next_y;
	int	next_y_max;
	int	next_x_max;
	int	next_x_min;

	i = 0;

	next_y = data->person_axes[0].y + 3;
	next_x_min = data->person_axes[0].x;
	next_x_max = data->person_axes[0].x;
	next_y_max = next_y;

	if (next_y + 55 >= BLOCK * data->X_block - BLOCK)
		return (0);
	while (next_y_max % BLOCK != 0)
		next_y_max++;
	while (next_x_min % BLOCK != 0)
		next_x_min--;
	while (next_x_max % BLOCK != 0)
		next_x_max++;
	while (i < data->box)
	{
		if (next_y_max == data->box_axes[i].y && (next_x_min == data->box_axes[i].x || next_x_max == data->box_axes[i].x))
		{
			if (next_y + 55 >= next_y_max)
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_box_right(t_data *data)
{
	int	i;
	int	next_x;
	int	next_x_max;
	int	next_y_min;
	int	next_y_max;

	i = 0;

	next_x = data->person_axes[0].x + 3;

	next_x_max = next_x;
	next_y_min = data->person_axes[0].y;
	next_y_max = data->person_axes[0].y;
	if (next_x + 55 >= BLOCK * data->X_block - BLOCK)
		return (0);
	while (next_x_max % BLOCK != 0)
		next_x_max++;
	while (next_y_min % BLOCK != 0)
		next_y_min--;
	while (next_y_max % BLOCK != 0)
		next_y_max++;
	while (i < data->box)
	{
		if (next_x_max == data->box_axes[i].x && (next_y_min == data->box_axes[i].y || next_y_max == data->box_axes[i].y))
		{
			if (next_x + 55 >= next_x_max)
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_box_left(t_data *data)
{
	int	i;
	int	next_x;
	int	next_y;
	int	next_x_min;
	int	next_x_max;
	int	next_y_min;
	int	next_y_max;

	i = 0;

	next_x = data->person_axes[0].x - 3;
	next_y = data->person_axes[0].y;

	next_x_min = next_x;
	next_x_max = next_x;
	next_y_min = next_y;
	next_y_max = next_y;

	if (next_x <= BLOCK)
		return (0);
	while (next_x_min % BLOCK != 0)
		next_x_min--;
	while (next_x_max % BLOCK != 0)
		next_x_max++;
	while (next_y_min % BLOCK != 0)
		next_y_min--;
	while (next_y_max % BLOCK != 0)
		next_y_max++;
	while (i < data->box)
	{
		if (next_x_min == data->box_axes[i].x && (next_y_min == data->box_axes[i].y || next_y_max == data->box_axes[i].y))
		{
			if (next_x < next_x_max)
				return (0);
		}
		i++;
	}
	return (1);
}

int	key_hook(int keycode, t_data *data)
{

	if (keycode == 0)
	{
		if (check_box_left(data))
			mlx_loop_hook(data->mlx_ptr, run_left, data);
		else
			mlx_loop_hook(data->mlx_ptr, run_left_place, data);
	}



	if (keycode == 1)
	{
		if (check_box_down(data))
			mlx_loop_hook(data->mlx_ptr, front_run, data);
		else
			mlx_loop_hook(data->mlx_ptr, front_run_place, data);
	}


	if (keycode == 2)
	{
		if (check_box_right(data))
			mlx_loop_hook(data->mlx_ptr, run_right, data);
		else
			mlx_loop_hook(data->mlx_ptr, run_right_place, data);
	}


	if (keycode == 13)
	{
		if(check_box_up(data))
			mlx_loop_hook(data->mlx_ptr, back_run, data);
		else
			mlx_loop_hook(data->mlx_ptr, back_run_place, data);
	}

	return (0);
}

int	key_hook_stop(int keycode, t_data *data)
{
	if (keycode == 0)
		mlx_loop_hook(data->mlx_ptr, idle_left, data);
	if (keycode == 1)
		mlx_loop_hook(data->mlx_ptr, front_idle, data);
	if (keycode == 2)
		mlx_loop_hook(data->mlx_ptr, idle_right, data);
	if (keycode == 13)
		mlx_loop_hook(data->mlx_ptr, back_idle, data);
	return (0);
}
