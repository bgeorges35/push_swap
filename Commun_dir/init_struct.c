/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:31:12 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/23 20:25:07 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			ft_word_count_for_split_without(char const *str, char c)
{
	int		i;
	int		count;
	int		count_next;

	i = -1;
	count = 0;
	count_next = 1;
	while (str[++i] != '\0')
	{
		if (count_next && str[i] != c)
		{
			count++;
			count_next = 0;
		}
		if (str[i] == c)
			count_next = 1;
	}
	return (count);
}

int			init_a(t_checker *checker, char **argv, int argc)
{
	int		nb_arg;

	nb_arg = 0;
	checker->len_a = 0;
	while (argc > ++nb_arg)
		checker->len_a += ft_word_count_for_split_without(argv[nb_arg], ' ');
	if (!(checker->tab_a = (int*)malloc(sizeof(int) * checker->len_a)))
		return (1);
	if (!(checker->tab_b = (int*)malloc(sizeof(int) * checker->len_a)))
		return (1);
	return (0);
}

int			stock_args(t_checker *checker, int i_tab, char **str, int nb_count)
{
	int			i;
	long long	tmp;

	i = 0;
	while (nb_count > i_tab)
	{
		tmp = ft_atoll(str[i]);
		if (tmp <= INT_MAX && tmp >= INT_MIN)
			checker->tab_a[i_tab] = tmp;
		else
		{
			free(str[i]);
			return (-1);
		}
		free(str[i++]);
		i_tab++;
	}
	return (i_tab);
}

int			stock_args2(char **argv, int argc, t_checker *checker)
{
	char		**str;
	int			nb_count;
	int			nb_arg;
	int			i_tab;

	i_tab = 0;
	nb_count = 0;
	nb_arg = 0;
	if (init_a(checker, argv, argc))
		return (1);
	while (argc > ++nb_arg)
	{
		nb_count += ft_word_count_for_split_without(argv[nb_arg], ' ');
		str = ft_strsplit_without(argv[nb_arg], ' ');
		if ((i_tab = stock_args(checker, i_tab, str, nb_count)) < 0)
		{
			free(str);
			ft_putendl_fd("Error", 2);
			return (1);
		}
		free(str);
	}
	return (0);
}

int			create_struct_check(int argc, char **argv, t_checker *checker)
{
	if (stock_args2(argv, argc, checker))
		return (1);
	checker->len_b = 0;
	return (0);
}
