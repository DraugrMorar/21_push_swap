/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:40:52 by dmorar            #+#    #+#             */
/*   Updated: 2019/04/20 12:14:59 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		find_maxa_and_mina(t_swap *fo)
{
	int i;
	int j;

	i = 0;
	j = 0;
	fo->maxa = fo->ara[i];
	while (i < fo->lenar)
	{
		if (fo->ara[i] > fo->maxa)
			fo->maxa = fo->ara[i];
		i++;
	}
	i = 0;
	while (i < fo->lenar)
	{
		if (fo->ara[i] < fo->ara[j])
			j = i;
		i++;
	}
	fo->mina = fo->ara[j];
}

void		maxa_mina_ordering(t_swap *fo)
{
	if (fo->ara[0] != fo->mina || fo->ara[2] != fo->maxa)
	{
		if ((fo->ara[0] == fo->mina && fo->ara[1] == fo->maxa)
			|| (fo->ara[1] == fo->mina && fo->ara[2] == fo->maxa)
			|| (fo->ara[0] == fo->maxa && fo->ara[2] == fo->mina))
		{
			top_two_el(fo->ara);
			ft_printf("sa\n");
		}
	}
}

void		for_two_val(t_swap *fo)
{
	if (fo->maxa == fo->ara[0])
	{
		minus_one_pos(fo->ara, fo->lenar);
		ft_printf("ra\n");
	}
	exit(0);
}

void		only_maxa_and_mina(t_swap *fo)
{
	int i;

	i = fo->lenar;
	find_maxa_and_mina(fo);
	if (fo->lenar == 2)
		for_two_val(fo);
	while (i != 3)
	{
		if (fo->ara[0] == fo->maxa || fo->ara[0] == fo->mina)
		{
			minus_one_pos(fo->ara, fo->lenar);
			ft_printf("ra\n");
		}
		if (fo->ara[0] < fo->maxa && fo->ara[0] > fo->mina)
		{
			swap_el(fo, 1);
			ft_printf("pb\n");
			i--;
		}
	}
	maxa_mina_ordering(fo);
}
