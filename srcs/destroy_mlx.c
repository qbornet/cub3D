#include <cub3D.h>

static void	destroy_img(t_data **d_curr)
{
	int		i;
	t_data	*frame;

	i = -1;
	frame = *d_curr;
	if (frame->mlx && frame->win)
	{
		while (++i < E_MAX_TEXTURE)
			if (frame->data[i].img)
				mlx_destroy_image(frame->mlx, frame->data[i].img);
		if (frame->buffer.img)
			mlx_destroy_image(frame->mlx, frame->buffer.img);
	}
}

int	destroy_mlx(t_data **d_curr)
{
	t_data	*frame;

	frame = *d_curr;
	destroy_img(d_curr);
	if (frame->mlx && frame->win)
		mlx_clear_window(frame->mlx, frame->win);
	if (frame->mlx && frame->win)
		mlx_destroy_window(frame->mlx, frame->win);
	if (frame->mlx)
		mlx_destroy_display(frame->mlx);
	return (0);
}
