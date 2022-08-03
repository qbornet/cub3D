#include <cub3D.h>

static void	move_fb(t_data **d_curr)
{
	t_ray	ray;
	t_data	*frame;

	frame = *d_curr;
	ray = frame->ray;
	ray.movespeed = 0.1;
	if (frame->forward)
	{
		if (frame->map[(int)(ray.posx + ray.dirx * ray.movespeed)][(int)ray.posy] == '0')
			ray.posx += ray.dirx * ray.movespeed;
		if (frame->map[(int)ray.posx][(int)(ray.posy + ray.diry * ray.movespeed)] == '0')
			ray.posy += ray.diry * ray.movespeed;
	}
	else if (frame->backward)
	{
		if (frame->map[(int)(ray.posx - ray.dirx * ray.movespeed)][(int)ray.posy] == '0')
			ray.posx -= ray.dirx * ray.movespeed;
		else if (frame->map[(int)ray.posx][(int)(ray.posy - ray.posy * ray.movespeed)] == '0')
			ray.posy -= ray.diry * ray.movespeed;
	}
	frame->ray = ray;
	*d_curr = frame;
}

static void	move_lr(t_data **d_curr)
{
	t_ray	*ray;
	double	old_dirx;
	double	old_planex;

	ray = &(*d_curr)->ray;
	ray->rotspeed = ft_deg2rad(0.33);
	old_dirx = ray->dirx;
	old_planex = ray->planex;
	if ((*d_curr)->left)
	{
		ray->dirx = ray->dirx * cos(ray->rotspeed) - ray->diry * sin(ray->rotspeed);
		ray->diry = old_dirx * sin(ray->rotspeed) + ray->diry * cos(ray->rotspeed);
		ray->planex = ray->planex * cos(ray->rotspeed) - ray->planey * sin(ray->rotspeed);
		ray->planey = old_planex * sin(ray->rotspeed) + ray->planey * cos(ray->rotspeed);
	}
	else if ((*d_curr)->right)
	{
		ray->dirx = ray->dirx * cos(-ray->rotspeed) - ray->diry * sin(-ray->rotspeed);
		ray->diry = old_dirx * sin(-ray->rotspeed) + ray->diry * cos(-ray->rotspeed);
		ray->planex = ray->planex * cos(-ray->rotspeed) - ray->planey * sin(-ray->rotspeed);
		ray->planey = old_planex * sin(-ray->rotspeed) + ray->planey * cos(-ray->rotspeed);
	}
	(*d_curr)->ray = *ray;
}

void	ft_moves(t_data **d_curr)
{
	if ((*d_curr)->forward || (*d_curr)->backward)
		move_fb(d_curr);
	else if ((*d_curr)->left || (*d_curr)->right)
		move_lr(d_curr);
}
