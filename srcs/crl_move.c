#include <cub3D.h>

void	move_crl_l(t_data **d_curr)
{
	t_ray	ray;
	double	old_dirx;
	double	old_planex;

	ray = (*d_curr)->ray;
	if ((*d_curr)->forward)
	{
		if ((*d_curr)->map[(int)(ray.posx + ray.dirx * ray.movespeed)][(int)ray.posy] == '0')
			ray.posx += ray.dirx * ray.movespeed;
		if ((*d_curr)->map[(int)ray.posx][(int)(ray.posy + ray.diry * ray.movespeed)] == '0')
			ray.posy += ray.diry * ray.movespeed;
	}
	if ((*d_curr)->left)
	{
		old_dirx = ray.dirx;
		old_planex = ray.planex;
		ray.dirx = ray.dirx * cos(ray.rotspeed) - ray.diry * sin(ray.rotspeed);
		ray.diry = old_dirx * sin(ray.rotspeed) + ray.diry * cos(ray.rotspeed);
		ray.planex = ray.planex * cos(ray.rotspeed) - ray.planey * sin(ray.rotspeed);
		ray.planey = old_planex * sin(ray.rotspeed) + ray.planey * cos(ray.rotspeed);
	}
	(*d_curr)->ray = ray;
}

void	move_crl_r(t_data **d_curr)
{
	t_ray	ray;
	double	old_dirx;
	double	old_planex;

	ray = (*d_curr)->ray;
	if ((*d_curr)->forward)
	{
		if ((*d_curr)->map[(int)(ray.posx + ray.dirx * ray.movespeed)][(int)ray.posy] == '0')
			ray.posx += ray.dirx * ray.movespeed;
		if ((*d_curr)->map[(int)ray.posx][(int)(ray.posy + ray.diry * ray.movespeed)] == '0')
			ray.posy += ray.diry * ray.movespeed;
	}
	if ((*d_curr)->right)
	{
		old_dirx = ray.dirx;
		old_planex = ray.planex;
		ray.dirx = ray.dirx * cos(-ray.rotspeed) - ray.diry * sin(-ray.rotspeed);
		ray.diry = old_dirx * sin(-ray.rotspeed) + ray.diry * cos(-ray.rotspeed);
		ray.planex = ray.planex * cos(-ray.rotspeed) - ray.planey * sin(-ray.rotspeed);
		ray.planey = old_planex * sin(-ray.rotspeed) + ray.planey * cos(-ray.rotspeed);
	}
	(*d_curr)->ray = ray;
}

void	move_bcrl_l(t_data **d_curr)
{
	t_ray	ray;
	double	old_dirx;
	double	old_planex;

	ray = (*d_curr)->ray;
	if ((*d_curr)->backward)
	{
		if (!((ray.posx - ray.dirx * 0.05) < 0)
			&& (*d_curr)->map[(int)(ray.posx - ray.dirx * ray.movespeed)][(int)ray.posy] == '0')
			ray.posx -= ray.dirx * ray.movespeed;
		if (!((ray.posy - ray.diry * 0.05) < 0)
			&& (*d_curr)->map[(int)ray.posx][(int)(ray.posy - ray.diry * ray.movespeed)] == '0')
			ray.posy -= ray.diry * ray.movespeed;
	}
	if ((*d_curr)->left)
	{
		// reverse turn right
		old_dirx = ray.dirx;
		old_planex = ray.planex;
		ray.dirx = ray.dirx * cos(-ray.rotspeed) - ray.diry * sin(-ray.rotspeed);
		ray.diry = old_dirx * sin(-ray.rotspeed) + ray.diry * cos(-ray.rotspeed);
		ray.planex = ray.planex * cos(-ray.rotspeed) - ray.planey * sin(-ray.rotspeed);
		ray.planey = old_planex * sin(-ray.rotspeed) + ray.planey * cos(-ray.rotspeed);
	}
	(*d_curr)->ray = ray;
}

void	move_bcrl_r(t_data **d_curr)
{
	t_ray	ray;
	double	old_dirx;
	double	old_planex;

	ray = (*d_curr)->ray;
	if ((*d_curr)->backward)
	{
		if (!((ray.posx - ray.dirx * 0.05) < 0)
			&& (*d_curr)->map[(int)(ray.posx - ray.dirx * ray.movespeed)][(int)ray.posy] == '0')
			ray.posx -= ray.dirx * ray.movespeed;
		if (!((ray.posy - ray.diry * 0.05) < 0)
			&& (*d_curr)->map[(int)ray.posx][(int)(ray.posy - ray.diry * ray.movespeed)] == '0')
			ray.posy -= ray.diry * ray.movespeed;
	}
	if ((*d_curr)->right)
	{
		// reverse turn left
		old_dirx = ray.dirx;
		old_planex = ray.planex;
		ray.dirx = ray.dirx * cos(ray.rotspeed) - ray.diry * sin(ray.rotspeed);
		ray.diry = old_dirx * sin(ray.rotspeed) + ray.diry * cos(ray.rotspeed);
		ray.planex = ray.planex * cos(ray.rotspeed) - ray.planey * sin(ray.rotspeed);
		ray.planey = old_planex * sin(ray.rotspeed) + ray.planey * cos(ray.rotspeed);
	}
	(*d_curr)->ray = ray;
}
