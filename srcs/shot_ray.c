#include <cub3D.h>

void	draw_vertline(t_data **d_curr, t_ray ray)
{
	int	i;

	i = 0;
	while (i < ray.drawstart)
	{
		mlx_pixel_put((*d_curr)->mlx, (*d_curr)->win, ray.x, i, 0x0);
		i++;
	}
	while (ray.drawstart < ray.drawend)
	{
		mlx_pixel_put((*d_curr)->mlx, (*d_curr)->win, ray.x, ray.drawstart, 0xFF);
		ray.drawstart += 1;
	}
	i = ray.drawend;
	while (i < HEIGHT)
	{
		mlx_pixel_put((*d_curr)->mlx, (*d_curr)->win, ray.x, i, 0x0);
		i++;
	}
}

int	shot_ray(t_data **d_curr)
{
	t_ray	ray;

	ray = (*d_curr)->ray;
	while (ray.x < WIDTH)
	{
		ray.camerax = 2 * ray.x / (double)WIDTH - 1;
		ray.raydirx = ray.dirx + ray.planex * ray.camerax;
		ray.raydiry = ray.diry + ray.planey * ray.camerax;
		ray.mapx = (int)ray.posx;
		ray.mapy = (int)ray.posy;
		if (ray.raydirx == 0)
			ray.dx = 1e30;
		else
			ray.dx = fabs(1 / ray.raydirx);
		if (ray.raydiry == 0)
			ray.dy = 1e30;
		else
			ray.dy = fabs(1 / ray.raydiry);
		if (ray.raydirx < 0)
		{
			ray.stepx = -1;
			ray.sidedistx = (ray.posx + 0.5- ray.mapx) * ray.dx;
		}
		else
		{
			ray.stepx = 1;
			ray.sidedistx = (ray.mapx + 1.0 - ray.posx) * ray.dx;
		}
		if (ray.raydiry < 0)
		{
			ray.stepy = -1;
			ray.sidedisty = (ray.posy + 0.5 - ray.mapy) * ray.dy;
		}
		else
		{
			ray.stepy = 1;
			ray.sidedisty = (ray.mapy + 1.0 - ray.posy) * ray.dy;
		}

		while (!ray.hit)
		{
			if (ray.sidedistx < ray.sidedisty)
			{
				ray.mapx += ray.stepx;
				ray.sidedistx += ray.dx;
				ray.side = 0;
			}
			else
			{
				ray.mapy += ray.stepy;
				ray.sidedisty += ray.dy;
				ray.side = 1;
			}
			if ((*d_curr)->map[ray.mapx][ray.mapy] == '1')
				ray.hit = 1;
		}
		if (!ray.side)
			ray.perpwall = (ray.sidedistx - ray.dx);
		else
			ray.perpwall = (ray.sidedisty - ray.dy);
		if (ray.perpwall <= 0)
			ray.perpwall = 2.0;
		ray.lineheight = (int)(HEIGHT / ray.perpwall);
		ray.drawstart = -ray.lineheight / 2 + HEIGHT / 2;
		if (ray.drawstart < 0)
			ray.drawstart = 0;
		ray.drawend = ray.lineheight / 2 + HEIGHT / 2;
		if (ray.drawend >= HEIGHT || ray.drawend < 0)
			ray.drawend = HEIGHT - 1;
		draw_vertline(d_curr, ray);
		ray.x += 1;
		ray.hit = 0;
		(*d_curr)->ray = ray;
	}
	(*d_curr)->ray.x = 0;
	ft_moves(d_curr);
	return (0);
}
