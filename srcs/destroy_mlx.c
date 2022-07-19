#include <cub3D.h>

int	destroy_mlx(t_data **d_curr)
{
	t_data	*frame;
	
	frame = *d_curr;
	if (frame->mlx && frame->win)
		mlx_clear_window(frame->mlx, frame->win);
	if (frame->mlx && frame->win)
		mlx_destroy_window(frame->mlx, frame->win);
	if (frame->mlx)
		mlx_destroy_display(frame->mlx);
	return (0);
}
