/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 02:42:43 by qbornet           #+#    #+#             */
/*   Updated: 2021/12/03 08:08:53 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*new_lst;
	t_list	*ret_lst;

	if (!lst)
		return (NULL);
	new_lst = ft_lstnew(f(lst->data));
	if (!new_lst)
		return (NULL);
	ret_lst = new_lst;
	while (lst->next)
	{
		lst = lst->next;
		new_lst = new_lst->next;
		new_lst = ft_lstnew(f(lst->data));
		if (!new_lst)
		{
			ft_lstclear(&ret_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&ret_lst, new_lst);
	}
	return (ret_lst);
}
