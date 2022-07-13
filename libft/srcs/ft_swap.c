/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:21:36 by qbornet           #+#    #+#             */
/*   Updated: 2022/03/03 09:56:40 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

void	ft_swap(void *a, void *b, size_t size)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*q;
	unsigned char	temp;

	if (!a || !b || size <= 0)
		return ;
	i = 0;
	p = a;
	q = b;
	while (i < size)
	{
		temp = p[i];
		p[i] = q[i];
		q[i] = temp;
		i++;
	}
}
