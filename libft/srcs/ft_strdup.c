/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 04:04:13 by qbornet           #+#    #+#             */
/*   Updated: 2022/07/15 10:34:41 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	ft_strdup_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	if (!*s1)
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	size = ft_strdup_len(s1);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (*s1 && i < size)
		str[i++] = *s1++;
	str[i] = '\0';
	return (str);
}
