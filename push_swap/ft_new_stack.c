/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:08:34 by sayar             #+#    #+#             */
/*   Updated: 2022/02/22 17:08:34 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(int n)
{
	t_stack		*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		exit(0);
	new->num = n;
	new->next = NULL;
	return (new);
}
