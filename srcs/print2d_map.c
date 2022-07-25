#include <cub3D.h>

static int	print_sqr(int c, t_data *frame, int mul_i, int mul_j)
{
	int	i;
	int	j;
	int	cellsize;

	i = -1;
	cellsize = 32;
	while (++i < cellsize) 
	{
		j = -1;
		while (++j < cellsize) {
			if (i == cellsize - 1 || j == cellsize - 1)
				continue ;
			else if (c == '1')
				mlx_pixel_put(frame->mlx, frame->win, (mul_i * 32) + i, (mul_j * 32) + j, 0x00FF);
			else if (c != ' ')
				mlx_pixel_put(frame->mlx, frame->win, (mul_i * 32) + i, (mul_j * 32) + j, 0x00808080);
		}
	}
	i = -1;
	while (++i < cellsize / 2)
	{
		j = -1;
		while (++j < cellsize / 2)
			if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
				mlx_pixel_put(frame->mlx, frame->win, (mul_i * 32) + i, (mul_j * 32) + j, 0xFFFF00);
	}
	return (0);
}

void	starting_pos(int x, int y, t_ray **r_curr)
{
	t_ray	*ray;

	ray = *r_curr;
	if (map[i][j] == 'N'
		|| map[i][j] == 'S'
		|| map[i][j] == 'E'
		|| map[i][j] == 'W')
	{
		ray->posx = x;
		ray->posy = y;
		ray->mapx = x;
		ray->mapy = y;
	}
	*r_curr = ray;
}

/* Le plan doit toujours etre perpendiculaire a la direction,
 * donc sachant que l'origine des vecteurs et toujours en haut a gauche et,
 * y descend, x va a droite. */

/* TLDR; On doit avoir le plan et la direction dans la meme position */

void	starting_value(char c, int x, int y, t_ray *ray)
{
	starting_pos(x, y, &ray);
	if (map[i][j] == 'N')
	{
		ray->diry = -1;
		ray->planey = -0.66;
	}
	else if (map[i][j] == 'S')
	{
		ray->diry = 1;
		ray->planey = 0.66;
	}
	else if (map[i][j] == 'E')
	{
		ray->dirx = 1;
		ray->planex = 0.66;
	}
	else if (map[i][j] == 'W')
	{
		ray->dirx = -1;
		ray->planex = -0.66;
	}
}

int	print2d_map(t_data **d_curr)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	map = (*d_curr)->map;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			print_sqr(map[i][j], (*d_curr), j, i);
			starting_value(map[i][j], j, i, &(*d_curr)->ray);
		}
	}
	shot_ray(d_curr);
	return (0);
}
