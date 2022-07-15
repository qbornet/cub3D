#include <cub3D.h>

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

int	ft_isvalid_path(char c, char next)
{
	if (!c || !next)
		return (-1);
	if ((c == '~' && next == '/')
		|| (c == '.' && next == '/')
		|| (c == '/' && ft_isprint(next)))
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}
