/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 23:33:06 by qbornet           #+#    #+#             */
/*   Updated: 2021/11/17 06:19:42 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h> 
#include <unistd.h>

static int	ft_strjoin_len(char const *str)
{
	int	i;

	if (!*str)
		return (0);
	i = -1;
	while (*str && str[++i])
		;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len_s1 = ft_strjoin_len(s1);
	len_s2 = ft_strjoin_len(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	while (len_s1--)
		str[i++] = *s1++;
	while (len_s2--)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
