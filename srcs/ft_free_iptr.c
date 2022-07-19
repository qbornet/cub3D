#include <cub3D.h>

int	*ft_retfree_iptr(int *tab)
{
	free(tab);
	return (NULL);
}
