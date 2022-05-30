/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:50:19 by sayar             #+#    #+#             */
/*   Updated: 2022/03/10 14:44:00 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

static void	ft_clear(t_com *begin)
{
	ft_lstdel1(&begin->a);
	ft_lstdel1(&begin->b);
	free(begin);
}

int	main(int ac, char **av)
{
	t_stack	*ab;
	t_com	*begin;
	char	*line;

	if (ac == 1)
		exit (0);
	ab = parse_argv(ac, av);
	begin = ft_init_stack();
	begin->b = NULL;
	begin->a = ab;
	check_doubles(begin->a);
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		ft_comp_moves(line, begin);
	}
	free(line);
	ft_check_stack(&begin->a, &begin->b);
	ft_clear(begin);
	return (0);
}
