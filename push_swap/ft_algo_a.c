/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:55:43 by sayar             #+#    #+#             */
/*   Updated: 2022/03/08 13:05:00 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_med_sort(t_com *begin, int n, int *r, int *p)
{
	int		i;
	int		median;
	t_stack	*temp;

	i = 0;
	median = ft_median(&begin->a, 1, n);
	while (ft_compare_med(begin, n - i, median, 1) && i++ < n)
	{
		if (begin->a->num < median)
		{
			temp = begin->a->next;
			begin->b = ft_push_stack(&begin->b, &begin->a);
			begin->a = temp;
			ft_inst(&begin->insta, 4);
			*p = *p + 1;
		}
		else
		{
			begin->a = ft_rotate_stack(&begin->a);
			ft_inst(&begin->insta, 5);
			*r = *r + 1;
		}
	}
}

static void	ft_place(t_com *begin, int *r)
{
	int	len;

	len = ft_get_len(&begin->a);
	if (*r > (len / 2) && len > 3)
	{
		while (*r < len)
		{
			begin->a = ft_rotate_stack(&begin->a);
			ft_inst(&begin->insta, 5);
			*r = *r + 1;
		}
	}
	else if (len > 3)
	{
		while (*r)
		{
			begin->a = ft_reverse_rotate(&begin->a);
			ft_inst(&begin->insta, 7);
			*r = *r - 1;
		}
	}
}

void	ft_algo_a(t_com *begin, int n)
{
	int		r;
	int		p;
	t_stack	*temp;

	r = 0;
	p = 0;
	if (n <= 3)
	{
		ft_sort_min(begin);
		return ;
	}
	if (begin->a != NULL && ft_is_sort(&begin->a, 1) == 0)
		return ;
	ft_med_sort(begin, n, &r, &p);
	ft_place(begin, &r);
	ft_algo_a(begin, (n - p));
	ft_algo_b(begin, p);
	while (p-- && begin->b != NULL)
	{
		temp = begin->b->next;
		begin->a = ft_push_stack(&begin->a, &begin->b);
		begin->b = temp;
		ft_inst(&begin->insta, 3);
	}
}
