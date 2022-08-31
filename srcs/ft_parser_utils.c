/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:13 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/31 16:21:40 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_invalid_line(const char *l)
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

static int	mod_isprint(char c)
{
	if (ft_isprint(c) || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_valid_file(char *filename)
{
	int		i;
	int		fd;
	char	buff[4097];

	i = -1;
	ft_memset(&buff, 0, sizeof(buff) / sizeof(buff[0]));
	fd = open(filename, O_RDONLY | O_NOCTTY);
	if (fd == -1)
		return (-1);
	if (read(fd, buff, 4096) < 0)
		return (-1);
	close(fd);
	while (buff[++i])
		if (!mod_isprint(buff[i]))
			return (-1);
	return (1);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}
