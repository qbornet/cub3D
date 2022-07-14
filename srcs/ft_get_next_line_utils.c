#include <cub3D.h>

char	*init_gnl(int fd)
{
	char	*buf;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 1023)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = 0;
	return (buf);
}
