/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:31:33 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/17 22:17:16 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_header.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	event_on(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		free(data->arrows);
		data->arrows = ft_strdup("exit_game");
	}
	else if (keycode == 0)
	{
		free(data->arrows);
		data->arrows = ft_strdup("run_left");
	}
	else if (keycode == 1)
	{
		free(data->arrows);
		data->arrows = ft_strdup("run_down");
	}
	else if (keycode == 2)
	{
		free(data->arrows);
		data->arrows = ft_strdup("run_right");
	}
	else if (keycode == 13)
	{
		free(data->arrows);
		data->arrows = ft_strdup("run_up");
	}
	return (0);
}

int	event_stop(int keycode, t_data *data)
{
	if (keycode == 0)
	{
		free(data->arrows);
		data->arrows = ft_strdup("idle_left");
	}
	else if (keycode == 1)
	{
		free(data->arrows);
		data->arrows = ft_strdup("idle_down");
	}
	else if (keycode == 2)
	{
		free(data->arrows);
		data->arrows = ft_strdup("idle_right");
	}
	else if (keycode == 13)
	{
		free(data->arrows);
		data->arrows = ft_strdup("idle_up");
	}
	return (0);
}

int	key_hook(t_data *data)
{
	if (ft_strcmp(data->arrows ,"exit_game") == 0)
		exit(0);
	else if (ft_strcmp(data->arrows ,"run_left") == 0)
		check_box_left(data);
	else if (ft_strcmp(data->arrows ,"run_down") == 0)
		check_box_down(data);
	else if (ft_strcmp(data->arrows ,"run_right") == 0)
		check_box_right(data);
	else if (ft_strcmp(data->arrows ,"run_up") == 0)
		check_box_up(data);
	else if (ft_strcmp(data->arrows ,"idle_left") == 0)
		left_idle(data);
	else if (ft_strcmp(data->arrows ,"idle_down") == 0)
		front_idle(data);
	else if (ft_strcmp(data->arrows ,"idle_right") == 0)
		right_idle(data);
	else if (ft_strcmp(data->arrows ,"idle_up") == 0)
		back_idle(data);
	return (0);
}
