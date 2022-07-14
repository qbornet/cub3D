#include <cub3D.h>

static int	end_of_line(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static char	*join_tampon(char **s, char *buf)
{
	int		i;
	int		len;
	char	*tmp;

	if (!*buf)
		return (*s);
	len = 0;
	i = 0;
	while (*s && (*s)[len])
		len++;
	while (buf[i])
		i++;
	tmp = *s;
	*s = malloc(sizeof(char) * (i + len + 1));
	if (!*s)
		return (ft_retfree_str(s));
	(*s)[len + i] = 0;
	while (i--)
		(*s)[len + i] = buf[i];
	while (len--)
		(*s)[len] = tmp[len];
	free(tmp);
	return (*s);
}

static char	*update_tampon(char **s)
{
	int		i;
	int		len;
	char	*new_s;

	i = 0;
	len = 0;
	while ((*s)[i] && (*s)[i] != '\n')
		i++;
	if ((*s)[i] == '\n')
		i++;
	while (*s && (*s)[i + len])
		len++;
	new_s = malloc(sizeof(char) * (len + 1));
	if (!new_s)
		return (ft_retfree_str(s));
	new_s[len] = 0;
	while (*s && len--)
		new_s[len] = (*s)[i + len];
	free(*s);
	return (new_s);
}

static char	*get_line(char *buf, char **s)
{
	int		len;
	char	*result;

	free(buf);
	len = 0;
	if (!*s || !(*(s[0])))
		return (ft_retfree_str(s));
	while ((*s)[len] && (*s)[len] != '\n')
		len++;
	if ((*s)[len] == '\n')
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (ft_retfree_str(s));
	result[len] = 0;
	while (len--)
		result[len] = (*s)[len];
	*s = update_tampon(s);
	return (result);
}

char	*ft_get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	ssize_t		rd;
	static char	*tampon[1024] = {NULL};

	buffer = init_gnl(fd);
	if (!buffer)
		return (NULL);
	rd = 1;
	while (!end_of_line(tampon[fd]) && rd)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (ft_retfree_str(&buffer));
		buffer[rd] = 0;
		if (!join_tampon(&(tampon[fd]), buffer))
			return (ft_retfree_str(&buffer));
		if (end_of_line(tampon[fd]) || !rd)
		{
			line = get_line(buffer, tampon + fd);
			return (line);
		}
	}
	line = get_line(buffer, tampon + fd);
	return (line);
}
