/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:46:03 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/19 16:01:45 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_header.h"

int	check_box_left(t_data *data)
{
	update_block(data, -SPEED, 0, BLOCK);
	check_box(data);
	check_coupon(data);
	left_run(data);
	return (0);
}
