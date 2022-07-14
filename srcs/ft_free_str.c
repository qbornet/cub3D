#include <cub3D.h>

char	*ft_retfree_str(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}
