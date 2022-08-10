#include <cub3D.h>

void	draw_vertline(t_data **d_curr, t_ray ray)
{
	int	i;

	i = 0;
	while (i < ray.drawstart)
	{
		ft_pixel_put(&(*d_curr)->data[0], ray.x, i, (*d_curr)->ccolors);
		i++;
	}
	while (ray.drawstart < ray.drawend)
	{
		ft_pixel_put(&(*d_curr)->data[0], ray.x, ray.drawstart, 0xFF);
		ray.drawstart += 1;
	}
	i = ray.drawend;
	while (i < HEIGHT)
	{
		ft_pixel_put(&(*d_curr)->data[0], ray.x, i, (*d_curr)->fcolors);
		i++;
	}
}

int	shot_ray(t_data **d_curr)
{
	t_ray	ray;
	static int	prev = 0;
	int	x;
	int	y;
	t_data	*frame;

	frame = *d_curr;

	if (frame->mouse_move)
	{
		mlx_mouse_get_pos(frame->mlx, frame->win, &x, &y);
		if (x == prev)
		{
			frame->left = 0;
			frame->right = 0;
		}
		if (x == 0)
			mlx_mouse_move(frame->mlx, frame->win, WIDTH - 1, y);
		else if (x == WIDTH - 1)
			mlx_mouse_move(frame->mlx, frame->win, 0, y);
		prev = x;
	}

	ray = (*d_curr)->ray;
	while (ray.x < WIDTH)
	{
		ray.camerax = 2 * ray.x / (double)WIDTH - 1;
		ray.raydirx = ray.dirx + ray.planex * ray.camerax;
		ray.raydiry = ray.diry + ray.planey * ray.camerax;
		ray.mapx = (int)ray.posx;
		ray.mapy = (int)ray.posy;
		if (ray.raydirx == 0)
			ray.dx = 0;
		else
			ray.dx = fabs(1 / ray.raydirx);
		if (ray.raydiry == 0)
			ray.dy = 0;
		else
			ray.dy = fabs(1 / ray.raydiry);
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
		if (ray.side == 0)
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
	mlx_put_image_to_window((*d_curr)->mlx, (*d_curr)->win, (*d_curr)->data[0].img, 0, 0);
	(*d_curr)->ray.x = 0;
	ft_moves(d_curr);
	return (0);
}
