/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:32:29 by sayar             #+#    #+#             */
/*   Updated: 2022/03/08 13:49:25 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_swap_stack(t_stack **begin)
{
	t_stack	*elem;
	int		temp;

	elem = *begin;
	if (elem == NULL || elem->next == NULL)
		return (*begin);
	temp = elem->next->num;
	elem->next->num = elem->num;
	elem->num = temp;
	*begin = elem;
	return (*begin);
}

t_stack	*ft_reverse_rotate(t_stack **begin)
{
	t_stack	*elem;
	int		temp;

	elem = *begin;
	if (elem == NULL || elem->next == NULL)
		return (*begin);
	while (elem->next != NULL)
		elem = elem->next;
	temp = elem->num;
	ft_rr(begin);
	elem = *begin;
	elem->num = temp;
	return (*begin);
}

void	ft_sort_tab(int *tab, int len)
{
	int	i;
	int	temp;
	int	n;

	i = 0;
	n = i;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = n;
		}
		else
			i++;
	}
	i = n;
}

int	ft_median(t_stack **begin, int stack, int n)
{
	t_stack	*temp;
	int		i;
	int		*tab;
	int		len;
	int		median;

	i = 0;
	len = n;
	tab = (int *)malloc(sizeof(int) * (len + 1));
	if (!tab)
		exit (1);
	temp = *begin;
	while (i < len)
	{
		tab[i] = temp->num;
		i++;
		temp = temp->next;
	}
	ft_sort_tab(tab, len);
	if (stack == 2 && len % 2 == 0)
		median = tab[(len / 2) - 1];
	else
		median = tab[(len / 2)];
	free(tab);
	return (median);
}
