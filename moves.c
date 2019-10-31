/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:39:14 by dmorar            #+#    #+#             */
/*   Updated: 2019/04/08 12:39:24 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_two_el(int *ar)
{
	int	swap;

	swap = ar[0];
	ar[0] = ar[1];
	ar[1] = swap;
}

void	minus_one_pos(int *a, int len)
{
	int	i;
	int	swap;

	if (len < 2)
		return ;
	i = 0;
	swap = a[i];
	while ((i + 1) < len)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[len - 1] = swap;
}

void	plus_one_pos(int *a, int len)
{
	int	swap;

	if (len < 2)
		return ;
	swap = a[len - 1];
	while ((len - 1) != 0)
	{
		len--;
		a[len] = a[len - 1];
	}
	a[0] = swap;
}

void	movedown(int *str, int len)
{
	int	l;

	l = len;
	while ((l - 1) >= 0)
	{
		str[l] = str[l - 1];
		l--;
	}
}

void	swap_el(t_swap *fo, int arr)
{
	if (arr == 1 && fo->lenar > 0)
	{
		if (fo->lenb != 0)
			movedown(fo->arb, fo->lenb);
		fo->arb[0] = fo->ara[0];
		fo->lenb++;
		minus_one_pos(fo->ara, fo->lenar);
		fo->lenar--;
	}
	else if (arr == 2 && fo->lenb > 0)
	{
		if (fo->lenar != 0)
			movedown(fo->ara, fo->lenar);
		fo->ara[0] = fo->arb[0];
		fo->lenar++;
		minus_one_pos(fo->arb, fo->lenb);
		fo->lenb--;
	}
}
