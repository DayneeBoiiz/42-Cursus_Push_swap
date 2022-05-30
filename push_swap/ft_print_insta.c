/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_insta.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:47:44 by sayar             #+#    #+#             */
/*   Updated: 2022/03/09 18:00:10 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_instruction(t_stack *elem)
{
	if (elem->num == 1)
		ft_putstr_fd("sa\n", 1);
	else if (elem->num == 2)
		ft_putstr_fd("sb\n", 1);
	if (elem->num == 3)
		ft_putstr_fd("pa\n", 1);
	else if (elem->num == 4)
		ft_putstr_fd("pb\n", 1);
	else if (elem->num == 5)
		ft_putstr_fd("ra\n", 1);
	else if (elem->num == 6)
		ft_putstr_fd("rb\n", 1);
	else if (elem->num == 7)
		ft_putstr_fd("rra\n", 1);
	else if (elem->num == 8)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_print_insta(t_com *begin)
{
	t_stack		*e;
	t_stack		*proxi;

	e = begin->insta;
	proxi = NULL;
	while (e != NULL)
	{
		if (e->next != NULL)
			proxi = e->next;
		if (e->num == 1 && proxi && proxi->num != 2)
			ft_putstr_fd("sa\n", 1);
		else if (e->num == 2 && proxi && proxi->num != 1)
			ft_putstr_fd("sb\n", 1);
		else if ((e->num == 1 && proxi && proxi->num == 2)
			|| (e->num == 2 && proxi && proxi->num == 1))
		{
			ft_putstr_fd("ss\n", 1);
			e = e->next;
		}
		else
			ft_print_instruction(e);
		e = e->next;
	}
}
