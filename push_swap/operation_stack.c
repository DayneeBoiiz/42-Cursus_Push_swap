/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:26:57 by sayar             #+#    #+#             */
/*   Updated: 2022/03/08 13:48:37 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_rotate_stack(t_stack **begin)
{
	t_stack	*elem;
	int		temp;

	elem = *begin;
	temp = elem->num;
	if (elem == NULL || elem->next == NULL)
		return (*begin);
	while (elem->next != NULL)
	{
		elem->num = elem->next->num;
		elem = elem->next;
	}
	elem->num = temp;
	return (*begin);
}

void	ft_rr(t_stack **stack)
{
	t_stack	*elem;
	int		temp;
	int		temp2;
	int		i;

	elem = *stack;
	i = 0;
	while (elem != NULL)
	{
		if (i % 2 != 0)
		{
			temp2 = elem->num;
			elem->num = temp;
		}
		else if (i % 2 == 0)
		{
			temp = elem->num;
			elem->num = temp2;
		}
		i++;
		elem = elem->next;
	}
}

int	ft_compare_med(t_com *begin, int n, int median, int stack)
{
	int		i;
	t_stack	*elem;

	i = 0;
	if (stack == 1)
		elem = begin->a;
	else if (stack == 2)
		elem = begin->b;
	while (i < n)
	{
		if (stack == 1 && elem->num < median)
			return (1);
		if (stack == 2 && elem->num > median)
			return (1);
		i++;
		elem = elem->next;
	}
	return (0);
}

t_stack	*ft_push_stack(t_stack **b, t_stack **a)
{
	t_stack	*elem;

	elem = *a;
	if (elem == NULL)
		return (*b);
	elem->next = *b;
	*b = elem;
	return (*b);
}
