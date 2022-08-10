#include <cub3D.h>

static int	check_end(const char *s, char **res, size_t i, int flg)
{
	*res = NULL;
	if (!s[i] || s[i] == '\n')
	{
		if (!flg)
			return (1);
		*res = ft_rmt_chr(s, '\n');
		return (1);
	}
	else if (!ft_isspace(s[i]) && s[i] != '0'
		&& s[i] != '1' && !ft_is_sta_pos(s[i]))
		return (1);
	return (0);
}

char	*nrm_line(const char *s, int *pos)
{
	int		flg;
	size_t	i;
	char	*res;

	if (!s || !pos)
		return (NULL);
	if (!s[0])
		return (NULL);
	flg = 0;
	if (s[0] == '\n')
		flg = 1;
	i = 0;
	while (1)
	{
		if (check_end(s, &res, i, flg))
			return (res);
		if (s[i] == '0' || s[i] == '1')
			flg = 1;
		else if (!ft_isspace(s[i]) && *pos)
			return (NULL);
		else if (!ft_isspace(s[i]) && !*pos)
			*pos = 1;
		i++;
	}
	return (NULL);
}

int	set_line(char **l, char **l_bef, int *pos, int fd)
{
	char	*tmp;

	tmp = *l;
	*l = nrm_line(*l, pos);
	if (!*l)
	{
		if (*l_bef)
			free(*l_bef);
		free(tmp);
		return (-1);
	}
	free(tmp);
	if (check_line(*l_bef, *l) < 0)
	{
		if (*l_bef)
			free(*l_bef);
		free(*l);
		return (-1);
	}
	if (*l_bef)
		free(*l_bef);
	*l_bef = *l;
	*l = get_next_line(fd, BUFFER_SIZE);
	return (0);
}

static int	check_last_line(char **l_bef, int *pos)
{
	if (check_line(*l_bef, NULL) < 0)
	{
		free(*l_bef);
		return (-1);
	}
	free(*l_bef);
	if (!*pos)
		return (-1);
	return (0);
}

int	map_parser(int fd, char ***res)
{
	int		pos;
	char	*l;
	char	*l_bef;

	*res = init_res(fd, &l, &l_bef, &pos);
	if (!*res)
		return (ft_clear_map_parser(fd, NULL));
	while (l)
	{
		if (set_line(&l, &l_bef, &pos, fd) < 0)
			return (ft_clear_map_parser(fd, res));
		update_res_tab(res, (const char *)l_bef);
	}
	if (check_last_line(&l_bef, &pos) < 0)
		return (ft_clear_map_parser(fd, res));
	return (0);
}
