/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 03:42:43 by qbornet           #+#    #+#             */
/*   Updated: 2021/11/16 05:29:05 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	ft_strmapi_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int		i;
	int		j;
	char	*dst;

	i = -1;
	j = 0;
	if (!s || !f)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strmapi_strlen(s) + 1));
	if (!dst)
		return (NULL);
	while (s[++i])
		dst[j++] = f(i, s[i]);
	dst[j] = '\0';
	return (dst);
}
