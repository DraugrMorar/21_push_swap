/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:33:13 by dmorar            #+#    #+#             */
/*   Updated: 2019/04/18 13:57:16 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_vis_comands(t_check *fo)
{
	static int i;

	if (i == fo->lencom)
	{
		ft_printf("KO\n");
		exit(0);
	}
	if (ft_strcmp(fo->com[i], "sa") == 0)
		top_two_el(fo->ara);
	else if (ft_strcmp(fo->com[i], "sb") == 0)
		top_two_el(fo->arb);
	else if (ft_strcmp(fo->com[i], "ss") == 0)
	{
		top_two_el(fo->ara);
		top_two_el(fo->arb);
	}
	else
		makecomands2(fo, i);
	if (fo->v == 1)
	{
		mlx_clear_window(fo->mlx_ptr, fo->win_ptr);
		ft_bzero(fo->img_data, WID * WID * 4);
		justdraw(fo, fo->com[i]);
	}
	i++;
}

int		key_release(int key, t_check *fo)
{
	if (key == 49)
	{
		if (checkorder(fo->ara, fo->lenar) == 1 && fo->lenar == fo->len)
		{
			mlx_clear_window(fo->mlx_ptr, fo->win_ptr);
			ft_bzero(fo->img_data, WID * WID * 4);
			justdraw(fo, "OK");
		}
		else
			make_vis_comands(fo);
	}
	if (key == 53)
		exit(0);
	return (0);
}

int		closemap(void *fo)
{
	(void)fo;
	exit(0);
}
