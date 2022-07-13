/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 06:51:39 by qbornet           #+#    #+#             */
/*   Updated: 2021/11/16 22:03:12 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

static int	ft_len_words(char const *s, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s[i] != c && s[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char	**ft_free(char **tab, int j)
{
	while (j)
		free(tab[--j]);
	free(tab);
	return (NULL);
}

static char	**ft_add_strings(char const *s, char **tab, char c, int len)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] && j < len)
	{
		k = 0;
		while (s[i] == c)
			i++;
		tab[j] = (char *)malloc(sizeof(char) * (ft_len_words(s, c, i) + 1));
		if (!tab[j])
			return (ft_free(tab, j));
		while (s[i] != '\0' && s[i] != c)
			tab[j][k++] = s[i++];
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**tab;

	if (!s)
		return (NULL);
	len = ft_count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (NULL);
	return (ft_add_strings(s, tab, c, len));
}
