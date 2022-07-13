/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:54:16 by qbornet           #+#    #+#             */
/*   Updated: 2021/11/25 08:35:02 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (src[ret])
		ret++;
	if (dstsize == 0)
		return (ret);
	while (src[i] && i < (dstsize - 1))
		*dst++ = src[i++];
	*dst = '\0';
	return (ret);
}
