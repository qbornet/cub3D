/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbornet <qbornet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:45:37 by qbornet           #+#    #+#             */
/*   Updated: 2021/11/16 05:58:30 by qbornet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int	ft_nb_len(int n)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
		nbr *= -1;
	if (nbr >= 10)
		return (1 + ft_nb_len(nbr / 10));
	return (1);
}

static char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = -1;
	temp = '0';
	while (str[++j])
		;
	j -= 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		j--;
		i++;
	}
	return (str);
}

static unsigned int	ft_is_negative(int n, int *neg, int *len)
{
	unsigned int	ret;

	ret = n;
	if (n < 0)
	{
		*neg = 1;
		ret = n * -1;
		*len += 1;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	int				i;
	int				len;
	int				neg;
	unsigned int	nbr;
	char			*str;

	i = 0;
	neg = 0;
	len = ft_nb_len(n);
	nbr = ft_is_negative(n, &neg, &len);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len - neg)
	{
		str[i++] = ((nbr % 10) + '0');
		nbr /= 10;
	}
	if (neg)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
