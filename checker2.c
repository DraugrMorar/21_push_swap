/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:49:50 by dmorar            #+#    #+#             */
/*   Updated: 2019/04/14 19:09:25 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_el_check(t_check *fo, int arr)
{
	int	i;

	i = 0;
	if (arr == 1)
	{
		if (fo->lenb != 0)
			movedown(fo->arb, fo->lenb);
		fo->arb[0] = fo->ara[0];
		fo->lenb++;
		minus_one_pos(fo->ara, fo->lenar);
		fo->lenar--;
	}
	if (arr == 2 && fo->lenb > 0)
	{
		if (fo->lenar != 0)
			movedown(fo->ara, fo->lenar);
		fo->ara[0] = fo->arb[0];
		fo->lenar++;
		minus_one_pos(fo->arb, fo->lenb);
		fo->lenb--;
	}
}

void	makecomands2(t_check *fo, int i)
{
	if (ft_strcmp(fo->com[i], "pa") == 0)
		swap_el_check(fo, 2);
	else if (ft_strcmp(fo->com[i], "pb") == 0)
		swap_el_check(fo, 1);
	else if (ft_strcmp(fo->com[i], "rra") == 0)
		plus_one_pos(fo->ara, fo->lenar);
	else if (ft_strcmp(fo->com[i], "rrb") == 0)
		plus_one_pos(fo->arb, fo->lenb);
	else if (ft_strcmp(fo->com[i], "rrr") == 0)
	{
		plus_one_pos(fo->ara, fo->lenar);
		plus_one_pos(fo->arb, fo->lenb);
	}
	else if (ft_strcmp(fo->com[i], "ra") == 0)
		minus_one_pos(fo->ara, fo->lenar);
	else if (ft_strcmp(fo->com[i], "rb") == 0)
		minus_one_pos(fo->arb, fo->lenb);
	else if (ft_strcmp(fo->com[i], "rr") == 0)
	{
		minus_one_pos(fo->ara, fo->lenar);
		minus_one_pos(fo->arb, fo->lenb);
	}
}

void	makecomands(t_check *fo)
{
	int		i;

	i = 0;
	fo->len = fo->lenar;
	while (i < fo->lencom)
	{
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
		i++;
	}
}

void	validcomands(char **com, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (ft_strcmp(com[i], "sa") == 0 || ft_strcmp(com[i], "sb") == 0 ||
			ft_strcmp(com[i], "ss") == 0 || ft_strcmp(com[i], "pa") == 0 ||
			ft_strcmp(com[i], "pb") == 0 || ft_strcmp(com[i], "ra") == 0 ||
			ft_strcmp(com[i], "rb") == 0 || ft_strcmp(com[i], "rr") == 0 ||
			ft_strcmp(com[i], "rra") == 0 || ft_strcmp(com[i], "rrb") == 0 ||
			ft_strcmp(com[i], "rrr") == 0)
			j++;
		i++;
	}
	if (j != len)
	{
		ft_printf("Error\n");
		exit(0);
	}
}

void	checkcomands(t_check *fo, char *str)
{
	int i;

	i = 0;
	fo->lencom = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] != '\n')
			fo->lencom++;
		else if (str[i] == '\n' && str[i + 1] == '\n')
		{
			ft_printf("Error\n");
			exit(0);
		}
		i++;
	}
	if (!(fo->com = ft_strsplit(str, '\n')))
		exit(0);
	validcomands(fo->com, fo->lencom);
}
