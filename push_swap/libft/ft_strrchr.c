/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:00:57 by sayar             #+#    #+#             */
/*   Updated: 2021/11/08 10:37:10 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*nstr;
	char	p;
	int		len;

	nstr = (char *) str;
	p = (char) c;
	len = ft_strlen(nstr);
	while (nstr[len] != p)
	{
		if (len == 0)
			return (0);
		len--;
	}
	return (&nstr[len]);
}
