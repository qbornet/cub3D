#include <cub3D.h>

int	print_wall(t_data *frame, int mul)
{
	int	i;
	int	j;

	i = 0;
	while (++i < 64)
	{
		j = 0;
		while (++j < 64)
			mlx_pixel_put(frame->mlx, frame->win, (mul * 64) + i, (mul * 64) + j, 0x00FF);
	}
	return (0);
}


int	print_floor(t_data *frame, int mul)
{
	int	i;
	int	j;

	i = 0;
	while (++i < 64)
	{
		j = 0;
		while (++j < 64)
			mlx_pixel_put(frame->mlx, frame->win, (mul * 64) + i, (mul * 64) + j, 0x00FFFFFF);
	}
	return (0);
}

int	print_sqr(int c, t_data *frame)
{
	static int	mul;

	if (c == '1')
		print_wall(frame, mul);
	else if (c == '0'
			|| c == 'N' || c == 'S'
			|| c == 'E' || c == 'W')
		print_floor(frame, mul);
	mul++;
	return (0);
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
			print_sqr(map[i][j], (*d_curr));
	}
	return (0);
}
