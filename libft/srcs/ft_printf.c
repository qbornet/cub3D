/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:19:57 by qbornet           #+#    #+#             */
/*   Updated: 2022/02/21 18:20:16 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	int		*status;
	va_list	args;

	i = 0;
	ret = 0;
	status = &ret;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_putargs(args, format[i + 1], status);
			i += 2;
		}
		else
			ft_putchar_check(format[i++], status);
	}
	va_end(args);
	return (ret);
}
