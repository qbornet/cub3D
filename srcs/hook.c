#include <cub3D.h>

static void	act_mouse_mode(t_data *frame)
{
	frame->mouse_mode = !frame->mouse_mode;
	mlx_mouse_move(frame->mlx, frame->win, WIDTH / 2, HEIGHT / 2);
	if (frame->mouse_mode)
		mlx_mouse_hide(frame->mlx, frame->win);
	else
		mlx_mouse_show(frame->mlx, frame->win);
}

int	move_down(int keycode, t_data **d_curr)
{
	t_data	*frame;

	frame = *d_curr;
	if (keycode == ESC_KEY)
		free_all(d_curr);
	if (keycode == M_KEY)
		act_mouse_mode(frame);
	if (keycode == W_KEY)
		frame->forward = 1;
	if (keycode == S_KEY)
		frame->backward = 1;
	if (!frame->mouse_mode)
	{
		if (keycode == D_KEY)
			frame->right = 1;
		if (keycode == A_KEY)
			frame->left = 1;
	}
	*d_curr = frame;
	return (0);
}

int	move_release(int keycode, t_data **d_curr)
{
	t_data	*frame;

	frame = *d_curr;
	if (keycode == W_KEY)
		frame->forward = 0;
	if (keycode == S_KEY)
		frame->backward = 0;
	if (!frame->mouse_mode)
	{
		if (keycode == A_KEY)
			frame->left = 0;
		if (keycode == D_KEY)
			frame->right = 0;
	}
	*d_curr = frame;
	return (0);
}

int	mouse_move(int x, int y, t_data **d_curr)
{
	t_data	*frame;

	frame = *d_curr;
	if (!frame->mouse_mode)
		return (0);
	frame->right = 1;
	ft_moves_mouse(d_curr, x);
	if (x > WIDTH - 100)
	{
		frame->prev = 99;
		mlx_mouse_move(frame->mlx, frame->win, 100, y);
	}
	else if (x < 100)
	{
		frame->prev = WIDTH - 99;
		mlx_mouse_move(frame->mlx, frame->win, WIDTH - 100, y);
	}
	else if (y > HEIGHT - 100)
		mlx_mouse_move(frame->mlx, frame->win, x, 100);
	else if (y < 100)
		mlx_mouse_move(frame->mlx, frame->win, x, HEIGHT - 100);
	frame->prev = x;
	return (0);
}
