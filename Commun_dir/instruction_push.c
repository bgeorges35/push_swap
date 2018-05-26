/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 22:59:38 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/23 18:22:04 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		instruction_push_a(t_checker *checker, int res)
{
	int tmp;

	tmp = checker->len_a;
	if (res && checker->len_b)
		ft_putendl("pa");
	while (tmp)
	{
		checker->tab_a[tmp] = checker->tab_a[tmp - 1];
		tmp--;
	}
	checker->tab_a[0] = checker->tab_b[0];
	checker->len_a++;
	while (tmp < checker->len_b - 1)
	{
		checker->tab_b[tmp] = checker->tab_b[tmp + 1];
		tmp++;
	}
	checker->len_b--;
	return (1);
}

int		instruction_push_b(t_checker *checker, int res)
{
	int	tmp;

	tmp = checker->len_b;
	if (res && checker->len_a)
		ft_putendl("pb");
	while (tmp)
	{
		checker->tab_b[tmp] = checker->tab_b[tmp - 1];
		tmp--;
	}
	checker->tab_b[0] = checker->tab_a[0];
	checker->len_b++;
	while (tmp < checker->len_a - 1)
	{
		checker->tab_a[tmp] = checker->tab_a[tmp + 1];
		tmp++;
	}
	checker->len_a--;
	return (1);
}
