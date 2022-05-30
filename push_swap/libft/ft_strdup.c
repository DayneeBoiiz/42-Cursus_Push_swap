/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srtdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:10:38 by sayar             #+#    #+#             */
/*   Updated: 2021/11/05 16:37:18 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*str;
	char	*nsrc;

	i = 0;
	nsrc = (char *) src;
	len = ft_strlen(nsrc);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	while (nsrc[i])
	{
		str[i] = nsrc[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
