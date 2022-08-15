/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:56:49 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/15 13:56:50 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

double	ft_rad2deg(double radians)
{
	return (radians * (180.0 / M_PI));
}

double	ft_deg2rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}
