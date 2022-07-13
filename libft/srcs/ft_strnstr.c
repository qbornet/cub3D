/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:09:06 by qbornet           #+#    #+#             */
/*   Updated: 2022/05/02 12:28:03 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		j;

	if (!*little)
		return ((char *)big);
	while (*big && len > 0)
	{
		j = 0;
		while (big[j] == little[j] && len - j > 0)
		{
			if (little[j + 1] == '\0')
				return ((char *)big);
			j++;
		}
		big++;
		len--;
	}
	return (NULL);
}
