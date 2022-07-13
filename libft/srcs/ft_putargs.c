/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:17:57 by qbornet           #+#    #+#             */
/*   Updated: 2022/02/21 18:18:38 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

void	ft_putargs(va_list args, char c, int *status)
{
	if (c == '%')
		ft_putchar_check('%', status);
	else if (c == 'c')
		ft_putchar_check((unsigned char)va_arg(args, int), status);
	else if (c == 's')
		ft_putstr_check(va_arg(args, char *), status);
	else if (c == 'p')
	{
		ft_putchar_check('0', status);
		ft_putchar_check('x', status);
		ft_putaddrs((t_uint64)va_arg(args, void *), status);
	}
	else if (c == 'i' || c == 'd')
		ft_putnbr_printf(va_arg(args, int), status);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), status);
	else if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), status);
	else if (c == 'X')
		ft_puthex_maj(va_arg(args, unsigned int), status);
}
