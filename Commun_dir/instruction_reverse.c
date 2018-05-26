/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 23:06:29 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/23 18:21:03 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		instruction_reverse_a_r(t_checker *checker, int res)
{
	int	tmp;
	int	count;

	count = checker->len_a - 1;
	tmp = checker->tab_a[checker->len_a - 1];
	while (count)
	{
		checker->tab_a[count] = checker->tab_a[count - 1];
		count--;
	}
	checker->tab_a[0] = tmp;
	if (res == 1)
		ft_putendl("rra");
	else if (res == 2)
		ft_putendl("rrr");
	return (1);
}

int		instruction_reverse_b_r(t_checker *checker, int res)
{
	int	tmp;
	int	count;

	count = checker->len_b - 1;
	tmp = checker->tab_b[checker->len_b - 1];
	while (count)
	{
		checker->tab_b[count] = checker->tab_b[count - 1];
		count--;
	}
	checker->tab_b[0] = tmp;
	if (res == 1)
		ft_putendl("rrb");
	return (1);
}
