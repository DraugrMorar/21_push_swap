/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:13:34 by dmorar            #+#    #+#             */
/*   Updated: 2019/04/20 13:38:53 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		fill_right(t_check *fo, int i, int y)
{
	int		x;
	int		x1;
	int		j;

	while (i < fo->lenb)
	{
		j = 0;
		while (j < fo->y)
		{
			x = 0;
			x1 = WID / 2;
			while (x < ((float)WID / 2 - 10) * ((float)fo->arb[i] /
			(float)fo->max))
			{
				if ((x + x1) >= 0 && (y + j) >= 0 && (y + j) < WID &&
				(x + x1) < WID)
					fo->img_data[(x + x1) + (y + j) * WID] = 0xFF83B9 -
							(fo->arb[i] / fo->max + fo->arb[i]);
				x++;
			}
			j++;
		}
		i++;
		y += j + 1;
	}
}

void		fill_left(t_check *fo, int i, int y)
{
	int		x;
	int		j;

	while (i < fo->lenar)
	{
		j = 0;
		while (j < fo->y)
		{
			x = 0;
			while (x < ((float)WID / 2 - 10) * ((float)fo->ara[i] /
			(float)fo->max))
			{
				if (x >= 0 && (y + j) >= 0 && (y + j) < WID && x < WID)
					fo->img_data[(WID / 2 - x + (y + j) * WID)] = 0x00FFFF -
							(fo->ara[i] / fo->max + fo->ara[i]);
				x++;
			}
			j++;
		}
		i++;
		y += j + 1;
	}
}

void		justdraw(t_check *fo, char *str)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WID * WID)
		fo->img_data[x] = 0x45007A;
	y = 99;
	x = WID / 2;
	while (++y < WID)
		fo->img_data[x + y * WID] = 0xFFFFFF;
	y = 100;
	x = -1;
	while (++x < WID)
		fo->img_data[x + y * WID] = 0xFFFFFF;
	if (fo->lenb > 0)
		fill_right(fo, 0, 110);
	fill_left(fo, 0, 110);
	mlx_put_image_to_window(fo->mlx_ptr, fo->win_ptr, fo->img_ptr, 0, 0);
	mlx_string_put(fo->mlx_ptr, fo->win_ptr, 350, 40, 0xD30606, "A");
	mlx_string_put(fo->mlx_ptr, fo->win_ptr, 1000, 40, 0xD30606, "B");
	mlx_string_put(fo->mlx_ptr, fo->win_ptr, 640, 40, 0x3DD306, str);
}

void		max_min_changes(t_check *fo)
{
	int		i;
	int		min;
	int		j;

	i = 0;
	j = 0;
	while (i < fo->lenar)
	{
		if (fo->ara[i] < fo->ara[j])
			j = i;
		i++;
	}
	min = fo->ara[j];
	if (min <= 0)
	{
		i = 0;
		while (i < fo->lenar)
		{
			fo->ara[i] = fo->ara[i] + (min * -1) + 1;
			i++;
		}
	}
}

void		visualit(t_check *fo)
{
	int i;

	i = 0;
	max_min_changes(fo);
	fo->max = fo->ara[i];
	while (i < fo->lenar)
	{
		if (fo->ara[i] > fo->max)
			fo->max = fo->ara[i];
		i++;
	}
	fo->len = fo->lenar;
	fo->y = 1000 / fo->len;
	if (fo->y > 20)
		fo->y = 20;
	fo->mlx_ptr = mlx_init();
	fo->win_ptr = mlx_new_window(fo->mlx_ptr, WID, WID, "CHECKER");
	fo->img_ptr = mlx_new_image(fo->mlx_ptr, WID, WID);
	fo->img_data = (int*)mlx_get_data_addr(fo->img_ptr, &fo->bpp,
		&fo->line_size, &fo->endian);
	justdraw(fo, "no moves");
	mlx_hook(fo->win_ptr, 2, 0, key_release, fo);
	mlx_hook(fo->win_ptr, 17, 0, closemap, fo);
	mlx_loop(fo->mlx_ptr);
}
