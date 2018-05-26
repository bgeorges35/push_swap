/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:41:22 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/11 16:19:35 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_struct(t_checker *stack_nb)
{
	free(stack_nb->tab_a);
	free(stack_nb->tab_b);
	free(stack_nb);
}
