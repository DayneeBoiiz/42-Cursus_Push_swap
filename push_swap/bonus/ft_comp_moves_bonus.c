/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 00:01:39 by sayar             #+#    #+#             */
/*   Updated: 2022/03/10 14:46:45 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_comp_moves_2(char *str, t_com *begin)
{
	if (str && (ft_strcmp(str, "ra\n") == 0 || ft_strcmp(str, "rr\n") == 0))
		begin->a = ft_rotate_stack(&begin->a);
	else if (str && (ft_strcmp(str, "rra\n") == 0
			|| ft_strcmp(str, "rrr\n") == 0))
		begin->a = ft_reverse_rotate(&begin->a);
	else if (str && (ft_strcmp(str, "rb\n") == 0 || ft_strcmp(str, "rr\n") == 0))
		begin->b = ft_rotate_stack(&begin->b);
	else if (str && (ft_strcmp(str, "rrb\n") == 0
			|| ft_strcmp(str, "rrr\n") == 0))
		begin->b = ft_reverse_rotate(&begin->b);
	else if (str && (ft_strcmp(str, "ss\n") == 0))
	{
		begin->a = ft_swap_stack(&begin->a);
		begin->b = ft_swap_stack(&begin->b);
	}
	else if ((str && (ft_strcmp(str, "pa\n") == 0) && begin->b == NULL)
		|| (str && (ft_strcmp(str, "pb\n") == 0) && begin->a == NULL))
		return ;
	else
	{
		write (2, "Error\n", 6);
		exit (1);
	}
}

void	ft_comp_moves(char *str, t_com *begin)
{
	t_stack	*temp;

	if (str && (ft_strcmp(str, "sa\n") == 0))
		begin->a = ft_swap_stack(&begin->a);
	else if (str && (ft_strcmp(str, "sb\n") == 0))
		begin->b = ft_swap_stack(&begin->b);
	else if (str && (ft_strcmp(str, "pb\n") == 0))
	{
		temp = begin->a->next;
		begin->b = ft_push_stack(&begin->b, &begin->a);
		begin->a = temp;
	}
	else if (str && (ft_strcmp(str, "pa\n") == 0))
	{
		temp = begin->b->next;
		begin->a = ft_push_stack(&begin->a, &begin->b);
		begin->b = temp;
	}
	else
		ft_comp_moves_2(str, begin);
}
