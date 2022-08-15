/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:47 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/15 15:37:48 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	wall_hit(t_ray *ray)
{
	if (ray->side == 0)
		ray->perpwall = (ray->sidedistx - ray->dx);
	else
		ray->perpwall = (ray->sidedisty - ray->dy);
	if (ray->perpwall <= 0)
		ray->perpwall = 2.0;
	ray->lineheight = (int)(HEIGHT / ray->perpwall);
	ray->drawstart = -ray->lineheight / 2 + HEIGHT / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + HEIGHT / 2;
	if (ray->drawend >= HEIGHT || ray->drawend < 0)
		ray->drawend = HEIGHT - 1;
}

static void	dda_algo(t_data **d_curr, t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->mapx += ray->stepx;
			ray->sidedistx += ray->dx;
			ray->side = 0;
		}
		else
		{
			ray->mapy += ray->stepy;
			ray->sidedisty += ray->dy;
			ray->side = 1;
		}
		if ((*d_curr)->map[ray->mapx][ray->mapy] == '1')
			ray->hit = 1;
	}
	wall_hit(ray);
}

static void	step_side(t_data **d_curr, t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->posx - ray->mapx) * ray->dx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->posx) * ray->dx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->posy - ray->mapy) * ray->dy;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->posy) * ray->dy;
	}
	dda_algo(d_curr, ray);
}

void	start_dda(t_data **d_curr, t_ray *ray)
{
	if (WIDTH % 2)
		ray->camerax = 2 * ray->x / (double)WIDTH - 1;
	else
		ray->camerax = 2 * ray->x / ((double)WIDTH - 1) - 1;
	ray->raydirx = ray->dirx + ray->planex * ray->camerax;
	ray->raydiry = ray->diry + ray->planey * ray->camerax;
	ray->mapx = (int)ray->posx;
	ray->mapy = (int)ray->posy;
	if (ray->raydirx == 0)
		ray->dx = 0;
	else
		ray->dx = fabs(1 / ray->raydirx);
	if (ray->raydiry == 0)
		ray->dy = 0;
	else
		ray->dy = fabs(1 / ray->raydiry);
	step_side(d_curr, ray);
}
