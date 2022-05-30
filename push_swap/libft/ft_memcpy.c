/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:18:58 by sayar             #+#    #+#             */
/*   Updated: 2021/11/08 14:50:35 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*p;
	char	*b;

	p = (char *) dest;
	b = (char *) src;
	i = 0;
	if (p == NULL && b == NULL)
		return (NULL);
	while (i < n)
	{
		p[i] = b[i];
		i++;
	}
	return (dest);
}
