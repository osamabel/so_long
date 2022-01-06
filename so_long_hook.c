/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:31:33 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/06 16:03:03 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	key_hook(int keycode, t_data *data)
{
	int o;

	o = data->widht;
	printf("keycode = %i\n", keycode);
	if (keycode == 0)
		mlx_loop_hook(data->mlx_ptr, run_left, data);
	if (keycode == 2)
		mlx_loop_hook(data->mlx_ptr, run_right, data);
	if (keycode == 13)
		mlx_loop_hook(data->mlx_ptr, idle_right, data);
	return (0);
}