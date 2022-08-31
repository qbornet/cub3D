/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_res.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:32 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/31 15:47:27 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	is_map_start(const char *l)
{
	int	i;
	int	len;

	if (l[0] == '\n')
		return (0);
	len = ft_strlen(l);
	if (l[len - 1] == '\n')
		len--;
	i = 0;
	while (i < len)
	{
		if (l[i] != '1' && l[i] != '0' && !ft_isspace(l[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_invalid_line(const char *l)
{
	static int	status = 0;

	while (*l == ' ')
		l++;
	if (ft_is_sta_pos(*l) || *l == 'F' || *l == 'C')
		status++;
	if (status > 6)
		return (1);
	return (0);
}

static int	get_fst_map_line(int fd, char **l, int *pos)
{
	while (1)
	{
		*pos = 0;
		*l = get_next_line(fd, BUFFER_SIZE);
		if (!*l)
			return (-1);
		if (is_map_start((const char *)(*l)))
			return (0);
		if (is_invalid_line((const char *)(*l)))
		{
			free(*l);
			return (-1);
		}
		free(*l);
	}
	return (-1);
}

char	**init_res(int fd, char **l, char **l_bef, int *pos)
{
	char	**tab;

	if (get_fst_map_line(fd, l, pos) < 0)
		return (NULL);
	*l_bef = NULL;
	if (set_line(l, l_bef, pos, fd) < 0)
		return (NULL);
	if (!*l)
	{
		free(*l_bef);
		return (NULL);
	}
	tab = ft_add_str(NULL, *l_bef);
	if (!tab)
	{
		free(*l_bef);
		free(*l);
		return (NULL);
	}
	return (tab);
}

void	update_res_tab(char ***res, const char *s)
{
	char	**tmp;

	tmp = *res;
	*res = ft_add_str((const char **)tmp, s);
	ft_retfree_tab(&tmp, ft_len_tab((const char **)tmp));
}

int	ft_clear_map_parser(int fd, char ***res)
{
	char	*l;

	l = get_next_line(fd, BUFFER_SIZE);
	while (l)
	{
		free(l);
		l = get_next_line(fd, BUFFER_SIZE);
	}
	if (res)
		ft_retfree_tab(res, ft_len_tab((const char **)(*res)));
	return (-1);
}
