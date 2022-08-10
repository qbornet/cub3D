#include <cub3D.h>

void	set_data(t_data **d_curr)
{
	t_img	img;

	img = (*d_curr)->data[0];
	(*d_curr)->ray.rotspeed = ft_deg2rad(0.22);
	(*d_curr)->ray.movespeed = 0.05;
	img.img = mlx_new_image((*d_curr)->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	(*d_curr)->data[0] = img;
}

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
	ft_memset(&frame->ray, 0, sizeof(t_ray));
	set_data(&frame);
	print2d_map(&frame);
	mlx_hook(frame->win, ON_MOUSEMOVE, (1L << 6), &mouse_move, &frame);
	mlx_hook(frame->win, ON_DESTROY, 0, &free_all, &frame);
	mlx_hook(frame->win, ON_KEYDOWN, (1L << 0), &move_down, &frame);
	mlx_loop_hook(frame->mlx, &shot_ray, &frame);
	mlx_hook(frame->win, ON_RELEASE, (1L << 1), &move_release, &frame);
	mlx_loop(frame->mlx);
	return (0);
}
