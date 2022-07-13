/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:14:56 by qbornet           #+#    #+#             */
/*   Updated: 2022/02/21 18:31:58 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

void	ft_putaddrs(t_uint64 addrs, int *status)
{
	char		*base;

	base = "0123456789abcdef";
	if (addrs >= 16)
		ft_putaddrs(addrs / 16, status);
	ft_putchar_check(base[addrs % 16], status);
}

void	ft_putnbr_printf(int nb, int *status)
{
	unsigned int	nbr;

	nbr = nb;
	if (nb < 0)
	{
		ft_putchar_check('-', status);
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr_printf(nbr / 10, status);
	ft_putchar_check((nbr % 10) + '0', status);
}

void	ft_putnbr_unsigned(unsigned int nb, int *status)
{
	if (nb >= 10)
		ft_putnbr_unsigned(nb / 10, status);
	ft_putchar_check((nb % 10) + '0', status);
}

void	ft_puthex(unsigned int nb, int *status)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
		ft_puthex(nb / 16, status);
	ft_putchar_check(base[nb % 16], status);
}

void	ft_puthex_maj(unsigned int nb, int *status)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nb >= 16)
		ft_puthex_maj(nb / 16, status);
	ft_putchar_check(base[nb % 16], status);
}
