/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:37:55 by qbornet           #+#    #+#             */
/*   Updated: 2021/11/07 19:33:14 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

static size_t	len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;

	i = -1;
	src_len = len((char *)src);
	while (++i < dstsize && *dst)
		dst++;
	if (i == dstsize)
		return (i + src_len);
	j = -1;
	while (src[++j] && j < (dstsize - i - 1))
		*dst++ = src[j];
	if (dstsize)
		*dst = '\0';
	return (i + src_len);
}
