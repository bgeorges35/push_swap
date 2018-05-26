/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 18:06:55 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/13 15:42:31 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_checker	*stack_nb;

	if (!(stack_nb = (t_checker*)malloc(sizeof(*stack_nb))))
		return (0);
	if (create_struct_check(argc, argv, stack_nb))
	{
		free_struct(stack_nb);
		return (0);
	}
	if (check_error(argc, argv, stack_nb))
	{
		free_struct(stack_nb);
		return (0);
	}
	if (check_sort(stack_nb->tab_a, stack_nb->len_a) && stack_nb->len_a)
		exceptions(stack_nb);
	if (check_sort(stack_nb->tab_a, stack_nb->len_a) && stack_nb->len_a)
		find_med_end(stack_nb);
	free_struct(stack_nb);
	return (0);
}
