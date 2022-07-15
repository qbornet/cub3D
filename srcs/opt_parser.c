#include <cub3D.h>

void	opt_setdirection(char **t_curr, int direction)
{
	char	*to_find;

	to_find = NULL;
	if (direction == 'n')
		to_find = "NO";
	else if (direction == 's')
		to_find = "SO";
	else if (direction == 'e')
		to_find = "EA";
	else if (direction == 'w')
		to_find = "WE";
	*t_curr = to_find;
}

int	opt_colorsatoi(char *str, int *i)
{
	int	res;

	res = 0;
	while (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
	{
		res = res * 10 + (str[*i] - '0');
		*i += 1;
	}
	return (res);
}
