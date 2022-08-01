#include <cub3D.h>

/*
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
*/

void	starting_pos(char c, int x, int y, t_ray *ray)
{
	ray->movespeed = 0.1;
	ray->rotspeed = 3.0;
	if (c == 'N'
		|| c == 'S'
		|| c == 'E'
		|| c == 'W')
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

int	print2d_map(t_data **d_curr)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	map = (*d_curr)->map;
	ft_memset(&(*d_curr)->ray, 0, sizeof(t_ray));
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			starting_value(map[i][j], i, j, d_curr);
	}
	return (0);
}
