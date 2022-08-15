/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shot_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:45 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/15 15:05:17 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	setup_texture(t_data **d_curr, t_ray ray)
{
	if (ray.side == 0 && ray.raydirx < 0)
		(*d_curr)->tex.texdir = E_SOUTH;
	if (ray.side == 0 && ray.raydirx >= 0)
		(*d_curr)->tex.texdir = E_NORTH;
	if (ray.side == 1 & ray.raydiry < 0)
		(*d_curr)->tex.texdir = E_EAST;
	if (ray.side == 1 & ray.raydiry > 0)
		(*d_curr)->tex.texdir = E_WEST;
	if (ray.side == 0)
		(*d_curr)->tex.wallx = ray.posy + ray.perpwall * ray.raydiry;
	else
		(*d_curr)->tex.wallx = ray.posx + ray.perpwall * ray.raydirx;
	(*d_curr)->tex.wallx -= floor(((*d_curr)->tex.wallx));
}

void	draw_texture(t_data **d_curr, t_ray ray, int y)
{
	t_data	*f;

	y = ray.drawstart - 1;
	setup_texture(d_curr, ray);
	f = *d_curr;
	f->tex.step = 1.0 * f->data[0].height / ray.lineheight;
	f->tex.texx = (int)(f->tex.wallx * (double)f->data[f->tex.texdir].width);
	if (ray.side == 0 && ray.raydirx > 0)
		f->tex.texx = f->data[f->tex.texdir].width - f->tex.texx - 1;
	if (ray.side == 1 && ray.raydiry < 0)
		f->tex.texx = f->data[f->tex.texdir].width - f->tex.texx - 1;
	f->tex.texpos = \
		(ray.drawstart - HEIGHT / 2 + ray.lineheight / 2) * f->tex.step;
	while (++y <= ray.drawend)
	{
		f->tex.texy = (int)f->tex.texpos & (f->data[f->tex.texdir].height - 1);
		f->tex.texpos += f->tex.step;
		if (y < HEIGHT && ray.x < WIDTH)
			f->buffer.addr[y * f->buffer.line_length / 4 + ray.x] = \
				f->data[f->tex.texdir].addr[f->tex.texy * \
					f->data[f->tex.texdir].line_length / 4 + f->tex.texx];
	}
	*d_curr = f;
}

void	draw_column(t_data **d_curr, t_ray ray)
{
	int		i;

	i = -1;
	while (++i < ray.drawstart)
		ft_pixel_put(&(*d_curr)->buffer, ray.x, i, (*d_curr)->ccolors);
	if (i <= ray.drawend)
		draw_texture(d_curr, ray, i);
	i = ray.drawend - 1;
	while (++i < HEIGHT)
		ft_pixel_put(&(*d_curr)->buffer, ray.x, i, (*d_curr)->fcolors);
}

int	shot_ray(t_data **d_curr)
{
	t_ray	ray;

	stop_mouse_move(*d_curr);
	ray = (*d_curr)->ray;
	ray.x = 0;
	create_buffer(d_curr);
	while (ray.x < WIDTH)
	{
		start_dda(d_curr, &ray);
		draw_column(d_curr, ray);
		ray.x += 1;
		ray.hit = 0;
		(*d_curr)->ray = ray;
		printf("%d %d %d %d %d %d |%d| %d %d %d %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n", ray.mapx,
			ray.mapy,
			ray.stepx,
			ray.stepy,
			ray.lineheight,
			ray.drawstart,
			ray.drawend,
			ray.x,
			ray.hit,
			ray.side,
			ray.posx,
			ray.posy,
			ray.dirx,
			ray.diry,
			ray.planex,
			ray.planey,
			ray.camerax,
			ray.raydirx,
			ray.raydiry,
			ray.sidedistx,
			ray.sidedisty,
			ray.dx,
			ray.dy,
			ray.perpwall);
	}
	put_buffer(d_curr);
	destroy_buffer(d_curr);
	ft_moves(d_curr);
	return (0);
}
