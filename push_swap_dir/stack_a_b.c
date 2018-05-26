/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:52:30 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/13 15:20:13 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		stack_b(t_checker *stack_nb, int moy, int max)
{
	while (find_nb_push_a(stack_nb->tab_a, stack_nb->len_a, max) > 0)
	{
		if (stack_nb->tab_a[0] <= max && stack_nb->tab_a[0] < moy)
		{
			instruction_push_b(stack_nb, 1);
			if (stack_nb->len_b > 1)
				instruction_rotate_b_r(stack_nb, 1);
		}
		else if (stack_nb->tab_a[0] <= max && stack_nb->tab_a[0] >= moy)
		{
			instruction_push_b(stack_nb, 1);
		}
		else
			instruction_rotate_a_r(stack_nb, 1);
	}
	return (0);
}

int		reverse_tab_b_max(t_checker *stack_nb, int boolean)
{
	while (ft_max_tab(stack_nb->tab_b, stack_nb->len_b) != stack_nb->tab_b[0])
	{
		if (ft_second_max_tab(stack_nb->tab_b, stack_nb->len_b) ==
			stack_nb->tab_b[0] && stack_nb->len_b > 1 && !boolean)
		{
			boolean = 1;
			instruction_push_a(stack_nb, 1);
		}
		else
			instruction_reverse_b_r(stack_nb, 1);
	}
	return (boolean);
}

int		rotate_tab_b_max(t_checker *stack_nb, int boolean)
{
	while (ft_max_tab(stack_nb->tab_b, stack_nb->len_b) != stack_nb->tab_b[0])
	{
		if (ft_second_max_tab(stack_nb->tab_b, stack_nb->len_b) ==
			stack_nb->tab_b[0] && stack_nb->len_b > 1 && !boolean)
		{
			boolean = 1;
			instruction_push_a(stack_nb, 1);
		}
		else
			instruction_rotate_b_r(stack_nb, 1);
	}
	return (boolean);
}

int		stack_a(t_checker *stack_nb)
{
	int		max;
	int		boolean;

	while (stack_nb->len_b)
	{
		boolean = 0;
		max = find_pos_nb(stack_nb->tab_b, stack_nb->len_b,
			ft_max_tab(stack_nb->tab_b, stack_nb->len_b));
		if (max > stack_nb->len_b / 2)
			boolean = reverse_tab_b_max(stack_nb, boolean);
		else
			boolean = rotate_tab_b_max(stack_nb, boolean);
		instruction_push_a(stack_nb, 1);
		if (boolean)
			instruction_swap_a(stack_nb, 1);
	}
	return (0);
}
