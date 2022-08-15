/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:19 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/15 13:59:20 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*ft_rmt_chr(const char *s, char c)
{
	char	*res;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!len || c == 0 || s[len - 1] != c)
	{
		res = ft_strdup(s);
		if (!res)
			return (NULL);
		return (res);
	}
	res = ft_calloc(len, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, len);
	return (res);
}

size_t	ft_len_tab(const char **tab)
{
	size_t	len;

	if (!tab)
		return (0);
	len = 0;
	while (tab[len])
		len++;
	return (len);
}

char	**ft_new_tab(const char *s)
{
	int		len;
	char	**res;

	if (s)
		len = 2;
	else
		len = 1;
	res = ft_calloc(len, sizeof(char *));
	if (!res)
		return (NULL);
	if (s)
	{
		res[0] = ft_strdup(s);
		if (!res[0])
		{
			free(res);
			return (NULL);
		}
	}
	return (res);
}

int	ft_cpy_tab(const char **tab, char **res, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
	{
		res[i] = ft_strdup(tab[i]);
		if (!res[i])
		{
			while (i--)
				free(res[i]);
			free(res);
			return (-1);
		}
	}
	return (0);
}

char	**ft_add_str(const char **tab, const char *s)
{
	char	**res;
	size_t	len;

	res = NULL;
	if (!s)
		return (NULL);
	if (!tab)
		res = ft_new_tab(s);
	else
	{
		len = ft_len_tab(tab);
		res = ft_calloc(len + 2, sizeof(char **));
		if (!res || ft_cpy_tab(tab, res, len) < 0)
			return (NULL);
		res[len] = ft_strdup(s);
		if (!res[len])
		{
			free(res);
			return (NULL);
		}
		res[len + 1] = NULL;
	}
	return (res);
}
