#include <cub3D.h>

int	valid_name(char *str)
{
	int		i;
	char	*ext;

	i = -1;
	ext = NULL;
	while (str && str[++i])
		if (str[i + 1])
			if (ft_strchr(&str[i + 1], '.'))
				ext = ft_strchr(&str[i + 1], '.');
	if (!ext || (ext && *(ext - 1) && *(ext - 1) == '.'))
		return (0);
	if (!ft_strncmp(ext, ".cub", 4))
		return (1);
	return (0);
}
