/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:06:00 by obelkhad          #+#    #+#             */
/*   Updated: 2022/01/02 18:07:09 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "get_next_line.h"
#include <stdio.h>

typedef struct s_data{
	void 	*img;
	char 	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void 	*mlx_ptr;
	void 	*mlx_win;
	int 	widht;
	int 	hight;
	int		X;
	int		Y;
}	t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_block(t_data *info, int X, int Y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 50)
	{	j = 0;
		while (j < 50)
		{
			my_mlx_pixel_put(info, X + i, Y + j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(info->mlx_ptr ,info->mlx_win, info->img, 0, 0);
}

void	clear_window(t_data *info)
{
	int x;
	int y;
	for (x = 0; x < 1300; x++)
	{
		for (y = 0 ; y < 1000 ; y++)
		{
			my_mlx_pixel_put(info, x, y, 0x3d3550);
		}
			mlx_put_image_to_window(info->mlx_ptr ,info->mlx_win, info->img, 0, 0);
	}
}

int loop_hook(t_data *info)
{
	static int i = 0;
	static int frams = 0;

	info->img = mlx_xpm_file_to_image(info->mlx_ptr,"Textures/mockup.xpm",&info->widht,&info->hight);
	mlx_put_image_to_window(info->mlx_ptr ,info->mlx_win, info->img, 0, 0);
	if (frams < 10 && i == 0)
	{
		info->img = mlx_xpm_file_to_image(info->mlx_ptr,"Textures/0.xpm",&info->widht,&info->hight);
		frams++;
		if (frams == 10)
		{
			i = 1;
			frams = 0;
		}
	}
	else if (frams < 10 && i == 1)
	{
		info->img = mlx_xpm_file_to_image(info->mlx_ptr,"Textures/1.xpm",&info->widht,&info->hight);
		frams++;
		if (frams == 10)
		{
			i = 2;
			frams = 0;
		}
	}
	else if (frams < 10 && i == 2)
	{
		info->img = mlx_xpm_file_to_image(info->mlx_ptr,"Textures/2.xpm",&info->widht,&info->hight);
		frams++;
		if (frams == 10)
		{
			i = 3;
			frams = 0;
		}
	}
	else if (frams < 10 && i == 3)
	{
		info->img = mlx_xpm_file_to_image(info->mlx_ptr,"Textures/3.xpm",&info->widht,&info->hight);
		frams++;
		if (frams == 10)
		{
			i = 1;
			frams = 0;
		}
	}
	else if (frams < 10 && i == 4)
	{
		info->img = mlx_xpm_file_to_image(info->mlx_ptr,"Textures/0.xpm",&info->widht,&info->hight);
		frams++;
		if (frams == 10)
		{
			i = 1;
			frams = 0;
		}
	}
	mlx_put_image_to_window(info->mlx_ptr ,info->mlx_win, info->img, 0, 0);
//	mlx_destroy_image(info->mlx_ptr, info->img);
	return 0;
}


int main (void)
{

	t_data	info;
	void *mlx_ptr = mlx_init();
	void *mlx_win =  mlx_new_window(mlx_ptr ,1300, 1000, "game");
	info.mlx_ptr = mlx_ptr;
	info.mlx_win = mlx_win;
	info.widht = 1300;
	info.hight = 1000;
	info.img = mlx_new_image(mlx_ptr, 1300, 1000);
	info.addr = mlx_get_data_addr(info.img, &info.bits_per_pixel, &info.line_length, &info.endian);
	mlx_loop_hook(mlx_ptr, loop_hook, &info);
	mlx_loop(mlx_ptr);
	return 0;
}