#include <cub3D.h>

int	move_down(int keycode, t_data **d_curr)
{
	t_data	*frame;

	frame = *d_curr;
	if (keycode == ESC_KEY)
		free_all(d_curr);
	else if (keycode == W_KEY)
		frame->forward = 1;
	else if (keycode == S_KEY)
		frame->backward = 1;
	else if (keycode == D_KEY)
		frame->right = 1;
	else if (keycode == A_KEY)
		frame->left = 1;
	*d_curr = frame;
	return (0);
}

int	move_release(int keycode, t_data **d_curr)
{
	t_data	*frame;

	frame = *d_curr;
	if (keycode == W_KEY)
		frame->forward = 0;
	else if (keycode == S_KEY)
		frame->backward = 0;
	else if (keycode == A_KEY)
		frame->left = 0;
	else if (keycode == D_KEY)
		frame->right = 0;
	*d_curr = frame;
	return (0);
}
