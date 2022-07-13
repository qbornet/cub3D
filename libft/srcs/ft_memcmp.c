/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:09:52 by qbornet           #+#    #+#             */
/*   Updated: 2021/11/16 22:23:03 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n)
	{
		if (!((*(unsigned char *)s1) == (*(unsigned char *)s2)))
			break ;
		s1++;
		s2++;
		n--;
	}
	if (n)
		return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
	return (0);
}
