/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:37:41 by dmorar            #+#    #+#             */
/*   Updated: 2019/04/20 13:18:45 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_check *fo)
{
	if (fo->v == 1)
		visualit(fo);
	makecomands(fo);
	if (fo->len == fo->lenar)
	{
		if (checkorder(fo->ara, fo->lenar) == 0)
			ft_printf("KO\n");
		else
			ft_printf("OK\n");
		exit(0);
	}
	else
	{
		ft_printf("KO\n");
		exit(0);
	}
}

void	makecheck(int ac, char **av, t_check *fo)
{
	char	**str;

	fo->v = 0;
	if (ft_strcmp(av[1], "-v") == 0)
		fo->v = 1;
	ac -= fo->v;
	str = fill_str(&av[fo->v], &ac);
	checknum(ac, str);
	fo->ara = fillarr(ac, str);
	fo->lenar = ac;
	fo->arb = (int *)malloc(sizeof(int) * fo->lenar);
	fo->lenb = 0;
	fo->len = fo->lenar;
	checkarr(fo->ara, fo->lenar);
}

int		main(int ac, char **av)
{
	char	*comand;
	char	buf[11];
	int		res;
	t_check	*fo;

	comand = (char *)malloc(sizeof(char) * 1);
	fo = (t_check*)malloc(sizeof(t_check));
	comand[0] = '\0';
	if (ac == 1)
		return (0);
	if (ac > 1)
	{
		makecheck(ac, av, fo);
		while ((res = read(0, buf, 10)) > 0)
		{
			buf[res] = '\0';
			comand = ft_strjoin_free(comand, buf, 1, 0);
		}
		checkcomands(fo, comand);
		checker(fo);
	}
	return (0);
}
