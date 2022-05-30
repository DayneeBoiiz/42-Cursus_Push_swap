/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:38:33 by sayar             #+#    #+#             */
/*   Updated: 2022/03/10 14:23:33 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_check_doubles(int *tab, int i, int n)
// {
// 	int		j;

// 	if (i != 0)
// 		j = i - 1;
// 	else
// 		j = 0;
// 	while (j >= 0)
// 	{
// 		if (tab[i] == tab[j] && n != 1 && j != i)
// 		{
// 			write(2, "Err11or\n", 8);
// 			exit(1);
// 		}
// 		j--;
// 	}
// }

void	ft_lstdel1(t_stack	**begin)
{
	t_stack	*temp;

	while (*begin != NULL)
	{
		temp = (*begin)->next;
		free(*begin);
		*begin = temp;
	}
	free(*begin);
}

void	str_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}
