/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crl_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:56:40 by jfrancai          #+#    #+#             */
/*   Updated: 2022/09/05 14:04:28 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	move_crl_fb(t_data **d_curr)
{
	t_ray	ray;

	ray = (*d_curr)->ray;
	if ((*d_curr)->forward || (*d_curr)->backward)
		move_fb(&ray, d_curr);
	if ((*d_curr)->lrotate)
		rotate(-1, &ray);
	else if ((*d_curr)->rrotate)
		rotate(1, &ray);
	(*d_curr)->ray = ray;
}

void	move_crl(t_data **d_curr, double pi_4)
{
	t_ray	ray;

	ray = (*d_curr)->ray;
	if ((*d_curr)->right || (*d_curr)->left)
		move(&ray, d_curr, pi_4);
	if ((*d_curr)->lrotate)
		rotate(-1, &ray);
	else if ((*d_curr)->rrotate)
		rotate(1, &ray);
	(*d_curr)->ray = ray;
}
