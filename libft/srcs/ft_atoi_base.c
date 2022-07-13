/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:02:56 by qbornet           #+#    #+#             */
/*   Updated: 2022/02/02 14:19:00 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

static int	ft_check_pose(char c, const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (c == str[i])
			return (i);
	}
	return (-1);
}

static int	ft_check_base(const char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '
			|| str[i] == '-' || str[i] == '+')
			return (0);
		j = i;
		while (str[++j])
		{
			if (str[i] == str[j])
				return (0);
		}
	}
	return (1);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int	i;
	int	res;
	int	isneg;

	i = 0;
	res = 0;
	isneg = 1;
	if (!(ft_check_base(base)))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			isneg *= -1;
	while (str[i] && (ft_check_pose(str[i], base) != -1))
	{
		res = res * ft_strlen(base) + ft_check_pose(str[i], base);
		i++;
	}
	return (res * isneg);
}
