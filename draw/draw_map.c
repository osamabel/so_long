/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:38:06 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/17 22:28:45 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_header.h"

int	check_tacking_coll(t_data *data)
{
	int	i;

	i = 0;
	while (data->taken_coll[i] && i < data->collectibles)
		i++;
	if (i == data->collectibles)
		return (1);
	return (0);
}

int	draw_map(t_data *data)
{
	int	j;

	j = 0;
	if (data->collectibles > 0)
		draw_coupon(data);
	if (data->enimy > 0)
		draw_enimy(data);
	key_hook(data);
	j = 0;
	if (!check_tacking_coll(data))
		draw_exit_befor(data);
	else
	{
		while (j < data->exit_games)
		{
			if (data->next_block->next_x_min == data->exit_games_axes[j].x && data->next_block->next_y_min == data->exit_games_axes[j].y)
			{
				free(data->arrows);
				data->arrows = ft_strdup("exit_game");
			}
			j++;
		}
		draw_exit_after(data);
	}
	return (0);
}
