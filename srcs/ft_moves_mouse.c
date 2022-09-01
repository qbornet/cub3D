/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:11 by jfrancai          #+#    #+#             */
/*   Updated: 2022/09/01 10:35:49 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	move_mouse_lr(t_data **d_curr, int x)
{
	t_ray	*ray;
	double	old_dirx;
	double	old_planex;

	ray = &(*d_curr)->ray;
	if ((*d_curr)->lrotate && (*d_curr)->rrotate)
		return ;
	ray->rotspeed = ft_deg2rad((float)((x - (*d_curr)->prev) % 100) / 10);
	old_dirx = ray->dirx;
	old_planex = ray->planex;
	ray->dirx = ray->dirx * cos(-ray->rotspeed)
		- ray->diry * sin(-ray->rotspeed);
	ray->diry = old_dirx * sin(-ray->rotspeed)
		+ ray->diry * cos(-ray->rotspeed);
	ray->planex = ray->planex * cos(-ray->rotspeed)
		- ray->planey * sin(-ray->rotspeed);
	ray->planey = old_planex * sin(-ray->rotspeed)
		+ ray->planey * cos(-ray->rotspeed);
	(*d_curr)->ray = *ray;
}

void	stop_mouse_move(t_data *frame)
{
	int	x;
	int	y;

	if (frame->mouse_mode)
	{
		mlx_mouse_get_pos(frame->mlx, frame->win, &x, &y);
		if (frame->prev == x)
			frame->rrotate = 0;
	}
}

void	ft_moves_mouse(t_data **d_curr, int x)
{
	if ((*d_curr)->rrotate)
		move_mouse_lr(d_curr, x);
}
