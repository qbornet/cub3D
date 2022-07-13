/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 02:11:33 by qbornet           #+#    #+#             */
/*   Updated: 2021/12/03 08:06:03 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

void	ft_lstdelone(t_list *lst, void (*del) (void *))
{
	if (!del || !lst)
		return ;
	del(lst->data);
	free(lst);
}
