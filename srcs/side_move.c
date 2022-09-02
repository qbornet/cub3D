/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:03:29 by jfrancai          #+#    #+#             */
/*   Updated: 2022/09/01 18:43:33 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

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
