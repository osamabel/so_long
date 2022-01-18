/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_get_axes_ulits.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:33:00 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/16 17:08:26 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_header.h"

void	peson_xy(t_data *data, int x, int y)
{
	data->person_axes[0].x = x * BLOCK + 19;
	data->person_axes[0].y = y * BLOCK + 19;
}

void	collectibes_xy(t_data *data, int x, int y)
{
	static int	c;

	data->collectibles_axes[c].x = x * BLOCK;
	data->collectibles_axes[c].y = y * BLOCK;
	c++;
}

void	exit_xy(t_data *data, int x, int y)
{
	static int	e;

	data->exit_games_axes[e].x = x * BLOCK;
	data->exit_games_axes[e].y = y * BLOCK;
	e++;
}

void	box_xy(t_data *data, int x, int y)
{
	static int	b;

	data->box_axes[b].x = x * BLOCK;
	data->box_axes[b].y = y * BLOCK;
	b++;
}

void	enimy_xy(t_data *data, int x, int y)
{
	static int	en;

	data->enimy_axes[en].x = x * BLOCK + 19;
	data->enimy_axes[en].y = y * BLOCK + 19;
	en++;
}
