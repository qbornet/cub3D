/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:35 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/15 13:59:35 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	ft_is_sta_pos(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

static int	is_inv_pos(const char *s1, const char *s2, size_t i, size_t len)
{
	if (ft_isspace(s1[i - 1])
		|| (s1[i + 1] && ft_isspace(s1[i + 1])) || i >= len)
		return (-1);
	if (i >= len || ft_isspace(s2[i]))
		return (-1);
	return (0);
}

static int	check_middle_line(const char *s1, const char *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1) - 1;
	if (s1[0] == '0' || s1[len1] == '0'
		|| ft_is_sta_pos(s1[0]) || ft_is_sta_pos(s1[len1]))
		return (-1);
	len2 = ft_strlen(s2);
	i = 1;
	while (i < len1)
	{
		if (s1[i] == '0' || ft_is_sta_pos(s1[i]))
			if (is_inv_pos(s1, s2, i, len2) < 0)
				return (-1);
		i++;
	}
	return (0);
}

static int	check_edge_line(const char *s)
{
	size_t	i;
	size_t	len;

	if (!s)
		return (-1);
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (ft_is_sta_pos(s[i]))
			return (-1);
		if (s[i] == '0')
			return (-1);
		i++;
	}
	return (0);
}

int	check_line(char *l_bef, char *l)
{
	if ((!l_bef && !l) || ((l_bef && !l_bef[0]) && (l && !l[0])))
		return (-1);
	if ((l && !l[0]) || ((l_bef && !l_bef[0]) && !l))
		return (0);
	if ((l_bef && !l_bef[0]) && l)
		return (-1);
	if (!l_bef && l)
	{
		if (check_edge_line(l) < 0)
			return (-1);
	}
	else if (l_bef && !l)
	{
		if (check_edge_line(l_bef) < 0)
			return (-1);
	}
	else
	{
		if (check_middle_line(l, l_bef) < 0)
			return (-1);
		if (check_middle_line(l_bef, l) < 0)
			return (-1);
	}
	return (0);
}
