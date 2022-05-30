/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:14:33 by sayar             #+#    #+#             */
/*   Updated: 2022/03/08 13:46:42 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_min(t_com *begin)
{
	int	len;

	len = ft_get_len(&begin->a);
	if (len > 1 && begin->a->num > begin->a->next->num)
	{
		begin->a = ft_swap_stack(&begin->a);
		ft_inst(&begin->insta, 1);
	}
	if (len > 2 && begin->a->next->num > begin->a->next->next->num)
	{
		begin->a = ft_rotate_stack(&begin->a);
		begin->a = ft_swap_stack(&begin->a);
		begin->a = ft_reverse_rotate(&begin->a);
		ft_inst(&begin->insta, 5);
		ft_inst(&begin->insta, 1);
		ft_inst(&begin->insta, 7);
	}
	if (len > 1 && begin->a->num > begin->a->next->num)
	{
		begin->a = ft_swap_stack(&begin->a);
		ft_inst(&begin->insta, 1);
	}
}

void	ft_sort_min_b(t_com *begin)
{
	int	len;

	len = ft_get_len(&begin->b);
	if (len > 1 && begin->b->num < begin->b->next->num)
	{
		begin->b = ft_swap_stack(&begin->b);
		ft_inst(&begin->insta, 2);
	}
	if (len > 2 && begin->b->next->num < begin->b->next->next->num)
	{
		begin->b = ft_rotate_stack(&begin->b);
		begin->b = ft_swap_stack(&begin->b);
		begin->b = ft_reverse_rotate(&begin->b);
		ft_inst(&begin->insta, 6);
		ft_inst(&begin->insta, 2);
		ft_inst(&begin->insta, 8);
	}
	if (len > 1 && begin->b->num < begin->b->next->num)
	{
		begin->b = ft_swap_stack(&begin->b);
		ft_inst(&begin->insta, 2);
	}
}
