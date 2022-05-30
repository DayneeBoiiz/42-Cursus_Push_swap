/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:12:33 by sayar             #+#    #+#             */
/*   Updated: 2021/11/12 15:01:54 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp1;

	temp = *lst;
	while (temp != NULL)
	{
		temp1 = *lst;
		temp = temp->next;
		del(temp1->content);
		free(temp1);
		*lst = temp;
	}
}
