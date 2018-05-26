/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:52:53 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/23 21:42:05 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct	s_checker
{
	int			*tab_a;
	int			len_a;
	int			*tab_b;
	int			len_b;
	char		**instruction;

}				t_checker;

typedef	struct	s_algo
{
	int			*stack_sorted;
	int			pos_level;
	int			max_level;
	int			nb_level;
	int			average;
	int			min;
	int			nb_elem_level;

}				t_algo;

/*
		**	CHECKER_DIR	**
*/

/*
**	checker.c
*/
void			free_instruction(t_checker *checker, int w_counts);
int				check_instruction(t_checker *checker, int w_counts);
int				find_instruction(t_checker *checker);

/*
		**	COMMUN_DIR	**
*/

/*
**	check_sort_tab.c
*/
int				check_sort(int *tab, int len);
int				check_sort_decreasing(int *tab, int len);
int				decreasing_to_increasing(t_checker *checker);
int				*sort_int_tab(int *tab, int len);

/*
**	error.c
*/
int				check_doublon_max_min(int *tab, int len);
int				check_is_digit(int argc, char **argv, int j, int k);
int				check_error(int argc, char **argv, t_checker *checker);

/*
**	free_struct.c
*/
void			free_struct(t_checker *stack_nb);
/*
**	init_struct.c
*/
int				ft_word_count_for_split_without(char const *str, char c);
int				init_a(t_checker *checker, char **argv, int argc);
int				stock_args2(char **argv, int argc, t_checker *checker);
int				create_struct_check(int argc, char **argv, t_checker *checker);

/*
**	instruction_push.c
*/
int				instruction_push_a(t_checker *checker, int res);
int				instruction_push_b(t_checker *checker, int res);

/*
**	instruction_reverse.c
*/
int				instruction_reverse_a_r(t_checker *checker, int res);
int				instruction_reverse_b_r(t_checker *checker, int res);

/*
**	instruction_rotate.c
*/
int				instruction_rotate_a_r(t_checker *checker, int res);
int				instruction_rotate_b_r(t_checker *checker, int res);

/*
**	instruction_swap.c
*/
int				instruction_swap_a(t_checker *checker, int res);
int				instruction_swap_b(t_checker *checker, int res);

/*
**	instruction.c
*/
int				need_more_lines_instruction(t_checker *checker, int i);
int				make_instruction(t_checker *checker, int w_counts);
int				ft_word_count_for_split(char const *str, char c);

/*
		**	PUSH_SWAP_DIR	**
*/

/*
**	algo.c
*/
t_algo			init_struct_algo(t_checker *stack_nb);
int				find_med_end(t_checker *stack_nb);

/*
**	basics_fuctions.c
*/
int				find_pos_nb(int *tab, int len, int nb);
int				find_nb_push_a(int *tab, int len, int nb);
int				ft_second_max_tab(int *tab, int len);
int				ft_find_j(int len);

/*
**	exceptions.c
*/
int				sort_swap(t_checker *stack_nb, int pos);
int				check_sort_swap(int *tab, int len);
int				exceptions(t_checker *stack_nb);

/*
**	stack_a_b.c
*/
int				stack_b(t_checker *stack_nb, int moy, int max);
int				reverse_tab_b_max(t_checker *stack_nb, int boolean);
int				rotate_tab_b_max(t_checker *stack_nb, int boolean);
int				stack_a(t_checker *stack_nb);
#endif
