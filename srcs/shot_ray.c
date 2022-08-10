#include <cub3D.h>

void	setup_texture(t_data **d_curr, t_ray ray)
{
	t_tex	tex;

	tex = (*d_curr)->tex;
	if (ray.side == 0 && ray.raydirx < 0)
		tex.texdir = 0;
	else if (ray.side == 0 && ray.raydirx >= 0)
		tex.texdir = 1;
	else if (ray.side == 1 && ray.raydiry < 0)
		tex.texdir = 2;
	else if (ray.side == 1 && ray.raydiry >= 0)
		tex.texdir = 3;
	if (ray.side == 0)
		tex.wallx = ray.posx + ray.perpwall * ray.raydirx;
	else
		tex.wallx = ray.posy + ray.perpwall * ray.raydiry;
	tex.wallx -= floor(tex.wallx);
	(*d_curr)->tex = tex;
}

void	draw_texture(t_data **d_curr, t_ray ray, int y)
{
	t_data	*f;

	setup_texture(d_curr, ray);
	y = ray.drawstart - 1;
	f = *d_curr;
	f->tex.step = 1.0 * f->data[0].height / ray.lineheight;
	f->tex.texx = (int)(f->tex.wallx * (double)f->data[f->tex.texdir].width);
	if (ray.side == 0 && ray.raydirx > 0)
		f->tex.texx = f->data[f->tex.texdir].width - f->tex.texx - 1;
	if (ray.side == 1 && ray.raydiry < 0)
		f->tex.texx = f->data[f->tex.texdir].width - f->tex.texx - 1;
	f->tex.texpos = (ray.drawstart - HEIGHT / 2 + ray.lineheight / 2) * f->tex.step;
	while (++y <= ray.drawend)
	{
		f->tex.texy = (int)f->tex.texpos & (f->data[f->tex.texdir].height - 1);
		f->tex.texpos += f->tex.step;
		if (y < HEIGHT && ray.x < WIDTH)
			f->buffer.addr[y * f->buffer.line_length / 4 + ray.x] = f->data[f->tex.texdir].addr[f->tex.texy * f->data[f->tex.texdir].line_length / 4 + f->tex.texx];
	}
	*d_curr = f;
}

void	draw_column(t_data **d_curr, t_ray ray)
{
	int		i;

	i = -1;
	ray.drawend = HEIGHT - ray.drawstart;
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
	t_img	buffer;

	ray = (*d_curr)->ray;
	buffer = (*d_curr)->buffer;
	buffer.img = mlx_new_image((*d_curr)->mlx, WIDTH, HEIGHT);
	if (!buffer.img)
		return (ft_retputstr_int("Error\nCreation of buffer image\n", 2, -1) && free_all(d_curr));
	buffer.addr = (int *)mlx_get_data_addr(buffer.img, &buffer.bits_per_pixel, &buffer.line_length, &buffer.endian);
	(*d_curr)->buffer = buffer;
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
		draw_column(d_curr, ray);
		ray.x += 1;
		ray.hit = 0;
		(*d_curr)->ray = ray;
	}
	mlx_put_image_to_window((*d_curr)->mlx, (*d_curr)->win, (*d_curr)->buffer.img, 0, 0);
	(*d_curr)->ray.x = 0;
	mlx_destroy_image((*d_curr)->mlx, (*d_curr)->buffer.img);
	ft_moves(d_curr);
	return (0);
}
