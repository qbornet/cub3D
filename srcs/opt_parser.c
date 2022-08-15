/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:37 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/15 13:59:38 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	opt_setdirection(char **t_curr, int direction)
{
	char	*to_find;

	to_find = NULL;
	if (direction == 'n')
		to_find = "NO";
	else if (direction == 's')
		to_find = "SO";
	else if (direction == 'e')
		to_find = "EA";
	else if (direction == 'w')
		to_find = "WE";
	*t_curr = to_find;
}

int	ft_check_numconv(int input)
{
	static int	in;

	if (in > 3)
		return (-1);
	if (input)
	{
		in = 0;
		return (0);
	}
	in++;
	return (0);
}

int	opt_colorsatoi(char *str, int *i)
{
	int	res;

	res = 0;
	if (ft_check_numconv(0) < 0)
		return (256);
	while (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
	{
		res = res * 10 + (str[*i] - '0');
		*i += 1;
	}
	return (res);
}

void	opt_check_commas(char *str, int *i, int *count)
{
	while (str[*i] && !ft_isdigit(str[*i]))
	{
		if (str[*i] == ',')
			*count += 1;
		*i += 1;
	}
}
