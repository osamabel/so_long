/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:46:15 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/19 22:57:15 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_header.h"

int	check_box_right(t_data *data)
{
	update_block(data, SPEED + 55, 0, BLOCK * (data->x_block - 1));
	check_box(data);
	check_coupon(data);
	right_run(data);
	return (0);
}
