#include <cub3D.h>

int	check_middle_line(const char *s1, const char *s2)
{
	int	i;
	int	len1;
	int	len2;

	len1 = ft_strlen(s1) - 1;
	if (s1[0] == '0' || s1[len1] == '0')
		return (-1);
	len2 = ft_strlen(s2);
	i = 1;
	while (i < len1)
	{
		if (s1[i] == '0')
		{
			if ((s1[i + 1] && s1[i + 1] == ' ') || i >= len2)
				return (-1);
			if (i - 1 >= len2 || s2[i - 1] == ' ')
				return (-1);
			if (i >= len2 || s2[i] == ' ')
				return (-1);
			if (i + 1 >= len2 || s2[i + 1] == ' ')
				return (-1);
		}
		i++;
	}
	return (0);
}

int	check_edge_line(const char *s)
{
	int	i;
	int	len;

	if (!s)
		return (-1);
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == '0')
			return (-1);
		i++;
	}
	return (0);
}

int	check_line(char *l_bef, char *l)
{
	if (!l_bef && !l)
		return (-1);
	if ((l_bef && !l_bef[0]) || (l && !l[0]))
		return (-1);
	if (!l_bef && l)
	{
		if (check_edge_line(l) < 0)
			return (-1);
	}
	else if (l_bef && !l)
	{
		if (check_edge_line(l_bef) < 0)
			return (-1);
	}
	else
	{
		if (check_middle_line(l, l_bef) < 0)
			return (-1);
		if (check_middle_line(l_bef, l) < 0)
			return (-1);
	}
	return (0);
}

int	map_parser(int fd)
{
	(void)fd;
	return (0);
}
