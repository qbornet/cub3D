#include <cub3D.h>

static void	starting_pos(char c, int x, int y, t_data **d_curr)
{
	static int	in;

	if (c == 'N'
		|| c == 'S'
		|| c == 'E'
		|| c == 'W')
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

/* Le plan doit toujours etre perpendiculaire a la direction,
 * donc pour dir x qui est set a = 1 ou -1 alors c'est y qui est set pour plan et,
 * inversement si c'est dir y qui est set a = 1 ou -1 alors c'est x qui est set pour le plan. */

/* TLDR; On doit avoir le plan et la direction dans une direction opposer et le scalar doit avoir la meme valeur. */

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
	t_img	buffer;

	buffer = (*d_curr)->buffer;
	(*d_curr)->fcolors = floor[2];
	(*d_curr)->fcolors |= floor[1] << 8;
	(*d_curr)->fcolors |= floor[0] << 16;
	(*d_curr)->ccolors = celling[2];
	(*d_curr)->ccolors |= celling[1] << 8;
	(*d_curr)->ccolors |= celling[0] << 16;
	buffer.img = mlx_new_image((*d_curr)->mlx, WIDTH, HEIGHT);
	buffer.addr =  mlx_get_data_addr(buffer.img, &buffer.bits_per_pixel, &buffer.line_length, &buffer.endian);
}



int	setup_dda(t_data **d_curr)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	map = (*d_curr)->map;
	set_colors(d_curr, (*d_curr)->colors[E_CELLING], (*d_curr)->colors[E_FLOOR]);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			starting_value(map[i][j], i, j, d_curr);
	}
	return (0);
}
