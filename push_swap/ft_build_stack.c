/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:02:51 by sayar             #+#    #+#             */
/*   Updated: 2022/03/14 09:41:34 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isstrint(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '\0')
		return (0);
	while (ft_isdigit(*s))
		s++;
	if (*s == '\0')
		return (1);
	return (0);
}

void	abort(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	parse_arg(t_stack **stack, char *arg)
{
	char	**tokens;
	int		i;
	int		nbr;
	t_stack	*new;

	i = 0;
	tokens = ft_split(arg, ' ');
	if (!tokens[0])
		abort();
	while (tokens[i])
		i++;
	while (i--)
	{
		if (!isstrint(tokens[i]))
			abort();
		errno = 0;
		nbr = ft_atoi(tokens[i]);
		if (errno == ERANGE)
			abort();
		new = ft_new_stack(nbr);
		new->next = *stack;
		*stack = new;
		free(tokens[i]);
	}
	free(tokens);
}

t_stack	*parse_argv(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = argc;
	while (i-- > 1)
		parse_arg(&stack, argv[i]);
	return (stack);
}
