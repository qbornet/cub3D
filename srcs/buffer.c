/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:56:35 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/15 13:56:37 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	destroy_buffer(t_data **d_curr)
{
	mlx_destroy_image((*d_curr)->mlx, (*d_curr)->buffer.img);
	(*d_curr)->buffer.img = NULL;
	return (0);
}

int	put_buffer(t_data **d_curr)
{
	mlx_put_image_to_window(\
			(*d_curr)->mlx, (*d_curr)->win, (*d_curr)->buffer.img, 0, 0);
	return (0);
}

int	create_buffer(t_data **d_curr)
{
	t_img	buffer;

	buffer = (*d_curr)->buffer;
	buffer.img = mlx_new_image((*d_curr)->mlx, WIDTH, HEIGHT);
	if (!buffer.img)
		return (ft_retputstr_int("Error\nCreation of buffer image\n", 2, -1));
	buffer.addr = (int *)mlx_get_data_addr(\
			buffer.img, &buffer.bits_per_pixel, \
				&buffer.line_length, &buffer.endian);
	(*d_curr)->buffer = buffer;
	return (0);
}
