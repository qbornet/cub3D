/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:03:29 by jfrancai          #+#    #+#             */
/*   Updated: 2022/09/04 18:26:24 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	move(t_ray *r, t_data **d_curr, double pi_4)
{
	t_data		*frame;
	static int	tmp = 1;

	frame = *d_curr;
	if (frame->left && frame->right)
	{
		if (tmp == 1)
			straff(r, d_curr, -pi_4);
		else if (tmp == 2)
			straff(r, d_curr, pi_4);
	}
	else if (frame->right)
	{
		tmp = 1;
		straff(r, d_curr, -pi_4);
	}
	else if (frame->left)
	{
		tmp = 2;
		straff(r, d_curr, pi_4);
	}
}

void	straff(t_ray *r, t_data **d_curr, double pi_4)
{
	t_data	*frame;
	char	**map;

	frame = *d_curr;
	map = frame->map;
	if (map[(int)((r->posx + (cos(pi_4) * r->dirx - sin(pi_4) \
			* r->diry) * r->movespeed))][(int)r->posy] == '0')
		r->posx = r->posx + (((cos(pi_4) * r->dirx - sin(pi_4) \
			* r->diry) * r->movespeed));
	if (map[(int)(r->posx)][(int)(r->posy + ((sin(pi_4) \
			* r->dirx + cos(pi_4) * r->diry) * r->movespeed))] == '0')
		r->posy = r->posy + (((sin(pi_4) * r->dirx + cos(pi_4) \
			* r->diry) * r->movespeed));
	return ;
}
