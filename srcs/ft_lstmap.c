/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelorme <adelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:34:48 by adelorme          #+#    #+#             */
/*   Updated: 2019/11/27 12:35:36 by adelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*previous;
	t_list	*new;
	t_list	*tmp;

	head = NULL;
	previous = NULL;
	if (!f)
		return (lst);
	while (lst)
	{
		tmp = (*f)(lst);
		new = ft_lstnew(tmp->content, tmp->content_size);
		if (!new)
			return (NULL);
		if (!head)
			head = new;
		if (previous)
			previous->next = new;
		previous = new;
		lst = lst->next;
	}
	return (head);
}
