/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:09 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/30 16:00:21 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	move_fb(t_data **d_curr)
{
	t_ray	ray;
	t_data	*frame;

	frame = *d_curr;
	if (frame->forward && frame->backward)
		return ;
	ray = frame->ray;
	if (frame->forward)
		move(0, frame->map, &ray);
	else if (frame->backward)
		move(1, frame->map, &ray);
	frame->ray = ray;
	*d_curr = frame;
}

static void	move_lr(t_data **d_curr)
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

void	move(int dir, char **map, t_ray *r)
{
	r->movespeed = 0.05;
	if (!dir)
	{
		if (map[(int)(r->posx + r->dirx * r->movespeed)][(int)r->posy] == '0')
			r->posx += r->dirx * r->movespeed;
		if (map[(int)r->posx][(int)(r->posy + r->diry * r->movespeed)] == '0')
			r->posy += r->diry * r->movespeed;
	}
	else
	{
		if (!((r->posx - r->dirx * 0.05) < 0)
			&& map[(int)(r->posx - r->dirx \
				* r->movespeed)][(int)r->posy] == '0')
			r->posx -= r->dirx * r->movespeed;
		if (!((r->posy - r->diry * 0.05) < 0)
			&& map[(int)r->posx][(int)(r->posy - r->diry \
				* r->movespeed)] == '0')
			r->posy -= r->diry * r->movespeed;
	}
}

void	rotate(int dir, t_ray *r)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = r->dirx;
	old_planex = r->planex;
	r->rotspeed = ft_deg2rad(0.66);
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
	if (!frame->mouse_mode && frame->forward && frame->lrotate)
		move_crl_l(d_curr);
	else if (!frame->mouse_mode && frame->forward && frame->rrotate)
		move_crl_r(d_curr);
	else if (!frame->mouse_mode && frame->backward && frame->lrotate)
		move_bcrl_l(d_curr);
	else if (!frame->mouse_mode && frame->backward && frame->rrotate)
		move_bcrl_r(d_curr);
	else if (frame->forward || frame->backward)
		move_fb(d_curr);
	else if (!frame->mouse_mode && (frame->lrotate || frame->rrotate))
		move_lr(d_curr);
}
