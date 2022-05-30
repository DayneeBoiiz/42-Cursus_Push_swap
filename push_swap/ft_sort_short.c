/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:28:03 by sayar             #+#    #+#             */
/*   Updated: 2022/03/08 13:48:03 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_inst(t_stack **inst, int n)
{
	t_stack		*e;
	t_stack		*new;

	e = *inst;
	if (e != NULL)
	{
		while (e->next != NULL)
			e = e->next;
		new = ft_new_stack(n);
		e->next = new;
	}
	else
		*inst = ft_new_stack(n);
}

void	ft_sort_two(t_com *begin)
{
	t_stack	*stack;

	stack = begin->a;
	if (stack->num > stack->next->num)
	{
		begin->a = ft_swap_stack(&begin->a);
		ft_inst(&begin->insta, 1);
	}
}

static void	ft_rotate(t_stack **elem, t_stack **proxi, t_com *begin)
{
	t_stack	*e;
	t_stack	*p;

	e = *elem;
	p = *proxi;
	if (e->num < p->num)
	{
		if (e->num < p->next->num)
		{
			begin->a = ft_reverse_rotate(&begin->a);
			ft_inst(&begin->insta, 7);
		}
		else
		{
			begin->a = ft_rotate_stack(&begin->a);
			ft_inst(&begin->insta, 5);
		}
	}
}

void	ft_sort_three(t_com *begin)
{
	t_stack	*stack;
	t_stack	*proxi;

	while (begin->a != NULL && ft_is_sort(&begin->a, 1) != 0)
	{
		stack = begin->a;
		proxi = stack->next;
		if (stack->num > proxi->num)
		{
			if (stack->num < proxi->next->num)
			{
				begin->a = ft_swap_stack(&begin->a);
				ft_inst(&begin->insta, 1);
			}
			else
			{
				begin->a = ft_rotate_stack(&begin->a);
				ft_inst(&begin->insta, 5);
			}
		}
		if (begin->a != NULL && ft_is_sort(&begin->a, 1) != 0)
			ft_rotate(&stack, &proxi, begin);
	}
}
