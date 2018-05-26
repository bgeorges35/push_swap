/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:33:42 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/13 14:30:37 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		sort_swap(t_checker *stack_nb, int pos)
{
	int		nb;

	nb = stack_nb->tab_a[pos];
	pos = 0;
	if (find_pos_nb(stack_nb->tab_a, stack_nb->len_a, nb) > stack_nb->len_a / 2)
	{
		while (stack_nb->tab_a[1] != nb)
		{
			instruction_reverse_a_r(stack_nb, 1);
			pos++;
		}
		instruction_swap_a(stack_nb, 1);
		while (pos--)
			instruction_rotate_a_r(stack_nb, 1);
		return (0);
	}
	while (stack_nb->tab_a[1] != nb)
	{
		instruction_rotate_a_r(stack_nb, 1);
		pos++;
	}
	instruction_swap_a(stack_nb, 1);
	while (pos--)
		instruction_reverse_a_r(stack_nb, 1);
	return (0);
}

int		check_sort_swap(int *tab, int len)
{
	int		i;
	int		j;
	int		ret;

	i = -1;
	j = 0;
	ret = 0;
	while (++i < len)
	{
		while (++j < len)
		{
			if (tab[i] > tab[j])
			{
				if (!ret)
					ret = find_pos_nb(tab, len, tab[j]);
				else
					return (0);
			}
		}
		j = i;
	}
	return (ret);
}

int		sort_exception_3(t_checker *stack_nb)
{
	int		boolean;

	boolean = 0;
	if (stack_nb->tab_a[0] == ft_max_tab(stack_nb->tab_a, stack_nb->len_a))
		instruction_rotate_a_r(stack_nb, 1);
	if (stack_nb->tab_a[1] == ft_max_tab(stack_nb->tab_a, stack_nb->len_a) &&
	stack_nb->tab_a[0] == ft_second_max_tab(stack_nb->tab_a, stack_nb->len_a))
	{
		instruction_rotate_a_r(stack_nb, 1);
		instruction_rotate_a_r(stack_nb, 1);
	}
	if (check_sort(stack_nb->tab_a, stack_nb->len_a))
	{
		if (stack_nb->tab_a[1] > stack_nb->tab_a[2])
		{
			instruction_push_b(stack_nb, 1);
			boolean = 1;
		}
		if (stack_nb->tab_a[0] > stack_nb->tab_a[1])
			instruction_swap_a(stack_nb, 1);
		if (boolean)
			instruction_push_a(stack_nb, 1);
	}
	return (0);
}

int		sort_exception_5(t_checker *stack_nb)
{
	while (stack_nb->len_b != 2)
	{
		if (ft_min_tab(stack_nb->tab_a, stack_nb->len_a) == stack_nb->tab_a[0])
			instruction_push_b(stack_nb, 1);
		else
		{
			if (find_pos_nb(stack_nb->tab_a, stack_nb->len_a,
			ft_min_tab(stack_nb->tab_a, stack_nb->len_a)) > stack_nb->len_a / 2)
				instruction_reverse_a_r(stack_nb, 1);
			else
				instruction_rotate_a_r(stack_nb, 1);
		}
	}
	sort_exception_3(stack_nb);
	if (stack_nb->tab_b[0] < stack_nb->tab_b[1])
		instruction_swap_b(stack_nb, 1);
	instruction_push_a(stack_nb, 1);
	instruction_push_a(stack_nb, 1);
	return (0);
}

int		exceptions(t_checker *stack_nb)
{
	int res;

	res = 0;
	if (!check_sort_decreasing(stack_nb->tab_a, stack_nb->len_a))
		decreasing_to_increasing(stack_nb);
	if (stack_nb->len_a == 3 && check_sort(stack_nb->tab_a, stack_nb->len_a))
		sort_exception_3(stack_nb);
	if ((stack_nb->len_a == 5) && check_sort(stack_nb->tab_a, stack_nb->len_a))
		sort_exception_5(stack_nb);
	if ((res = check_sort_swap(stack_nb->tab_a, stack_nb->len_a)) > 0)
		sort_swap(stack_nb, res);
	return (0);
}
