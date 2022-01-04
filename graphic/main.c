/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:33:59 by obelkhad          #+#    #+#             */
/*   Updated: 2021/12/29 20:02:43 by obelkhad         ###   ########.fr       */
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

	// X = X * 50 - 50;
	// Y = Y * 50 - 50;
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

int	mouse_event(int x, int y, t_data *info)
{
	int X = x;
	int Y = y;
	if (x >= 0 && x <= info->widht && y >= 0 && y <= info->hight)
	{
		while (X % 50 != 0)
			X--;
		while (Y % 50 != 0)
			Y--;
		put_block(info, X, Y, 0x27FF00);
	}
	return 0;
}

int	key_hook(int keycode, t_data *info)
{
	static int keyold;
	printf("> %i\n",keycode);
	put_block(info, info->X, info->Y, 0x000000);
	if (keycode == 123)
		info->X = info->X - 50;
	if (keycode == 124)
		info->X = info->X + 50;
	if (keycode == 125)
		info->Y = info->Y + 50;
	if (keycode == 126)
		info->Y = info->Y - 50;
	keyold = keycode;
	if (keyold == 126 && keycode ==124)
	{
		info->X = 0;
		info->Y = 0;
	}
	put_block(info, info->X, info->Y, 0x27FF00);
	return 0;
}
int	key_hook_lol(int keycode, t_data *info)
{
	static int keyold;
	printf("> %i\n",keycode);
	put_block(info, info->X, info->Y, 0x000000);
	keyold = keycode;
	if (keyold == 126 && keycode ==124)
	{
		info->X = 0;
		info->Y = 0;
	}
	put_block(info, info->X, info->Y, 0x27FF00);
	return 0;
}

int main (void)
{
	t_data	info;
	void *mlx_ptr = mlx_init();
	void *mlx_win =  mlx_new_window(mlx_ptr ,800, 800, "game");
	info.mlx_ptr = mlx_ptr;
	info.mlx_win = mlx_win;
	info.widht = 800;
	info.hight = 800;
	info.img = mlx_new_image(mlx_ptr, 800, 800);
	info.addr = mlx_get_data_addr(info.img, &info.bits_per_pixel, &info.line_length, &info.endian);
	int fd = open("./map.ber", O_RDONLY);
	int i =0;
	int color;
	info.X = 0;
	info.Y = 0;
	char	*ber = get_next_line(fd);
	while (ber)
	{
		while (ber[i])
		{
			if (ber[i] == '1')
			{
				color = 0xAA3B00;
				info.X += 50;
			}
			if (ber[i] == '0')
			{
				color = 0x000000;
				info.X += 50;
			}
			if (ber[i] == 'c')
			{
				color = 0xF1508B;
				info.X += 50;
			}
			if (ber[i] == 'e')
			{
				color = 0x5A50F1;
				info.X += 50;
			}
			if (ber[i] == 'p')
			{
				color = 0xFAFE00;
				info.X += 50;
			}
			put_block(&info, info.X, info.Y, color);
			i++;
		}
		ber = get_next_line(fd);
		info.Y += 50;
		i = 0;
	}
	mlx_loop(mlx_ptr);
	return 0;
}
