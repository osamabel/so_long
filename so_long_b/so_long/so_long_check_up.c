/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:46:34 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/19 16:01:45 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_header.h"

int	check_box_up(t_data *data)
{
	update_block(data, 0, -SPEED, BLOCK);
	check_box(data);
	check_coupon(data);
	back_run(data);
	return (0);
}
