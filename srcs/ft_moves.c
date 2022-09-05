/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:09 by jfrancai          #+#    #+#             */
/*   Updated: 2022/09/05 14:44:51 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	rotate_lr(t_data **d_curr)
{
	t_ray		*ray;
	static int	tmp = 1;

	ray = &(*d_curr)->ray;
	if ((*d_curr)->lrotate && (*d_curr)->rrotate)
	{
		if (tmp == 1)
			rotate(-1, ray);
		else if (tmp == 2)
			rotate(1, ray);
	}
	else if ((*d_curr)->lrotate)
	{
		tmp = 1;
		rotate(-1, ray);
	}
	else if ((*d_curr)->rrotate)
	{
		tmp = 2;
		rotate(1, ray);
	}
	(*d_curr)->ray = *ray;
}

void	rotate(int dir, t_ray *r)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = r->dirx;
	old_planex = r->planex;
	r->rotspeed = ft_deg2rad(1.32);
	r->dirx = r->dirx * cos(r->rotspeed) + dir * r->diry * sin(r->rotspeed);
	r->diry = -dir * old_dirx * sin(r->rotspeed) + r->diry * cos(r->rotspeed);
	r->planex = r->planex * cos(r->rotspeed) + \
			dir * r->planey * sin(r->rotspeed);
	r->planey = -dir * old_planex * sin(r->rotspeed) \
			+ r->planey * cos(r->rotspeed);
}

void	ft_moves(t_data **d_curr)
{
	t_data	*frame;

	frame = *d_curr;
	frame->ray.movespeed = 0.05;
	if (!frame->mouse_mode && (frame->forward || frame->backward) \
		&& (frame->lrotate || frame->rrotate))
		move_crl_fb(d_curr);
	else if (!frame->mouse_mode && (frame->right || frame->left) \
		&& (frame->lrotate || frame->rrotate))
		move_crl(d_curr, 1.57);
	else if (frame->forward && (frame->right || frame->left))
		move(&frame->ray, d_curr, 0.785);
	else if (frame->backward && (frame->right || frame->left))
		move(&frame->ray, d_curr, 2.356);
	else if (frame->forward || frame->backward)
		move_fb(&(*d_curr)->ray, d_curr);
	else if (frame->right || frame->left)
		move(&(*d_curr)->ray, d_curr, 1.57);
	else if (!frame->mouse_mode && (frame->lrotate || frame->rrotate))
		rotate_lr(d_curr);
}
