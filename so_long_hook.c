/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:31:33 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/08 17:06:46 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	key_hook_coupon(int keycode, t_data *data)
{
	printf("keycode = %i\n", keycode);
	if (keycode)
		mlx_loop_hook(data->mlx_ptr, draw_coupon, data);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	printf("keycode = %i\n", keycode);
	if (keycode == 0)
		mlx_loop_hook(data->mlx_ptr, run_left, data);
	if (keycode == 1)
		mlx_loop_hook(data->mlx_ptr, front_run, data);
	if (keycode == 2)
		mlx_loop_hook(data->mlx_ptr, run_right, data);
	if (keycode == 13)
		mlx_loop_hook(data->mlx_ptr, back_run, data);
	return (0);
}

int	key_hook_stop(int keycode, t_data *data)
{

	printf("keycode = %i\n", keycode);
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
