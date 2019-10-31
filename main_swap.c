/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:37:56 by dmorar            #+#    #+#             */
/*   Updated: 2019/04/20 13:22:32 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	newdata(t_swap *fo)
{
	if (fo->mv == NULL)
		fo->mv = (t_mv *)malloc(sizeof(t_mv) * fo->lenb);
	fo->mv->a = 0;
	fo->mv->b = 0;
	fo->mv->wa = 0;
	fo->mv->wb = 0;
	fo->mv->res = 0;
	fo->midara = fo->lenar / 2;
	fo->midarb = fo->lenb / 2;
}

void	make_min_moves(t_swap *fo)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (i < fo->lenb)
	{
		if (fo->mv[i].res < fo->mv[min].res)
			min = i;
		i++;
	}
	ordermin(fo, fo->mv, min, fo->arb[min]);
}

void	count_move2(t_swap *fo, int i)
{
	int j;

	j = 0;
	while (j < fo->lenar)
	{
		if (fo->ara[fo->lenar - 1] < fo->arb[i] && fo->ara[0] > fo->arb[i])
			fo->mv[i].a = 0;
		else if (fo->ara[j] < fo->arb[i] && fo->ara[j + 1] > fo->arb[i] &&
		(j + 1) < fo->lenar)
		{
			fo->mv[i].a = j;
			if (fo->mv[i].a <= fo->midara)
				fo->mv[i].wa = 1;
			else
				fo->mv[i].a = fo->lenar - fo->mv[i].a;
		}
		j++;
	}
}

void	count_move(t_swap *fo, int i)
{
	newdata(fo);
	while (i < fo->lenb)
	{
		count_move2(fo, i);
		if (i > fo->midarb)
			fo->mv[i].b = fo->lenb - i;
		else
		{
			fo->mv[i].b = i;
			fo->mv[i].wb = 1;
		}
		if (fo->mv[i].wa == fo->mv[i].wb)
		{
			if (fo->mv[i].a > fo->mv[i].b)
				fo->mv[i].res = fo->mv[i].a;
			else
				fo->mv[i].res = fo->mv[i].b;
		}
		else if (fo->mv[i].wa != fo->mv[i].wb)
			fo->mv[i].res = fo->mv[i].a + fo->mv[i].b;
		i++;
	}
	make_min_moves(fo);
}

int		main(int ac, char **av)
{
	t_swap	*fo;
	char	**str;

	fo = (t_swap*)malloc(sizeof(t_swap));
	if (ac == 1)
		return (0);
	else if (ac >= 2)
	{
		str = fill_str(av, &ac);
		checknum(ac, str);
		fo->ara = fillarr(ac, str);
		fo->lenar = ac;
		fo->arb = (int *)malloc(sizeof(int) * (fo->lenar));
		fo->lenb = 0;
		checkarr(fo->ara, fo->lenar);
		if (checkorder(fo->ara, fo->lenar) == 1)
			exit(0);
		only_maxa_and_mina(fo);
		count_move(fo, 0);
		exit(0);
	}
	return (0);
}
