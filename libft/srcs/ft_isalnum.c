/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:24:38 by qbornet           #+#    #+#             */
/*   Updated: 2021/11/04 14:43:16 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
