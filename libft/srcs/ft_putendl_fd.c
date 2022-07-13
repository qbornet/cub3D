/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 04:28:43 by qbornet           #+#    #+#             */
/*   Updated: 2021/11/16 05:16:16 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	char	c;

	c = '\n';
	if (!s)
		return ;
	while (*s)
		if ((write(fd, s++, 1) != -1))
			;
	if ((write(fd, &c, 1) != -1))
		;
}
