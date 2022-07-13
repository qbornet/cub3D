/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 22:06:33 by qbornet           #+#    #+#             */
/*   Updated: 2022/01/07 14:53:12 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

void	ft_aff_bin(t_int64 data)
{
	int			fd;
	t_uint64	i;
	t_uint64	nbr;

	i = (1ULL << 63);
	fd = 1;
	nbr = data;
	if (nbr & i)
		ft_putstr_fd("1b", fd);
	else
		ft_putstr_fd("0b", fd);
	i = i / 2;
	while (i > 0)
	{
		if (nbr & i)
			ft_putchar_fd('1', fd);
		else
			ft_putchar_fd('0', fd);
		i = i / 2;
	}
	ft_putchar_fd('\n', fd);
}
