/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:09 by jfrancai          #+#    #+#             */
/*   Updated: 2022/09/04 18:21:32 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	rotate_lr(t_data **d_curr)
{
	t_ray	*ray;

	ray = &(*d_curr)->ray;
	if ((*d_curr)->left && (*d_curr)->right)
		return ;
	if ((*d_curr)->lrotate)
		rotate(0, ray);
	else if ((*d_curr)->rrotate)
		rotate(1, ray);
	(*d_curr)->ray = *ray;
}

void	rotate(int dir, t_ray *r)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = r->dirx;
	old_planex = r->planex;
	r->rotspeed = ft_deg2rad(1.32);
	if (!dir)
	{
		r->dirx = r->dirx * cos(r->rotspeed) - r->diry * sin(r->rotspeed);
		r->diry = old_dirx * sin(r->rotspeed) + r->diry * cos(r->rotspeed);
		r->planex = r->planex * cos(r->rotspeed) - r->planey * sin(r->rotspeed);
		r->planey = old_planex * sin(r->rotspeed) \
			+ r->planey * cos(r->rotspeed);
	}
	else
	{
		r->dirx = r->dirx * cos(-r->rotspeed) - r->diry * sin(-r->rotspeed);
		r->diry = old_dirx * sin(-r->rotspeed) + r->diry * cos(-r->rotspeed);
		r->planex = r->planex * cos(-r->rotspeed) \
				- r->planey * sin(-r->rotspeed);
		r->planey = old_planex * sin(-r->rotspeed) \
				+ r->planey * cos(-r->rotspeed);
	}
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
