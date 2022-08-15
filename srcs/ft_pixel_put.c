/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:15 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/15 13:59:16 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	ft_pixel_put(t_img *data, int x, int y, int colors)
{
	int	*dst;

	dst = data->addr + (y * data->line_length / 4 + x);
	*(unsigned int *)dst = colors;
}
