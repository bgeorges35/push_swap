/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 12:00:49 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/26 15:15:15 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_instruction(t_checker *checker, int w_counts)
{
	int		i;

	i = 0;
	while (i < w_counts && checker->instruction[i] != NULL)
		free(checker->instruction[i++]);
	free(checker->instruction);
	free_struct(checker);
}

int		check_instruction(t_checker *checker, int w_counts)
{
	int	i;

	i = 0;
	while (i < w_counts && checker->instruction[i] != NULL)
	{
		if (!ft_strcmp(checker->instruction[i], "sa\n") ||
			!ft_strcmp(checker->instruction[i], "sb\n") ||
			!ft_strcmp(checker->instruction[i], "ss\n") ||
			!ft_strcmp(checker->instruction[i], "pa\n") ||
			!ft_strcmp(checker->instruction[i], "pb\n") ||
			!ft_strcmp(checker->instruction[i], "ra\n") ||
			!ft_strcmp(checker->instruction[i], "rb\n") ||
			!ft_strcmp(checker->instruction[i], "rr\n") ||
			!ft_strcmp(checker->instruction[i], "rra\n") ||
			!ft_strcmp(checker->instruction[i], "rrb\n") ||
			!ft_strcmp(checker->instruction[i], "rrr\n") ||
			!ft_strcmp(checker->instruction[i], ""))
			i++;
		else
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
	}
	return (0);
}

int		find_instruction(t_checker *checker)
{
	char	*str;
	char	*tmp;
	int		ret;
	int		words_count;

	str = ft_strnew(2);
	if (ret = read(0, str, 1) < 0)
		return (-1);
	str[ret] = '\0';
	tmp = ft_strnew(2);
	if (ret)
	{
		while ((ret = read(0, tmp, 1)) > 0)
		{
			tmp[ret] = '\0';
			str = ft_strjoin_free(str, tmp);
		}
	}
	if (ret < 0)
		return (-1);
	checker->instruction = ft_strsplit(str, '\n');
	words_count = ft_word_count_for_split(str, '\n');
	free(tmp);
	free(str);
	return (words_count);
}

int		main(int argc, char **argv)
{
	t_checker	*checker;
	int			w_counts;

	if (!(checker = (t_checker*)malloc(sizeof(*checker))))
		return (1);
	if (create_struct_check(argc, argv, checker))
	{
		free_struct(checker);
		return (1);
	}
	if (check_error(argc, argv, checker))
	{
		free_struct(checker);
		return (1);
	}
	if (w_counts = find_instruction(checker) < 0)
	{
		free_instruction(checker, w_counts);
		return (1);
	}
	if (check_instruction(checker, w_counts))
	{
		free_instruction(checker, w_counts);
		return (1);
	}
	if (make_instruction(checker, w_counts))
		return (1);
	free_instruction(checker, w_counts);
	return (0);
}
