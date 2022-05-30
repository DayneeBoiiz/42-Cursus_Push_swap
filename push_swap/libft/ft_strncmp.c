/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:48:30 by sayar             #+#    #+#             */
/*   Updated: 2021/11/08 16:58:05 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*nstr1;
	unsigned char	*nstr2;

	nstr1 = (unsigned char *) str1;
	nstr2 = (unsigned char *) str2;
	i = 0;
	if (!n)
		return (0);
	if ((!nstr1[i] || !nstr2[i]) && n)
		return (nstr1[i] - nstr2[i]);
	while (i < n)
	{
		if (nstr1[i] != nstr2[i] || !nstr1[i] || !nstr2[i])
			return (nstr1[i] - nstr2[i]);
		i++;
	}
	return (0);
}
