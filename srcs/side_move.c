/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:03:29 by jfrancai          #+#    #+#             */
/*   Updated: 2022/09/02 13:57:38 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	move_lr(t_ray *r, t_data **d_curr)
{
	t_data		*frame;
	static int	tmp = 1;

	frame = *d_curr;
	if (frame->left && frame->right)
	{
		if (tmp == 1)
			straff(r, d_curr, -1.57);
		else if (tmp == 2)
			straff(r, d_curr, 1.57);
	}
	else if (frame->right)
	{
		tmp = 1;
		straff(r, d_curr, -1.57);
	}
	else if (frame->left)
	{
		tmp = 2;
		straff(r, d_curr, 1.57);
	}
}

void	move_blr(t_ray *r, t_data **d_curr)
{
	t_data		*frame;
	static int	tmp = 1;

	frame = *d_curr;
	if (frame->backward && frame->right && frame->left)
	{
		if (tmp == 1)
			straff(r, d_curr, -2.356);
		else if (tmp == 2)
			straff(r, d_curr, 2.356);
	}
	else if (frame->backward && frame->right)
	{
		tmp = 1;
		straff(r, d_curr, -2.356);
	}
	else if (frame->backward && frame->left)
	{
		tmp = 2;
		straff(r, d_curr, 2.356);
	}
}

void	move_flr(t_ray *r, t_data **d_curr)
{
	t_data		*frame;
	static int	tmp = 1;

	frame = *d_curr;
	if (frame->forward && frame->right && frame->left)
	{
		if (tmp == 1)
			straff(r, d_curr, 0.785);
		else if (tmp == 2)
			straff(r, d_curr, -0.785);
	}
	else if (frame->forward && frame->left)
	{
		tmp = 1;
		straff(r, d_curr, 0.785);
	}
	else if (frame->forward && frame->right)
	{
		tmp = 2;
		straff(r, d_curr, -0.785);
	}
}

void	straff(t_ray *r, t_data **d_curr, double pi_4)
{
	t_data	*frame;
	char	**map;

	frame = *d_curr;
	map = frame->map;
	if (map[(int)((r->posx + (cos(pi_4) * r->dirx - sin(pi_4) * r->diry) * r->movespeed))][(int)r->posy] == '0')
		r->posx = r->posx + (((cos(pi_4) * r->dirx - sin(pi_4) * r->diry) * r->movespeed));
	if (map[(int)(r->posx)][(int)(r->posy + ((sin(pi_4) * r->dirx + cos(pi_4) * r->diry) * r->movespeed))] == '0')
		r->posy = r->posy + (((sin(pi_4) * r->dirx + cos(pi_4) * r->diry) * r->movespeed));
	return ;
}
