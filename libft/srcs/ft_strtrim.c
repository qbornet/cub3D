/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 00:00:05 by qbornet           #+#    #+#             */
/*   Updated: 2021/11/17 06:25:56 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	ft_ischarset(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (i);
	return (-1);
}

static int	ft_remove_end(char const *s1, char const *set)
{
	int	i;

	i = -1;
	if (!*s1)
		return (0);
	while (s1[++i])
		;
	while ((ft_ischarset(s1[--i], set) != -1) && !(i == 0))
		;
	return (i);
}

static char const	*ft_remove_begin(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while ((ft_ischarset(s1[i], set) != -1) && s1[i])
		s1++;
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = -1;
	s1 = ft_remove_begin(s1, set);
	end = (ft_remove_end(s1, set) + 1);
	if (!*s1)
		end = 1;
	str = (char *)malloc(sizeof(char) * (end + 1));
	if (!str)
		return (NULL);
	while (++i < end)
		str[i] = *s1++;
	str[i] = '\0';
	return (str);
}
