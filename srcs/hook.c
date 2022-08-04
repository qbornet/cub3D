#include <cub3D.h>

int	move_down(int keycode, t_data **d_curr)
{
	t_data	*frame;

	frame = *d_curr;
	if (keycode == ESC_KEY)
		free_all(d_curr);
	if (keycode == W_KEY)
		frame->forward = 1;
	if (keycode == S_KEY)
		frame->backward = 1;
	if (keycode == D_KEY)
		frame->right = 1;
	if (keycode == A_KEY)
		frame->left = 1;
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
