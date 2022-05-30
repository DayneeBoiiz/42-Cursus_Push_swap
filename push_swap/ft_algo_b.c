/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:38:13 by sayar             #+#    #+#             */
/*   Updated: 2022/03/08 13:05:07 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_med_sort(t_com *begin, int n, int *r, int *p)
{
	int		i;
	int		median;
	t_stack	*temp;

	i = 0;
	median = ft_median(&begin->b, 2, n);
	while (ft_compare_med(begin, n - i, median, 2) && i++ < n)
	{
		if (begin->b->num > median)
		{
			temp = begin->b->next;
			begin->a = ft_push_stack(&begin->a, &begin->b);
			begin->b = temp;
			ft_inst(&begin->insta, 3);
			*p = *p + 1;
		}
		else
		{
			begin->b = ft_rotate_stack(&begin->b);
			ft_inst(&begin->insta, 6);
			*r = *r + 1;
		}
	}
}

static void	ft_place(t_com *begin, int *r)
{
	int	blen;

	blen = ft_get_len(&begin->b);
	if (*r > (blen / 2) && blen > 3)
	{
		while (*r < blen)
		{
			begin->b = ft_rotate_stack(&begin->b);
			ft_inst(&begin->insta, 6);
			*r = *r + 1;
		}
	}
	else if (blen > 3)
	{
		while (*r)
		{
			begin->b = ft_reverse_rotate(&begin->b);
			ft_inst(&begin->insta, 8);
			*r = *r - 1;
		}
	}
}

void	ft_algo_b(t_com *begin, int n)
{
	int		r;
	int		p;
	t_stack	*temp;

	r = 0;
	p = 0;
	if (n <= 3)
	{
		ft_sort_min_b(begin);
		return ;
	}
	ft_med_sort(begin, n, &r, &p);
	ft_algo_a(begin, p);
	ft_place(begin, &r);
	ft_algo_b(begin, n - p);
	if (begin->b != NULL && ft_is_sort(&begin->b, 2) == 1)
	{
		while (p--)
		{
			temp = begin->a->next;
			begin->b = ft_push_stack(&begin->b, &begin->a);
			begin->a = temp;
			ft_inst(&begin->insta, 4);
		}
	}
}
