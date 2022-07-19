#include <cub3D.h>

int	start_window(t_data **d_curr)
{
	t_data	*frame;

	frame = *d_curr;
	frame->mlx = mlx_init();
	if (!frame->mlx)
		return (-1);
	frame->win = mlx_new_window(frame->mlx, WIDTH, HEIGHT, "cub3D");
	if (!frame->win)
		return (-1);
	print2d_map(&frame);
	mlx_hook(frame->win, ON_DESTROY, 0, &free_all, &frame);
	mlx_loop(frame->mlx);
	return (0);
}
