#include <cub3D.h>

static char	*opt_select_direction(char *buff, int i, int j)
{
	char	*new;

	while (ft_isspace(buff[i]))
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	new = ft_substr(buff, i, (j - i));
	if (!new)
	{
		free(buff);
		return (NULL);
	}
	free(buff);
	return (new);
}

static char	*select_direction(char *buff, int direction)
{
	int		i;
	int		j;
	char	*res;
	char	*to_find;

	i = -1;
	opt_setdirection(&to_find, direction);
	while (buff[++i])
		if (!ft_strncmp(&buff[i], to_find, ft_strlen(to_find)))
			break ;
	j = i;
	while (buff[j] && buff[j] != '\n')
		j++;
	if (!buff[j])
		return (NULL);
	res = ft_substr(buff, i, (j - i));
	if (!res)
		return (NULL);
	i = 0;
	while (res[i] && !ft_isvalid_path(res[i], res[i + 1]))
		i++;
	return (opt_select_direction(res, i, ft_strlen(res)));
}

char	*ft_get_texture(char *filename, int direction)
{
	int		fd;
	int		ret;
	char	*res;
	char	buff[1025];

	ret = 1;
	res = NULL;
	ft_memset(&buff, 0, sizeof(buff) / sizeof(buff[0]));
	if (ft_valid_file(filename) < 0)
		return (NULL);
	fd = open(filename, O_RDONLY | O_NOCTTY);
	if (fd == -1)
		return (NULL);
	while (ret)
	{
		ret = read(fd, buff, 1024);
		if (ret == -1)
			return (NULL);
		res = select_direction(buff, direction);
		if (res)
			break ;
	}
	close(fd);
	return (res);
}

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

char	**get_texture(char *filename)
{
	int					i;
	char				**tab;
	enum e_texture_pos	dummy;

	i = -1;
	(void)dummy;
	tab = ft_calloc(5, sizeof(char *));
	if (!tab)
		return (NULL);
	tab[E_NORTH] = ft_get_texture(filename, 'n');
	tab[E_SOUTH] = ft_get_texture(filename, 's');
	tab[E_WEST] = ft_get_texture(filename, 'w');
	tab[E_EAST] = ft_get_texture(filename, 'e');
	if (!tab[0] || !tab[1]
		|| !tab[2] || !tab[3])
	{
		while (++i < 4)
			free(tab[i]);
		free(tab);
		return (NULL);
	}
	return (tab);
}
