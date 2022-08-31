/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crl_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:56:40 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/30 15:47:15 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	move_crl_l(t_data **d_curr)
{
	t_ray	ray;

	ray = (*d_curr)->ray;
	if ((*d_curr)->forward)
		move(0, (*d_curr)->map, &ray);
	if ((*d_curr)->lrotate)
		rotate(0, &ray);
	(*d_curr)->ray = ray;
}

void	move_crl_r(t_data **d_curr)
{
	t_ray	ray;

	ray = (*d_curr)->ray;
	if ((*d_curr)->forward)
		move(0, (*d_curr)->map, &ray);
	if ((*d_curr)->rrotate)
		rotate(1, &ray);
	(*d_curr)->ray = ray;
}

void	move_bcrl_l(t_data **d_curr)
{
	t_ray	ray;

	ray = (*d_curr)->ray;
	if ((*d_curr)->backward)
		move(1, (*d_curr)->map, &ray);
	if ((*d_curr)->lrotate)
		rotate(1, &ray);
	(*d_curr)->ray = ray;
}

void	move_bcrl_r(t_data **d_curr)
{
	t_ray	ray;

	ray = (*d_curr)->ray;
	if ((*d_curr)->backward)
		move(1, (*d_curr)->map, &ray);
	if ((*d_curr)->rrotate)
		rotate(0, &ray);
	(*d_curr)->ray = ray;
}
