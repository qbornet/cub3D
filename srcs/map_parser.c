#include <cub3D.h>

int	check_line(char *l_bef, char *l)
{
	int		i;
	int		len;
	int		len_bef;

	if (!l_bef && !l)
		return (-1);
	if ((l_bef && !l_bef[0]) || (l && !l[0]))
		return (-1);
	if (!l_bef && l)
	{
		len = ft_strlen(l);
		i = 0;
		while (i < len)
		{	
			if (l[i] == '0')
				return (-1);
			i++;
		}
		return (0);
	}
	else if (l_bef && !l)
	{
		i = 0;
		len_bef = ft_strlen(l_bef);
		while (i < len_bef)
		{
			if (l_bef[i] == '0')
				return (-1);
			i++;
		}
		return (0);
	}
	else
	{
		len = ft_strlen(l) - 1;
		if (l[0] == '0' || l[len] == '0')
			return (-1);
		len_bef = ft_strlen(l_bef);
		i = 1;
		while (i < len)
		{
			if (l[i] == '0')
			{
				if (l[i + 1] && l[i + 1] == ' ')
					return (-1);
				if (i >= len_bef)
					return (-1);
				if (i - 1 >= len_bef || l_bef[i - 1] == ' ')
					return (-1);
				if (i >= len_bef || l_bef[i] == ' ')
					return (-1);
				if (i + 1 >= len_bef || l_bef[i + 1] == ' ')
					return (-1);
			}
			i++;
		}
		len_bef = ft_strlen(l_bef) - 1;
		if (l_bef[0] == '0' || l_bef[len_bef] == '0')
			return (-1);
		len = ft_strlen(l);
		i = 1;
		while (i < len_bef)
		{
			if (l_bef[i] == '0')
			{
				if (l_bef[i + 1] && l_bef[i + 1] == ' ')
					return (-1);
				if (i >= len)
					return (-1);
				if (i - 1 >= len || l[i - 1] == ' ')
					return (-1);
				if (i >= len || l[i] == ' ')
					return (-1);
				if (i + 1 >= len || l[i + 1] == ' ')
					return (-1);
			}
			i++;
		}
		return (0);
	}
	return (0);
}

int	map_parser(int fd)
{
	(void)fd;
	return (0);
}
