/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:41:33 by dmorar            #+#    #+#             */
/*   Updated: 2019/04/20 13:17:53 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checkorder(int *tab, int len)
{
	int		i;

	i = 0;
	while (i + 1 < len)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	checkarr(int *ar, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (ar[i] == ar[j] && i != j)
			{
				ft_printf("Error\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}
