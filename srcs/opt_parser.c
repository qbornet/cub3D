/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:37 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/31 11:35:12 by jfrancai         ###   ########.fr       */
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

int	ft_digitcom(char c)
{
	if (c == ',' || ft_isdigit(c) || ft_isspace(c))
		return (1);
	return (0);
}

int	opt_colorsatoi(char *str, int *i)
{
	int	res;

	res = 0;
	while (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
	{
		res = res * 10 + (str[*i] - '0');
		*i += 1;
	}
	return (res);
}

int	opt_colors_value(char *to_find, char **r_curr, char *buff, int i)
{
	int		j;
	int		x;
	char	*res;

	j = i;
	x = 0;
	res = *r_curr;
	while (buff[j] && buff[j] != '\n')
		j++;
	if (!buff[j])
		return (-1);
	res = ft_substr(buff, i, (j - i));
	if (!res)
		return (-1);
	while (!ft_isspace(res[x]))
		x++;
	*r_curr = res;
	if (res[0] == to_find[0] && x == 1)
		return (1);
	return (-1);
}
