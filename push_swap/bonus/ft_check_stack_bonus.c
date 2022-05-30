/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:14:59 by sayar             #+#    #+#             */
/*   Updated: 2022/03/10 14:56:29 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	print_error(void)
{
	ft_putstr_fd("KO\n", 1);
	exit(1);
}

void	ft_check_stack(t_stack **a, t_stack **b)
{
	t_stack	*elem;
	int		n;

	elem = *a;
	if (elem != NULL)
	{
		n = elem->num;
		elem = elem->next;
	}
	while (elem != NULL)
	{
		if (elem->num > n)
		{
			n = elem->num;
			elem = elem->next;
		}
		else
			print_error();
	}
	elem = *b;
	if (elem == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
