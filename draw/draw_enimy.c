/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enimy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:07:53 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/18 20:50:15 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_header.h"

void	make_enemy_action(t_data *data, char *action)
{
	data->arrows_enimy = ft_strdup(action);
	check_box_enimy(data);
}

void	tracking_person(t_data *data)
{
	static int	z;

	data->z = z;
	if (data->enimy_axes[z].x < data->person_axes[0].x)
	{
		update_block_enimy(data, SPEED + 55, 0, BLOCK * (data->X_block - 1));
		make_enemy_action(data, "right");
	}
	if (data->enimy_axes[z].y < data->person_axes[0].y)
	{
		update_block_enimy(data, 0, SPEED + 55, BLOCK * (data->Y_block - 1));
		make_enemy_action(data, "down");
	}
	if (data->enimy_axes[z].x > data->person_axes[0].x)
	{
		update_block_enimy(data, -SPEED, 0, BLOCK);
		make_enemy_action(data, "left");
	}
	if (data->enimy_axes[z].y > data->person_axes[0].y)
	{
		update_block_enimy(data, 0, -SPEED, BLOCK);
		make_enemy_action(data, "up");
	}
	if (z++ && z == data->enimy)
		z = 0;
}

void	game_over(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->enimy)
	{
		if ((data->person_axes[0].x - data->enimy_axes[j].x < 30 && \
		data->person_axes[0].y - data->enimy_axes[j].y < 30) && \
		(data->enimy_axes[j].x - data->person_axes[0].x < 30 && \
		data->enimy_axes[j].y - data->person_axes[0].y < 30))
		{
			if (data->arrows)
				free(data->arrows);
			free_game(data);
			write(1, "LOSE _ GAME\n", 12);
			exit(1);
			break ;
		}
		j++;
	}
}

int	draw_enimy(t_data *data)
{
	static int	i;
	static int	frams;
	int			j;

	j = 0;
	if (frams < FRAMS && i == 0)
		draw_position(data, &i, &frams, "image/enemy/frm0.xpm");
	else if (frams < FRAMS && i == 1)
		draw_position(data, &i, &frams, "image/enemy/frm1.xpm");
	else if (frams < FRAMS && i == 2)
		draw_position(data, &i, &frams, "image/enemy/frm2.xpm");
	else if (frams < FRAMS && i == 3)
		draw_position(data, &i, &frams, "image/enemy/frm3.xpm");
	while (j < data->enimy)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, \
		data->enimy_axes[j].x, data->enimy_axes[j].y);
		j++;
	}
	tracking_person(data);
	game_over(data);
	return (0);
}
