/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_get_axes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:36:06 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/18 20:24:43 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_header.h"

void	free_game(t_data *data)
{
	if (data->taken_coll)
		free(data->taken_coll);
	if (data->person_axes)
		free(data->person_axes);
	if (data->next_block)
		free(data->next_block);
	if (data->collectibles_axes)
		free(data->collectibles_axes);
	if (data->collectibles_taken_axes)
		free(data->collectibles_taken_axes);
	if (data->exit_games_axes)
		free(data->exit_games_axes);
	if (data->box_axes)
		free(data->box_axes);
	if (data->enimy_axes)
		free(data->enimy_axes);
}

void	*ft_memset(void *buf, int ch, size_t	len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)buf)[i] = (unsigned char) ch;
		i++;
	}
	return (buf);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(count * size);
	if (!s)
		return (0);
	ft_memset(s, 0, size * count);
	return ((void *)s);
}

void	items_allocation(t_data *data)
{
	data->taken_coll = (int *)ft_calloc(sizeof(int), data->collectibles);
	data->person_axes = (t_point *)ft_calloc(sizeof(t_point), 1);
	data->next_block = (t_next_block *)ft_calloc(sizeof(t_next_block), 1);
	data->collectibles_axes = (t_point *)ft_calloc(sizeof(t_point), \
	data->collectibles);
	data->collectibles_taken_axes = (t_point *)ft_calloc(sizeof(t_point), \
	data->collectibles);
	data->exit_games_axes = (t_point *)ft_calloc(sizeof(t_point), \
	data->exit_games);
	data->box_axes = (t_point *)ft_calloc(sizeof(t_point), data->box);
	data->enimy_axes = (t_point *)ft_calloc(sizeof(t_point), data->enimy);
	if (!data->taken_coll || !data->person_axes || !data->collectibles_axes || \
	!data->next_block || !data->collectibles_taken_axes || \
	!data->exit_games_axes || !data->box_axes || !data->enimy_axes)
	{
		free_game(data);
		malloc_error();
	}
}

void	get_data_axes(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	items_allocation(data);
	while (y < data->Y_block)
	{
		x = 0;
		while (x < data->X_block)
		{
			if (data->map[y][x] == 'P')
				peson_xy(data, x, y);
			if (data->map[y][x] == 'C')
				collectibes_xy(data, x, y);
			if (data->map[y][x] == 'E')
				exit_xy(data, x, y);
			if (data->map[y][x] == '1')
				box_xy(data, x, y);
			if (data->map[y][x] == 'X')
				enimy_xy(data, x, y);
			x++;
		}
		y++;
	}
}
