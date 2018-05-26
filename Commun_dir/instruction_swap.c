/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 22:56:52 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/13 15:12:10 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		instruction_swap_a(t_checker *checker, int res)
{
	int		tmp;

	tmp = checker->tab_a[0];
	checker->tab_a[0] = checker->tab_a[1];
	checker->tab_a[1] = tmp;
	if (res == 1)
		ft_putendl("sa");
	else if (res == 2)
		ft_putendl("ss");
	return (1);
}

int		instruction_swap_b(t_checker *checker, int res)
{
	int		tmp;

	tmp = checker->tab_b[0];
	checker->tab_b[0] = checker->tab_b[1];
	checker->tab_b[1] = tmp;
	if (res == 1)
		ft_putendl("sb");
	return (1);
}
