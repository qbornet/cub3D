#include <cub3D.h>

#ifndef MAIN

int	main(int ac, char **av)
{
	if (ac > 2)
		return (ft_retputstr_int("Error: too many arguments\n", 2, 0));
	if (ac == 1)
		return (ft_retputstr_int("Error: need one argument <path_to_file.cub>\n", 2, 0));
	if (!valid_name(av[1]))
		return (ft_retputstr_int("Error: with name doesn't have a .cub extansion\n", 2, 0));
	return (0);
}

#endif
