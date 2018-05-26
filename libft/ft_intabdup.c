/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intabdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:26:36 by bgeorges          #+#    #+#             */
/*   Updated: 2018/05/22 14:47:06 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intabdup(int *tab, int len)
{
	int *new;
	int i;

	i = 0;
	if (!(new = (int*)malloc(sizeof(int) * len)))
		return (0);
	while (len > i)
	{
		new[i] = tab[i];
		i++;
	}
	return (new);
}
