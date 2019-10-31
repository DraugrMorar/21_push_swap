/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:40:07 by dmorar            #+#    #+#             */
/*   Updated: 2019/04/20 13:23:07 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_strlen_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' || (ft_isdigit(str[i]) == 1) || str[i] == '-' ||
	str[i] == '+')
		i++;
	if (i > 11)
	{
		ft_printf("Error\n");
		exit(0);
	}
}

int			is_in_str_digit(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		j += ft_isdigit(str[i]);
		i++;
	}
	if (j == 0)
		return (0);
	return (1);
}

char		**fill_str(char **str, int *len)
{
	char			**str2;
	int				i;
	char			*temp;

	i = 1;
	temp = (char *)malloc(sizeof(char));
	while (i < *len)
	{
		if (str[i][0] == '\0' || is_in_str_digit(str[i]) == 0)
		{
			ft_printf("Error\n");
			exit(0);
		}
		str[i] = ft_strjoin(str[i], " ");
		temp = ft_strjoin_free(temp, str[i], 1, 0);
		i++;
	}
	str2 = ft_strsplit(temp, ' ');
	i = 0;
	while (str2[i] != NULL)
		i++;
	*len = i;
	free(temp);
	return (str2);
}

int			*fillarr(int ac, char **str)
{
	int				i;
	int				j;
	long long int	*arr;
	int				*ar;

	i = 0;
	j = 0;
	arr = (long long int *)malloc(sizeof(long long int) * (ac));
	ar = (int *)malloc(sizeof(int) * (ac));
	while (i < ac)
	{
		check_strlen_str(str[i]);
		arr[j] = ft_atoi_long(str[i]);
		if (arr[j] > 2147483647 || arr[j] < -2147483648)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		else
			ar[j] = (int)arr[j];
		i++;
		j++;
	}
	free(arr);
	return (ar);
}

void		checknum(int ac, char **str)
{
	int		j;
	int		i;

	i = 0;
	while (i < ac)
	{
		j = 1;
		if (str[i][0] == '\0' || (ft_isdigit(str[i][0]) == 0 &&
		str[i][0] != '-'))
		{
			ft_printf("Error\n");
			exit(0);
		}
		while (str[i][j] != '\0')
		{
			if (ft_isdigit(str[i][j]) == 0)
			{
				ft_printf("Error\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}
