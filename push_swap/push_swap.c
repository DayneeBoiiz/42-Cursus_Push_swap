/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 05:45:14 by sayar             #+#    #+#             */
/*   Updated: 2022/03/14 09:42:15 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doubles(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->num == temp->num)
				abort();
			temp = temp->next;
		}
		a = a->next;
	}
}

static t_com	*ft_init_stack(void)
{
	t_com	*begin;

	begin = (t_com *)malloc(sizeof(t_com));
	if (!begin)
		exit (1);
	ft_bzero(begin, sizeof(t_com));
	return (begin);
}

int	main(int ac, char **av)
{
	t_com	*begin;

	begin = ft_init_stack();
	begin->b = NULL;
	begin->insta = NULL;
	if (ac == 1)
		exit (0);
	begin->a = parse_argv(ac, av);
	check_doubles(begin->a);
	if (ft_is_sort(&begin->a, 1) != 0)
		ft_algo(begin);
	ft_lstdel1(&begin->a);
	ft_lstdel1(&begin->b);
	ft_lstdel1(&begin->insta);
	free(begin);
	return (0);
}
