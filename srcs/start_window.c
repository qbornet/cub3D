/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:49 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/22 17:30:18 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

// Pas de handler dans la mlx pour recup x, y, et le param
// Impossible de repositionner la souris si l'utilisateurs 
// reussi a sortir de la window (notamment en bourinant les
// angles);
/*
static int	mouse_out(int x, int y, t_data **d_curr)
{
	(void)x;
	(void)y;
	t_data	*frame;

	frame = *d_curr;
	if (!frame->mouse_mode)
		return (0);
	mlx_mouse_move(frame->mlx, frame->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
*/

static int	set_data(t_data **d_curr)
{
	int		i;
	t_img	img;
	t_data	*frame;

	i = -1;
	frame = *d_curr;
	while (++i < E_MAX_TEXTURE)
	{
		img = frame->data[i];
		img.img = mlx_xpm_file_to_image(\
				frame->mlx, frame->texture[i], &img.width, &img.height);
		if (!img.img)
		{
			ft_putstr_fd("Error\nTexture file is incorrect\n", 2);
			return (-1);
		}
		img.addr = (int *)mlx_get_data_addr(\
				img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		frame->data[i] = img;
	}
	*d_curr = frame;
	return (0);
}

//mlx_hook(frame->win, 8, (1L << 5), &mouse_out, d_curr);
int	start_window(t_data **d_curr)
{
	t_data	*frame;

	frame = *d_curr;
	frame->mlx = mlx_init();
	if (!frame->mlx)
		return (-1);
	if (set_data(&frame) < 0)
		return (free_all(d_curr));
	frame->win = mlx_new_window(frame->mlx, WIDTH, HEIGHT, "cub3D");
	if (!frame->win)
		return (-1);
	setup_dda(&frame);
	mlx_hook(frame->win, ON_MOUSEMOVE, (1L << 6), &mouse_move, &frame);
	mlx_hook(frame->win, ON_DESTROY, 0, &free_all, &frame);
	mlx_hook(frame->win, ON_KEYDOWN, (1L << 0), &move_down, &frame);
	mlx_loop_hook(frame->mlx, &shot_ray, &frame);
	mlx_hook(frame->win, ON_RELEASE, (1L << 1), &move_release, &frame);
	mlx_loop(frame->mlx);
	return (0);
}
