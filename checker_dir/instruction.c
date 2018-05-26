/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 19:23:49 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/23 21:51:21 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_word_count_for_split(char const *str, char c)
{
	int i;
	int count;
	int	count_next;

	i = 0;
	count = 0;
	count_next = 1;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			count++;
			count_next = 0;
		}
		else
			count_next = 1;
		i++;
	}
	if (count_next)
		count++;
	return (count);
}

int		need_more_lines_instruction(t_checker *checker, int i)
{
	if ((((!ft_strcmp(checker->instruction[i], "sa\n")) ||
		(!ft_strcmp(checker->instruction[i], "ss\n"))) && checker->len_a > 1))
		instruction_swap_a(checker, 0);
	if ((((!ft_strcmp(checker->instruction[i], "sb\n")) ||
		(!ft_strcmp(checker->instruction[i], "ss\n"))) && checker->len_b > 1))
		instruction_swap_b(checker, 0);
	if (((!ft_strcmp(checker->instruction[i], "pa\n")) && checker->len_b > 0))
		instruction_push_a(checker, 0);
	if (((!ft_strcmp(checker->instruction[i], "pb\n")) && checker->len_a > 0))
		instruction_push_b(checker, 0);
	if ((((!ft_strcmp(checker->instruction[i], "ra\n")) ||
		(!ft_strcmp(checker->instruction[i], "rr\n"))) && checker->len_a > 1))
		instruction_rotate_a_r(checker, 0);
	if ((((!ft_strcmp(checker->instruction[i], "rb\n")) ||
		(!ft_strcmp(checker->instruction[i], "rr\n"))) && checker->len_b > 1))
		instruction_rotate_b_r(checker, 0);
	if ((((!ft_strcmp(checker->instruction[i], "rra\n")) ||
		(!ft_strcmp(checker->instruction[i], "rrr\n"))) && checker->len_a > 1))
		instruction_reverse_a_r(checker, 0);
	if ((((!ft_strcmp(checker->instruction[i], "rrb\n")) ||
		(!ft_strcmp(checker->instruction[i], "rrr\n"))) && checker->len_b > 1))
		instruction_reverse_b_r(checker, 0);
	return (0);
}

int		make_instruction(t_checker *checker, int w_counts)
{
	int	i;

	i = 0;
	while (i < w_counts && checker->instruction[i] != NULL)
	{
		need_more_lines_instruction(checker, i);
		i++;
	}
	if (check_sort(checker->tab_a, checker->len_a) || checker->len_b)
	{
		free_instruction(checker, w_counts);
		ft_putstr("KO\n");
		return (1);
	}
	ft_putstr("OK\n");
	return (0);
}
