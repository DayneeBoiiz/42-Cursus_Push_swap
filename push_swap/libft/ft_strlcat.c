/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:37:31 by sayar             #+#    #+#             */
/*   Updated: 2021/11/19 13:46:29 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	while (dest[i])
		i++;
	size = 0;
	while (src[size])
		size++;
	if (len <= i)
		size += len;
	else
		size += i;
	j = 0;
	if (len != 0)
	{
		while (src[j] && i < len - 1)
		{
			dest[i++] = src[j++];
		}
		dest[i] = '\0';
	}
	return (size);
}
