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
