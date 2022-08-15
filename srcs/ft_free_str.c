/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:59:07 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/15 13:59:08 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*ft_retfree_str(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

char	*ft_retfree_tab(char ***tab, size_t len)
{
	size_t	i;

	if (!tab || !*tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
	return (NULL);
}
