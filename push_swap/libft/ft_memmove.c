/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:00:39 by sayar             #+#    #+#             */
/*   Updated: 2021/11/24 09:36:43 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ndest;
	unsigned char	*nsrc;

	ndest = (unsigned char *) dest;
	nsrc = (unsigned char *) src;
	i = 0;
	if (ndest == NULL && nsrc == NULL)
		return (NULL);
	if (ndest > nsrc)
	{
		while (i < n)
		{
			ndest[n - 1] = nsrc[n - 1];
			n--;
		}
	}
	while (i < n)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	return (ndest);
}
