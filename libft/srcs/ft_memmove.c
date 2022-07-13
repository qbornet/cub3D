/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 03:39:50 by qbornet           #+#    #+#             */
/*   Updated: 2021/11/07 08:27:00 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;

	if (!dst && !src && len >= 1)
		return (NULL);
	ptr_dst = dst;
	ptr_src = src;
	if (ptr_src < ptr_dst)
	{
		ptr_dst += len;
		ptr_src += len;
		while (len--)
			*--ptr_dst = *--ptr_src;
	}
	else
		while (len--)
			*ptr_dst++ = *ptr_src++;
	return (dst);
}
