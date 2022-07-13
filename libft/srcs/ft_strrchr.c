/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:06:21 by qbornet           #+#    #+#             */
/*   Updated: 2021/11/06 06:20:53 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	if (*s == (char)c)
		ret = (char *)s;
	while (*s++)
		if (*s == (char)c)
			ret = (char *)s;
	return (ret);
}
