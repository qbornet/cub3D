/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:43:02 by qbornet           #+#    #+#             */
/*   Updated: 2021/12/28 19:51:54 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

static char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_null(s1) + ft_null(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[j++] = s1[i];
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	free(s1);
	return (str);
}

static char	*gnl_del_line(char *save_line)
{
	size_t	i;
	size_t	c;
	char	*str;

	i = 0;
	c = 0;
	while (save_line[i] && save_line[i] != '\n')
		i++;
	if (!save_line[i])
	{
		free(save_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * ((ft_null(save_line) - i) + 1));
	if (!str)
		return (NULL);
	while (save_line[++i])
		str[c++] = save_line[i];
	str[c] = '\0';
	free(save_line);
	return (str);
}

static char	*gnl_get_line(char *save_line)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!save_line[i])
		return (NULL);
	while (save_line[i] && save_line[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (*save_line && *save_line != '\n')
		line[i++] = *save_line++;
	if (*save_line == '\n')
		line[i++] = *save_line++;
	line[i] = '\0';
	return (line);
}

static char	*gnl_read_line(int fd, char *save_line, size_t buffer_size)
{
	char	*buff;
	int		r_value;

	buff = (char *)malloc(sizeof(char) * (buffer_size + 1));
	if (!buff)
		return (NULL);
	r_value = 1;
	while (!ft_strchr_null(save_line, '\n') && r_value != 0)
	{
		r_value = read(fd, buff, buffer_size);
		if (r_value == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[r_value] = '\0';
		save_line = gnl_strjoin(save_line, buff);
	}
	free(buff);
	return (save_line);
}

char	*get_next_line(int fd, size_t buffer_size)
{
	char		*line;
	static char	*save_line;

	if (fd < 0 || buffer_size == 0)
		return (NULL);
	save_line = gnl_read_line(fd, save_line, buffer_size);
	if (!save_line)
		return (NULL);
	line = gnl_get_line(save_line);
	save_line = gnl_del_line(save_line);
	return (line);
}
