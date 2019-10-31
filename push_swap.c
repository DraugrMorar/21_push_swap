/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:17:53 by dmorar            #+#    #+#             */
/*   Updated: 2019/04/20 12:20:20 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ordermin5(t_swap *fo, int i)
{
	while (fo->ara[i] != '\0')
	{
		if (fo->ara[i] == fo->mina)
			break ;
		i++;
	}
	if (i > fo->lenar / 2)
	{
		while (fo->mina != fo->ara[0])
		{
			plus_one_pos(fo->ara, fo->lenar);
			ft_printf("rra\n");
		}
	}
	else
	{
		while (fo->mina != fo->ara[0])
		{
			minus_one_pos(fo->ara, fo->lenar);
			ft_printf("ra\n");
		}
	}
}

void	ordermin4(t_swap *fo, int value, int i)
{
	if (i < fo->lenar / 2)
	{
		while (!(value < fo->ara[0] && value > fo->ara[fo->lenar - 1]))
		{
			minus_one_pos(fo->ara, fo->lenar);
			ft_printf("ra\n");
		}
	}
	else if (i >= fo->lenar / 2 && fo->lenb != 0)
	{
		while (!(value < fo->ara[0] && value > fo->ara[fo->lenar - 1]))
		{
			plus_one_pos(fo->ara, fo->lenar);
			ft_printf("rra\n");
		}
	}
	if (fo->lenb != 0)
	{
		swap_el(fo, 2);
		ft_printf("pa\n");
	}
	if (fo->lenb > 0)
		count_move(fo, 0);
	else if (fo->lenb == 0)
		ordermin5(fo, 0);
}

void	ordermin3(t_swap *fo, int value, int i)
{
	while (i < fo->lenar)
	{
		if (value > fo->ara[i] && value < fo->ara[i + 1] && (i + 1) < fo->lenar)
			break ;
		else if (value < fo->ara[0] && value > fo->ara[fo->lenar - 1])
			break ;
		i++;
	}
	ordermin4(fo, value, i);
}

void	ordermin2(t_swap *fo, int value, int i)
{
	while (i < fo->lenb)
	{
		if (fo->arb[i] == value)
			break ;
		i++;
	}
	if (i >= fo->lenb / 2)
	{
		while (value != fo->arb[0])
		{
			plus_one_pos(fo->arb, fo->lenb);
			ft_printf("rrb\n");
		}
	}
	else
	{
		while (value != fo->arb[0])
		{
			minus_one_pos(fo->arb, fo->lenb);
			ft_printf("rb\n");
		}
	}
	ordermin3(fo, value, 0);
}

void	ordermin(t_swap *fo, t_mv *mv, int i, int value)
{
	if (mv[i].a < fo->lenar / 2 && i < fo->lenb / 2)
	{
		while (value != fo->arb[0] && !(value < fo->ara[0] &&
		value > fo->ara[fo->lenar - 1]))
		{
			minus_one_pos(fo->ara, fo->lenar);
			minus_one_pos(fo->arb, fo->lenb);
			ft_printf("rr\n");
		}
	}
	else if (mv[i].a >= fo->lenar / 2 && i >= fo->lenb / 2)
	{
		while (value != fo->arb[0] && !(value < fo->ara[0] &&
		value > fo->ara[fo->lenar - 1]))
		{
			plus_one_pos(fo->ara, fo->lenar);
			plus_one_pos(fo->arb, fo->lenb);
			ft_printf("rrr\n");
		}
	}
	ordermin2(fo, value, 0);
}
