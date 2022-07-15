/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 03:14:28 by qbornet           #+#    #+#             */
/*   Updated: 2022/07/15 10:38:03 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr_calloc;
	unsigned char	*ptr_init;
	size_t			i;

	i = 0;
	ptr_calloc = malloc(size * count);
	if (!ptr_calloc)
		return (NULL);
	ptr_init = ptr_calloc;
	while (i < (size * count))
	{
		*ptr_init++ = 0;
		i++;
	}
	return (ptr_calloc);
}
