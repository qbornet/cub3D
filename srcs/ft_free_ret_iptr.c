#include <cub3D.h>

int	*ft_free_ret_iptr(int *tab)
{
	free(tab);
	return (NULL);
}
