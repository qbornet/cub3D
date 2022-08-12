#include <cub3D.h>

static void	move_fb(t_data **d_curr)
{
	t_ray	ray;
	t_data	*frame;

	frame = *d_curr;
	if (frame->forward && frame->backward)
		return ;
	ray = frame->ray;
	ray.movespeed = 0.05;
	if (frame->forward)
	{
		if (frame->map[(int)(ray.posx + ray.dirx * ray.movespeed)][(int)ray.posy] == '0')
			ray.posx += ray.dirx * ray.movespeed;
		if (frame->map[(int)ray.posx][(int)(ray.posy + ray.diry * ray.movespeed)] == '0')
			ray.posy += ray.diry * ray.movespeed;
	}
	else if (frame->backward)
	{
		if (!((ray.posx - ray.dirx * 0.05) < 0) && frame->map[(int)(ray.posx - ray.dirx * ray.movespeed)][(int)ray.posy] == '0')
			ray.posx -= ray.dirx * ray.movespeed;
		if (!((ray.posy - ray.diry * 0.05) < 0) && frame->map[(int)ray.posx][(int)(ray.posy - ray.diry * ray.movespeed)] == '0')
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
	if ((*d_curr)->left && (*d_curr)->right)
		return ;
	ray->rotspeed = ft_deg2rad(0.66);
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
	t_data	*frame;

	frame = *d_curr;
	if (!frame->mouse_mode && frame->forward && frame->left)
		move_crl_l(d_curr);
	else if (!frame->mouse_mode && frame->forward && frame->right)
		move_crl_r(d_curr);
	else if (!frame->mouse_mode && frame->backward && frame->left)
		move_bcrl_l(d_curr);
	else if (!frame->mouse_mode && frame->backward && frame->right)
		move_bcrl_r(d_curr);
	else if (frame->forward || frame->backward)
		move_fb(d_curr);
	else if (!frame->mouse_mode && (frame->left || frame->right))
		move_lr(d_curr);
}
