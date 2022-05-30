/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:23:39 by sayar             #+#    #+#             */
/*   Updated: 2021/11/11 11:14:45 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	check(int n, int *multi)
{
	int	count;
	int	extra;

	*multi = 1;
	if (n < 0)
		extra = 2;
	else
		extra = 1;
	count = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		*multi = *multi * 10;
		count++;
	}
	count++;
	return (count + extra);
}

char	*ft_itoa(int n)
{
	int		multi;
	char	*res;
	int		i;
	long	nb;

	nb = (long) n;
	res = (char *)malloc(sizeof(char) * check(nb, &multi));
	if (res == NULL)
		return (NULL);
	if (nb == 0)
		return (ft_strcpy(res, "0"));
	i = 0;
	if (nb < 0)
	{
		res[i++] = '-';
		nb = nb * -1;
	}
	while (multi != 0)
	{
		res[i++] = nb / multi + '0';
		nb = nb % multi;
		multi = multi / 10;
	}
	res[i] = '\0';
	return (res);
}
