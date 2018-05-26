/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:32:17 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/13 13:43:37 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		check_sort(int *tab, int len)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < len)
	{
		while (++j < len)
		{
			if (tab[i] > tab[j])
			{
				return (1);
			}
		}
		j = i;
	}
	return (0);
}

int		check_sort_decreasing(int *tab, int len)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < len)
	{
		while (++j < len)
		{
			if (tab[i] < tab[j])
			{
				return (1);
			}
		}
		j = i;
	}
	return (0);
}

int		decreasing_to_increasing(t_checker *checker)
{
	while (checker->len_a > 3)
		instruction_push_b(checker, 1);
	instruction_swap_a(checker, 1);
	if (checker->len_a > 2)
		instruction_reverse_a_r(checker, 1);
	while (checker->len_b)
	{
		instruction_push_a(checker, 1);
		instruction_rotate_a_r(checker, 1);
	}
	return (0);
}

int		*sort_int_tab(int *tab, int len)
{
	int		i;
	int		j;
	int		tmp;

	i = -1;
	j = 0;
	while (++i < len)
	{
		while (++j < len)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
		j = i;
	}
	return (tab);
}
