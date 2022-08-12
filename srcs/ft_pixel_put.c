#include <cub3D.h>

void	ft_pixel_put(t_img *data, int x, int y, int colors)
{
	int	*dst;

	dst = data->addr + (y * data->line_length / 4 + x);
	*(unsigned int *)dst = colors;
}
