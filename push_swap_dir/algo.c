/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 12:56:04 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/13 14:29:54 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_algo	init_struct_algo(t_checker *stack_nb)
{
	t_algo	variables;

	variables.nb_level = ft_find_j(stack_nb->len_a);
	variables.stack_sorted = ft_intabdup(stack_nb->tab_a, stack_nb->len_a);
	variables.stack_sorted =
		sort_int_tab(variables.stack_sorted, stack_nb->len_a);
	variables.pos_level = stack_nb->len_a / variables.nb_level;
	variables.nb_elem_level = variables.pos_level;
	variables.min = variables.stack_sorted[0];
	variables.max_level = 0;
	return (variables);
}

int		find_med_end(t_checker *stack_nb)
{
	t_algo	variables;
	int		i;

	i = 0;
	variables = init_struct_algo(stack_nb);
	while (i < variables.nb_level)
	{
		variables.max_level = variables.stack_sorted[variables.pos_level - 1];
		i++;
		if (i == variables.nb_level && variables.max_level !=
		ft_max_tab(stack_nb->tab_a, stack_nb->len_a))
			variables.max_level = ft_max_tab(stack_nb->tab_a, stack_nb->len_a);
		variables.average = (variables.max_level + variables.min) / 2;
		stack_b(stack_nb, variables.average, variables.max_level);
		variables.min = variables.max_level;
		variables.pos_level += variables.nb_elem_level;
	}
	stack_a(stack_nb);
	free(variables.stack_sorted);
	return (0);
}
