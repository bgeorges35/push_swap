/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 23:01:58 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/23 18:20:53 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		instruction_rotate_a_r(t_checker *checker, int res)
{
	int		tmp;
	int		count;

	count = 0;
	tmp = checker->tab_a[0];
	while (count < checker->len_a - 1)
	{
		checker->tab_a[count] = checker->tab_a[count + 1];
		count++;
	}
	checker->tab_a[checker->len_a - 1] = tmp;
	if (res == 1)
		ft_putendl("ra");
	else if (res == 2)
		ft_putendl("rr");
	return (1);
}

int		instruction_rotate_b_r(t_checker *checker, int res)
{
	int		count;
	int		tmp;

	count = 0;
	tmp = checker->tab_b[0];
	while (count < checker->len_b - 1)
	{
		checker->tab_b[count] = checker->tab_b[count + 1];
		count++;
	}
	checker->tab_b[checker->len_b - 1] = tmp;
	if (res == 1)
		ft_putendl("rb");
	return (1);
}
