#include <cub3D.h>

int	move_down(int keycode, t_data **d_curr)
{
	t_data	*frame;
	static int	mouse_move = 0;

	frame = *d_curr;
	if (keycode == ESC_KEY)
		free_all(d_curr);
	if (keycode == M_KEY)
	{
		mouse_move = !mouse_move;
		mlx_mouse_move(frame->mlx, frame->win, 100, 100);
	}
	if (keycode == W_KEY)
		frame->forward = 1;
	if (keycode == S_KEY)
		frame->backward = 1;
	if (!mouse_move)
	{
		if (keycode == D_KEY)
			frame->right = 1;
		if (keycode == A_KEY)
			frame->left = 1;
	}
	*d_curr = frame;
	return (0);
}

/* crl est pour faire du circle strafe */
int	move_release(int keycode, t_data **d_curr)
{
	t_data	*frame;

	frame = *d_curr;
	if (keycode == W_KEY) 
		frame->forward = 0;
	if (keycode == S_KEY)
		frame->backward = 0;
	if (keycode == A_KEY)
		frame->left = 0;
	if (keycode == D_KEY)
		frame->right = 0;
	*d_curr = frame;
	return (0);
}

int	mouse_move(int x, int y, t_data **d_curr)
{
	static int prev = 0;

	t_data	*frame;
	(void)x;
	(void)y;
	frame = *d_curr;
	(void)frame;

	if (prev > x)
	{
		frame->left = 1;
		frame->right = 0;
	}
	else if (prev < x)
	{
		frame->right = 1;
		frame->left = 0;
	}
	prev = x;
	return (0);
}
