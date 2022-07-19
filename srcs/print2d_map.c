#include <cub3D.h>

static int	print_sqr(int c, t_data *frame, int mul_i, int mul_j)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 32)
	{
		j = -1;
		while (++j < 32)
		{
			if (c == '1')
				mlx_pixel_put(frame->mlx, frame->win, (mul_i * 32) + i, (mul_j * 32) + j, 0x00FF);
			else
				mlx_pixel_put(frame->mlx, frame->win, (mul_i * 32) + i, (mul_j * 32) + j, 0x00808080);
		}
	}
	i = -1;
	while (++i < 16)
	{
		j = -1;
		while (++j < 16)
		{
			if (c == 'N'
				|| c == 'S'
				|| c == 'E'
				|| c == 'W')
				mlx_pixel_put(frame->mlx, frame->win, (mul_i * 36) + i, (mul_j * 36) + j, 0xFFFF00);
		}
	}
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
			print_sqr(map[i][j], (*d_curr), j, i);
	}
	return (0);
}
