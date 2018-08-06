/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:27:00 by ysushkov          #+#    #+#             */
/*   Updated: 2018/03/29 16:58:05 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *temp1;
	t_list *temp2;

	if (!lst || !f)
		return (NULL);
	temp1 = f(lst);
	if ((new = ft_lstnew(temp1->content, temp1->content_size)))
	{
		temp2 = new;
		lst = lst->next;
		while (lst)
		{
			temp1 = f(lst);
			temp2->next = ft_lstnew(temp1->content, temp1->content_size);
			temp2 = temp2->next;
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
