/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:16:10 by sayar             #+#    #+#             */
/*   Updated: 2021/11/09 11:15:31 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*nstr1;
	unsigned char	*nstr2;
	size_t			i;

	nstr1 = (unsigned char *) str1;
	nstr2 = (unsigned char *) str2;
	i = 0;
	while (n > i)
	{
		if (nstr1[i] != nstr2[i])
			return (nstr1[i] - nstr2[i]);
		i++;
	}
	return (0);
}
