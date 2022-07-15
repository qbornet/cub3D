#include <cub3D.h>

char	*nrm_line(const char *s, int *pos)
{
	int		flg;
	size_t	i;
	char	*res;

	if (!s || !pos)
		return (NULL);
	if (!s[0] || s[0] == '\n')
		return (NULL);
	i = 0;
	flg = 0;
	while (1)
	{
		if (!s[i] || s[i] == '\n')
		{
			if (!flg)
				return (NULL);
			res = ft_rmt_chr(s, '\n');
			if (!res)
				return (NULL);
			return (res);
		}
		else if (s[i] != ' ' && s[i] != '0' && s[i] != '1' && s[i] != 'N' && s[i] != 'S' && s[i] != 'W' && s[i] != 'E')
			return (NULL);
		if (s[i] == '0' || s[i] == '1')
			flg = 1;
		else if (s[i] != ' ' && *pos)
			return (NULL);
		else if (s[i] != ' ' && !*pos)
			*pos = 1;
		i++;
	}
	return (NULL);
}

int	map_parser(int fd)
{
	int		pos;
	char	*tmp;
	char	*l;
	char	*l_bef;

	l_bef = NULL;
	l = ft_get_next_line(fd);
	if (!l)
		return (-1);
	tmp = l;
	pos = 0;
	l = nrm_line(l, &pos);
	if (!l)
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	if (check_line(l_bef, l) < 0)
	{
		free(l);
		return (-1);
	}
	l_bef = l;
	l = ft_get_next_line(fd);
	if (!l)
	{
		free(l_bef);
		return (-1);
	}
	while (l)
	{
		tmp = l;
		l = nrm_line(l, &pos);
		if (!l)
		{
			free(l_bef);
			free(tmp);
			return (-1);
		}
		free(tmp);
		if (check_line(l_bef, l) < 0)
		{
			free(l);
			free(l_bef);
			return (-1);
		}
		free(l_bef);
		l_bef = l;
		l = ft_get_next_line(fd);
		
	}
	if (check_line(l_bef, NULL) < 0)
	{
		free(l_bef);
		return (-1);
	}
	free(l_bef);
	if (!pos)
		return (-1);
	return (0);
}
