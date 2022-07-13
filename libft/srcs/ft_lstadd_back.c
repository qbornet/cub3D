/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 02:07:43 by qbornet           #+#    #+#             */
/*   Updated: 2021/12/03 07:59:15 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*head;

	if (!alst || !new)
		return ;
	head = *alst;
	if (!head)
	{
		*alst = new;
		return ;
	}
	while (head->next)
		head = head->next;
	head->next = new;
}
