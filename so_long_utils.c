/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:03:46 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/03 21:26:28 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long_header.h"

int	verify_map(char	**map, t_data *data)
{
	int	x;
	int	y;
	int	person;

	person = 0;
	x = 0;
	y = 0;
	while (y <= data->Y_block)
	{
		while (*(*map + x) != '\n' && *(*map + x))
		{
			if ((y == 0 || y == data->Y_block) && *(*map + x) != '1')
				return (0);
			if (y > 0 && y < data->Y_block)
			{
				if (*(*map + x - 1) == '\n' && *(*map + x) != '1')
					return (0);
				if (*(*map + x + 1) == '\n' && *(*map + x) != '1')
					return (0);
				if (*(*map + x) != '1' && *(*map + x) != '0' && *(*map + x)\
				 != 'C' && *(*map + x) != 'P' && *(*map + x) != 'E')
					return (0);
			}
			x++;
			if (*(*map + x) == 'P')
				person++;
			if (person > 1)
				return (0);
		}
		x++;
		y++;
	}
	return (1);
}