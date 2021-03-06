/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_frams.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:09:29 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/19 15:04:47 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_header.h"

void	draw_position(t_data *data, int *i, int *frams, char *path)
{
	data->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->x, &data->y);
	(*frams)++;
	if (*frams == FRAMS)
	{
		(*i)++;
		*frams = 0;
	}
	if (*i == 4)
		*i = 0;
}
