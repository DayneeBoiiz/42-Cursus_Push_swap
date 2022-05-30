/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:36:09 by sayar             #+#    #+#             */
/*   Updated: 2021/11/06 11:17:52 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	num, size_t	size)
{
	char	*p;

	p = malloc (num * size);
	if (p != NULL)
	{
		ft_bzero(p, num * size);
		return (p);
	}
	return (0);
}
