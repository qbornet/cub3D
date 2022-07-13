/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:12:59 by qbornet           #+#    #+#             */
/*   Updated: 2022/02/21 18:13:26 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

void	ft_putstr_check(char *s, int *status)
{
	int	check;

	if (!s)
		check = write(1, "(null)", 6);
	else
		check = write(1, s, ft_strlen(s));
	if (check == -1)
		*status = -1;
	else
		*status += check;
}
