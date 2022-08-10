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

static int	mouse_leave_screen(int x, int y, t_data **d_curr)
{
	t_data	*frame;

	frame = *d_curr;
	if (!frame->mouse_move)
		return (0);
	if (x > WIDTH - 1)
		mlx_mouse_move(frame->mlx, frame->win, 0, y);
	else if (x < 0)
		mlx_mouse_move(frame->mlx, frame->win, WIDTH - 1, y);
	else if (y > HEIGHT - 1)
		mlx_mouse_move(frame->mlx, frame->win, x, 0);
	else if (y < 0)
		mlx_mouse_move(frame->mlx, frame->win, x, HEIGHT - 1);
	return (0);
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
	mlx_hook(frame->win, 8, (1L << 5), &mouse_leave_screen, &frame);
	mlx_hook(frame->win, ON_DESTROY, 0, &free_all, &frame);
	mlx_hook(frame->win, ON_KEYDOWN, (1L << 0), &move_down, &frame);
	mlx_loop_hook(frame->mlx, &shot_ray, &frame);
	mlx_hook(frame->win, ON_RELEASE, (1L << 1), &move_release, &frame);
	mlx_loop(frame->mlx);
	return (0);
}
