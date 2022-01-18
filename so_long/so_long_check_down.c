/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_down.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:46:38 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/15 15:23:36 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_header.h"

int	check_box_down(t_data *data)
{
	update_block(data, 0, SPEED + 55, BLOCK * (data->Y_block - 1));
	check_box(data);
	check_coupon(data);
	front_run(data);
	return (0);
}
