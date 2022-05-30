/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:06:15 by sayar             #+#    #+#             */
/*   Updated: 2021/11/23 17:42:04 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*nstr;
	char	p;

	nstr = (char *) str;
	p = (char) c;
	i = 0;
	while (i < n)
	{
		if (nstr[i] == p)
			return (&nstr[i]);
		i++;
	}
	return (0);
}
