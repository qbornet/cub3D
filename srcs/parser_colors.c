#include <cub3D.h>

static int	string_as_correct_data(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == '-' || str[*i] == '+')
			return (-1);
		*i += 1;
	}
	*i = 0;
	while (str[*i] && !ft_isdigit(str[*i]))
		*i += 1;
	if (!str[*i])
		return (-1);
	return (1);
}

int	*colors_atoi(char *str)
{
	int	i;
	int	j;
	int	res;
	int	count;
	int	*tab;

	i = 0;
	j = 0;
	count = 0;
	if (string_as_correct_data(str, &i) < 0)
		return (NULL);
	tab = malloc(sizeof(int) * 4);
	if (!tab)
		return (NULL);
	while (j < 3)
	{
		res = opt_colorsatoi(str, &i);
		if (res > 255)
			return (ft_retfree_iptr(tab));
		tab[j++] = res;
		opt_check_commas(str, &i, &count);
	}
	if (count != 2 && ft_check_numconv(0) != -1)
		return (ft_retfree_iptr(tab));
	return (tab);
}

int	*select_level(char *buff, int level)
{
	int		i;
	int		j;
	int		*tab;
	char	*to_find;
	char	*res;

	i = -1;
	if (level == 'f')
		to_find = "F";
	else if (level == 'c')
		to_find = "C";
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
	tab = colors_atoi(res);
	free(res);
	return (tab);
}

int	*ft_get_colors(char *filename, int level)
{
	int		fd;
	int		ret;
	int		*tab;
	char	buff[1025];

	ret = 1;
	tab = NULL;
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
		tab = select_level(buff, level);
		if (tab)
			break ;
	}
	close(fd);
	ft_check_numconv(1);
	return (tab);
}

int	**get_colors(char *filename)
{
	int					i;
	int					**tab;
	enum e_colors_pos	dummy;

	i = -1;
	(void)dummy;
	tab = ft_calloc(3, sizeof(int *));
	if (!tab)
		return (NULL);
	tab[E_FLOOR] = ft_get_colors(filename, 'f');
	tab[E_CELLING] = ft_get_colors(filename, 'c');
	if (!tab[E_FLOOR] || !tab[E_CELLING])
	{
		while (tab && ++i < 2)
			free(tab[i]);
		free(tab);
		return (NULL);
	}
	return (tab);
}
