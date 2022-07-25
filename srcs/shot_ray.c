#include <cub3D.h>

void	shot_ray(t_data **d_curr)
{
	t_ray	ray;

	ray = (*d_curr)->ray;
	while (ray.x < WIDTH)
	{
		ray.camerax = 2 * ray.x / (double)WIDTH - 1;
		ray.raydirx = ray.dirx + ray.planex * ray.camerax;
		ray.raydiry = ray.diry + ray.planey * ray.camerax;
		if (ray.raydirx == 0)
			ray.dx = 1e30;
		else
			ray.dx = abs(1 / ray.raydirx);
		if (ray.raydiry == 0)
			ray.dy = 1e30;
		else
			ray.dy = abs(1 / ray.raydiry);
		if (ray.raydirx < 0)
		{
			ray.stepx = -1;
			ray.sidedistx = (ray.posx - ray.mapx) * ray.dx;
		}
		else
		{
			ray.stepx = 1;
			ray.sidedistx = (ray.mapx + 1.0 - ray.posx) * ray.dx;
		}
		if (ray.raydiry < 0)
		{
			ray.stepy = -1;
			ray.sidedisty = (ray.posy - ray.mapy) * ray.dy;
		}
		else
		{
			ray.stepy = 1;
			ray.sidedisty = (ray.mapy + 1.0 - ray.posY) * ray.dy;
		}

		while (!ray.hit)
		{
			if (ray.sidedistx < ray.sidedisty)
			{
				ray.sidedistx += ray.dx;
				ray.mapx += ray.stepx;
				ray.side = 0;
			}
			else
			{
				ray.sidedisty += ray.dy;
				ray.mapy += ray.stepy;
				ray.side = 1;
			}
			if ((*d_curr)->map[ray.mapy][ray.mapx] == '1')
				hit = 1;
		}
		if (!ray.side)
			ray.perpwall = ray.sidedistx - ray.dx;
		else
			ray.perpwall = ray.sidedisty - ray.dy;
		ray.lineheight = (int)(HEIGHT / ray.perpwall);
		ray.drawstart = -ray.lineheight / 2 + HEIGHT / 2;
		if (!ray.drawstart)
			ray.drawstart = 0;
		ray.drawend = ray.lineheight / 2 + HEIGHT / 2;
		if (ray.drawend >= HEIGHT)
			ray.drawend = HEIGHT - 1;
	}
}
