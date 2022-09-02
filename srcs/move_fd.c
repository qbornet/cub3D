/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:46:56 by jfrancai          #+#    #+#             */
/*   Updated: 2022/09/02 13:47:15 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	move_f(t_ray *r, t_data **d_curr)
{
	t_data	*frame;
	char	**map;

	frame = *d_curr;
	map = frame->map;
	if (map[(int)(r->posx + r->dirx * r->movespeed)][(int)r->posy] == '0')
		r->posx += r->dirx * r->movespeed;
	if (map[(int)r->posx][(int)(r->posy + r->diry * r->movespeed)] == '0')
		r->posy += r->diry * r->movespeed;
}

static void	move_b(t_ray *r, t_data **d_curr)
{
	t_data	*frame;
	char	**map;

	frame = *d_curr;
	map = frame->map;
	if (map[(int)(r->posx - r->dirx * r->movespeed)][(int)r->posy] == '0')
		r->posx -= r->dirx * r->movespeed;
	if (map[(int)r->posx][(int)(r->posy - r->diry * r->movespeed)] == '0')
		r->posy -= r->diry * r->movespeed;
}

void	move_fb(t_ray *r, t_data **d_curr)
{
	static int	tmp = 0;

	if ((*d_curr)->forward && (*d_curr)->backward)
	{
		if (tmp == 1)
			move_f(r, d_curr);
		else if (tmp == 2)
			move_b(r, d_curr);
	}
	else if ((*d_curr)->forward)
	{
		tmp = 1;
		move_f(r, d_curr);
	}
	else if ((*d_curr)->backward)
	{
		tmp = 2;
		move_b(r, d_curr);
	}
}
