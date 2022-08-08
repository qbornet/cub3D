#include <cub3D.h>

static int	set_data(t_data **d_curr)
{
	int		i;
	t_img	img;
	t_data	*frame;

	(*d_curr)->ray.rotspeed = ft_deg2rad(0.22);
	(*d_curr)->ray.movespeed = 0.05;
	i = -1;
	frame = *d_curr;
	while (++i < E_MAX_TEXTURE)
	{
		img = frame->data[i];
		img.img = mlx_xpm_file_to_image(frame->mlx, frame->texture[i], &img.width, &img.height);
		if (!img.img)
		{
			ft_putstr_fd("Error\ntexture file is incorrect\n", 2);
			return (-1);
		}
		frame->data[i] = img;
	}
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
	if (set_data(&frame) < 0)
		return (free_all(d_curr));
	setup_dda(&frame);
	mlx_hook(frame->win, ON_DESTROY, 0, &free_all, &frame);
	mlx_hook(frame->win, ON_KEYDOWN, (1L << 0), &move_down, &frame);
	mlx_loop_hook(frame->mlx, &shot_ray, &frame);
	mlx_hook(frame->win, ON_RELEASE, (1L << 1), &move_release, &frame);
	mlx_loop(frame->mlx);
	return (0);
}
