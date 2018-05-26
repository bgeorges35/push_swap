/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:22:11 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/13 15:18:57 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		check_doublon_max_min(int *tab, int len)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < len)
	{
		while (++j < len)
		{
			if (tab[i] == tab[j] && i != j)
			{
				ft_putendl_fd("Error", 2);
				return (1);
			}
		}
		j = -1;
	}
	return (0);
}

int		check_is_digit(int argc, char **argv, int j, int k)
{
	char	**str;
	int		i;

	while (argc > ++k)
	{
		j += ft_word_count_for_split_without(argv[k], ' ');
		i = 0;
		str = ft_strsplit_without(argv[k], ' ');
		while (j > i)
		{
			if (ft_str_isdigit(str[i]))
			{
				free(str[i]);
				free(str);
				ft_putendl_fd("Error", 2);
				return (1);
			}
			free(str[i++]);
		}
		free(str);
		j = 0;
	}
	return (0);
}

int		check_error(int argc, char **argv, t_checker *checker)
{
	if (argc < 2)
		return (1);
	if (check_is_digit(argc, argv, 0, 0) ||
			check_doublon_max_min(checker->tab_a, checker->len_a))
		return (1);
	return (0);
}
