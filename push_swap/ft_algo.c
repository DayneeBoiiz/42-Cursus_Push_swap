/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:29:43 by sayar             #+#    #+#             */
/*   Updated: 2022/03/08 13:05:12 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_len(t_stack	**begin)
{
	t_stack	*elem;
	int		i;

	i = 0;
	elem = *begin;
	while (elem != NULL)
	{
		i++;
		elem = elem->next;
	}
	return (i);
}

int	ft_is_sort(t_stack **begin, int stack)
{
	int		i;
	t_stack	*e;
	t_stack	*next;

	i = 0;
	e = *begin;
	next = e->next;
	while (i < ft_get_len(begin) - 1)
	{
		if ((e->num < next->num && stack == 1)
			|| (e->num > next->num && stack == 2))
		{
			e = e->next;
			next = e->next;
			i++;
		}
		else
			return (1);
	}
	return (0);
}

int	ft_algo(t_com *begin)
{
	int	n;

	n = ft_get_len(&begin->a);
	if (n == 1)
		return (0);
	else if (n == 2)
		ft_sort_two(begin);
	else if (n == 3)
		ft_sort_three(begin);
	else
		ft_algo_a(begin, ft_get_len(&begin->a));
	ft_print_insta(begin);
	return (0);
}
