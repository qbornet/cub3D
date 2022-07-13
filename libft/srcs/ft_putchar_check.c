/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:13:48 by qbornet           #+#    #+#             */
/*   Updated: 2022/02/21 18:14:13 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

void	ft_putchar_check(unsigned char c, int *status)
{
	int	check;

	check = write(1, &c, 1);
	if (check == -1)
		*status = -1;
	else
		*status += 1;
}
