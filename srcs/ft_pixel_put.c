#include <cub3D.h>

void	ft_pixel_put(t_img *data, int x, int y, int colors)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (dst && *dst)
		*(unsigned int *)dst = colors;
}
