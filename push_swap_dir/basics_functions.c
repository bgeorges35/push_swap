/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 12:58:50 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/09 20:12:11 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_pos_nb(int *tab, int len, int nb)
{
	int i;

	i = 0;
	while (tab[i] != nb && i < len - 1)
		i++;
	return (i);
}

int		find_nb_push_a(int *tab, int len, int nb)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (len--)
	{
		if (nb >= tab[i])
			res++;
		i++;
	}
	return (res);
}

int		ft_second_max_tab(int *tab, int len)
{
	int		max;
	int		i;
	int		res;

	max = ft_max_tab(tab, len);
	i = 0;
	res = tab[i];
	while (len > i)
	{
		if (tab[i] > res && tab[i] != max)
			res = tab[i];
		i++;
	}
	return (res);
}

int		ft_find_j(int len)
{
	int		j;

	if (len < 10)
		j = 1;
	if (len < 15)
		j = 2;
	else if (len < 50)
		j = 3;
	else if (len < 200)
		j = 5;
	else if (len < 250)
		j = 6;
	else if (len < 350)
		j = 7;
	else if (len < 450)
		j = 8;
	else
		j = 10;
	return (j);
}
