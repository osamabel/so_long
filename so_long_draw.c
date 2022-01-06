/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:12:57 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/06 16:03:57 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"



void	draw_wall_box(t_data *data, int x, int y)
{
	data->img = mlx_xpm_file_to_image(data->mlx_ptr,"image1/wall_box.xpm",&data->x,&data->y);
	mlx_put_image_to_window(data->mlx_ptr ,data->mlx_win, data->img, x, y);
}

void	draw_corner_top_left(t_data *data, int x, int y)
{
	data->img = mlx_xpm_file_to_image(data->mlx_ptr,"image1/corner_top_left.xpm",&data->x,&data->y);
	mlx_put_image_to_window(data->mlx_ptr ,data->mlx_win, data->img, x, y);
}

void	draw_corner_top_right(t_data *data, int x, int y)
{
	data->img = mlx_xpm_file_to_image(data->mlx_ptr,"image1/corner_top_right.xpm",&data->x,&data->y);
	mlx_put_image_to_window(data->mlx_ptr ,data->mlx_win, data->img, x, y);
}

void	draw_corner_buttom_right(t_data *data, int x, int y)
{
	data->img = mlx_xpm_file_to_image(data->mlx_ptr,"image1/corner_buttom_right.xpm",&data->y,&data->y);
	mlx_put_image_to_window(data->mlx_ptr ,data->mlx_win, data->img, x, y);
}

void	draw_corner_buttom_left(t_data *data, int x, int y)
{
	data->img = mlx_xpm_file_to_image(data->mlx_ptr,"image1/corner_buttom_left.xpm",&data->x,&data->y);
	mlx_put_image_to_window(data->mlx_ptr ,data->mlx_win, data->img, x, y);
}

void	draw_wall_top(t_data *data, int x, int y)
{
	data->img = mlx_xpm_file_to_image(data->mlx_ptr,"image1/wall_top.xpm",&data->x,&data->y);
	mlx_put_image_to_window(data->mlx_ptr ,data->mlx_win, data->img, x, y);
}

void	draw_wall_buttom(t_data *data, int x, int y)
{
	data->img = mlx_xpm_file_to_image(data->mlx_ptr,"image1/wall_buttom.xpm",&data->x,&data->y);
	mlx_put_image_to_window(data->mlx_ptr ,data->mlx_win, data->img, x, y);
}

void	draw_wall_right(t_data *data, int x, int y)
{
	data->img = mlx_xpm_file_to_image(data->mlx_ptr,"image1/wall_right.xpm",&data->x,&data->y);
	mlx_put_image_to_window(data->mlx_ptr ,data->mlx_win, data->img, x, y);
}

void	draw_wall_left(t_data *data, int x, int y)
{
	data->img = mlx_xpm_file_to_image(data->mlx_ptr,"image1/wall_left.xpm",&data->x,&data->y);
	mlx_put_image_to_window(data->mlx_ptr ,data->mlx_win, data->img, x, y);
}

void	draw_position(t_data *data, int *i, int *frams ,char	*path)
{
	data->img = mlx_xpm_file_to_image(data->mlx_ptr, path,&data->x,&data->y);
	*frams += 1;
	if (*frams == 13)
	{
		*i += 1;
		*frams = 0;
	}
	if (*i == 4)
		*i = 0;
}

int run_right(t_data *data)
{
	static int i;
	static int frams;

	if (frams < 13 && i == 0)
		draw_position(data , &i, &frams, "saitama/right_run1.xpm");
	else if (frams < 13 && i == 1)
		draw_position(data , &i, &frams, "saitama/right_run2.xpm");
	else if (frams < 13 && i == 2)
		draw_position(data , &i, &frams, "saitama/right_run3.xpm");
	else if (frams < 13 && i == 3)
		draw_position(data , &i, &frams, "saitama/right_run4.xpm");
	mlx_put_image_to_window(data->mlx_ptr ,data->mlx_win, data->img, 74, 74);
	return 0;
}

int run_left(t_data *data)
{
	static int i;
	static int frams;

	if (frams < 13 && i == 0)
		draw_position(data , &i, &frams, "saitama/left_run1.xpm");
	else if (frams < 13 && i == 1)
		draw_position(data , &i, &frams, "saitama/left_run2.xpm");
	else if (frams < 13 && i == 2)
		draw_position(data , &i, &frams, "saitama/left_run3.xpm");
	else if (frams < 13 && i == 3)
		draw_position(data , &i, &frams, "saitama/left_run4.xpm");
	mlx_put_image_to_window(data->mlx_ptr ,data->mlx_win, data->img, 74, 74);
	return 0;
}

int idle_right(t_data *data)
{
	static int i;
	static int frams;

	if (frams < 13 && i == 0)
		draw_position(data , &i, &frams, "saitama/right_idle1.xpm");
	else if (frams < 13 && i == 1)
		draw_position(data , &i, &frams, "saitama/right_idle2.xpm");
	else if (frams < 13 && i == 2)
		draw_position(data , &i, &frams, "saitama/right_idle3.xpm");
	else if (frams < 13 && i == 3)
		draw_position(data , &i, &frams, "saitama/right_idle2.xpm");
	mlx_put_image_to_window(data->mlx_ptr ,data->mlx_win, data->img, 74, 74);
	return 0;
}