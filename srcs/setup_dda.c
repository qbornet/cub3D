#include <cub3D.h>

static void	starting_pos(char c, int x, int y, t_data **d_curr)
{
	static int	in;

	if (ft_is_sta_pos(c))
	{
		(*d_curr)->ray.posx = (double)x;
		(*d_curr)->ray.posy = (double)y;
		(*d_curr)->ray.mapx = x;
		(*d_curr)->ray.mapy = y;
		in++;
	}
	if (in > 1)
	{
		ft_putstr_fd("Error\nMap as multiple starting position\n", 2);
		free_all(d_curr);
	}
}

static void	starting_value(char c, int x, int y, t_data **d_curr)
{
	t_data	*frame;

	frame = *d_curr;
	starting_pos(c, x, y, d_curr);
	if (c == 'N')
	{
		frame->ray.dirx = -1;
		frame->ray.planey = 0.66;
	}
	else if (c == 'S')
	{
		frame->ray.dirx = 1;
		frame->ray.planey = -0.66;
	}
	else if (c == 'E')
	{
		frame->ray.diry = 1;
		frame->ray.planex = 0.66;
	}
	else if (c == 'W')
	{
		frame->ray.diry = -1;
		frame->ray.planex = -0.66;
	}
	*d_curr = frame;
}

static void	set_colors(t_data **d_curr, int *celling, int *floor)
{
	(*d_curr)->fcolors = floor[2];
	(*d_curr)->fcolors |= floor[1] << 8;
	(*d_curr)->fcolors |= floor[0] << 16;
	(*d_curr)->ccolors = celling[2];
	(*d_curr)->ccolors |= celling[1] << 8;
	(*d_curr)->ccolors |= celling[0] << 16;
}

int	setup_dda(t_data **d_curr)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	map = (*d_curr)->map;
	set_colors(\
			d_curr, (*d_curr)->colors[E_CELLING], (*d_curr)->colors[E_FLOOR]);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			starting_value(map[i][j], i, j, d_curr);
			if (ft_is_sta_pos(map[i][j]))
				map[i][j] = '0';
		}
	}
	return (0);
}
