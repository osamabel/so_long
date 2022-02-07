/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:38:06 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/19 15:06:39 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_header.h"

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

void	end_game(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->exit_games)
	{
		if (data->next_block->next_x_min == data->exit_games_axes[j].x && \
		data->next_block->next_y_min == data->exit_games_axes[j].y)
		{
			if (data->arrows)
				free(data->arrows);
			free_game(data);
			write(1, "WIN _ GAME\n", 11);
			exit(1);
		}
		j++;
	}
}

int	draw_map(t_data *data)
{
	int	j;

	j = 0;
	if (data->collectibles > 0)
		draw_coupon(data);
	key_hook(data);
	j = 0;
	if (!check_tacking_coll(data))
		draw_exit_befor(data);
	else
	{
		end_game(data);
		draw_exit_after(data);
	}
	return (0);
}
