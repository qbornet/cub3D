/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:16:38 by qbornet           #+#    #+#             */
/*   Updated: 2021/12/03 09:31:25 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strchr_null(const char *s, int c)
{
	unsigned char	cmp;

	if (!s)
		return (NULL);
	cmp = c;
	while (*s != cmp)
		if (!*s++)
			return (NULL);
	return ((char *)s);
}
