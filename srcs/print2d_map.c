#include <cub3D.h>

void	starting_pos(char c, int x, int y, t_ray *ray)
{
	if (ft_is_sta_pos(c))
	{
		ray->posx = (double)x;
		ray->posy = (double)y;
		ray->mapx = x;
		ray->mapy = y;
	}
}

/* Le plan doit toujours etre perpendiculaire a la direction,
 * donc sachant que l'origine des vecteurs et toujours en haut a gauche et,
 * y descend, x va a droite. */

/* TLDR; On doit avoir le plan et la direction dans la meme position */

void	starting_value(char c, int x, int y, t_data **d_curr)
{
	t_data	*frame;

	frame = *d_curr;
	starting_pos(c, x, y, &frame->ray);
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

void	set_colors(t_data **d_curr, int *celling, int *floor)
{
	(*d_curr)->fcolors = floor[2];
	(*d_curr)->fcolors |= floor[1] << 8;
	(*d_curr)->fcolors |= floor[0] << 16;
	(*d_curr)->ccolors = celling[2];
	(*d_curr)->ccolors |= celling[1] << 8;
	(*d_curr)->ccolors |= celling[0] << 16;
}

int	print2d_map(t_data **d_curr)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	map = (*d_curr)->map;
	ft_memset(&(*d_curr)->ray, 0, sizeof(t_ray));
	set_colors(d_curr, (*d_curr)->colors[E_CELLING],
		(*d_curr)->colors[E_FLOOR]);
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
