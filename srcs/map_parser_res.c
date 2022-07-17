#include <cub3D.h>

char	**init_res(int fd, char **l, char **l_bef, int *pos)
{
	char	**tab;

	*l_bef = NULL;
	*l = get_next_line(fd, BUFFER_SIZE);
	if (!*l)
		return (NULL);
	*pos = 0;
	if (set_line(l, l_bef, pos, fd) < 0)
		return (NULL);
	if (!*l)
	{
		free(*l_bef);
		return (NULL);
	}
	tab = ft_add_str(NULL, *l_bef);
	if (!tab)
	{
		free(*l_bef);
		free(*l);
		return (NULL);
	}
	return (tab);
}

void	update_res_tab(char ***res, const char *s)
{
	char	**tmp;

	tmp = *res;
	*res = ft_add_str((const char **)tmp, s);
	ft_retfree_tab(&tmp, ft_len_tab((const char **)tmp));
}
