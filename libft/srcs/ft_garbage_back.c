/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 07:22:53 by qbornet           #+#    #+#             */
/*   Updated: 2022/03/13 21:17:24 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

int	ft_garbage_back(t_list **current, void *data, void (*del) (void *))
{
	t_list	*head;

	if (!current || !data)
		return (0);
	head = *current;
	if (!head)
	{
		*current = ft_lstnew(data);
		if (!*current)
		{
			del(data);
			return (-1);
		}
		return (0);
	}
	while (head->next)
		head = head->next;
	head->next = ft_lstnew(data);
	if (!head->next)
	{
		del(data);
		return (-1);
	}
	return (0);
}
