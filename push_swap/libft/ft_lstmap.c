/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:47:13 by sayar             #+#    #+#             */
/*   Updated: 2021/11/17 13:04:47 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*i;
	t_list	*j;

	j = NULL;
	while (lst && f)
	{
		i = ft_lstnew((f)(lst->content));
		if (!i)
		{
			ft_lstclear(&j, del);
			return (NULL);
		}
		else
			ft_lstadd_back(&j, i);
		lst = lst->next;
	}
	return (j);
}
