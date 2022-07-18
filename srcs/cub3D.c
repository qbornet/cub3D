#include <cub3D.h>

void	ft_print_ret(char **ret, int **colors)
{
	if (ret && *ret)
	{
		for (int i = 0; ret[i]; i++)
			printf("|%s|\n", ret[i]);
	}
	if (colors && *colors)
	{
		for (int i = 0; colors[i]; i++)
		{
			printf("colors[%d]:\n", i);
			for (int j = 0; j < 3; j++)
				printf("[%d][%d]: %d\n", i, j, colors[i][j]);
		}
	}
}

#ifndef MAIN

int	main(int ac, char **av)
{
	int		fd;
	int		size;
	int		**colors;
	char	**texture;
	char	**map;

	if (ac > 2)
		return (ft_retputstr_int("Error: too many arguments\n", 2, 0));
	if (ac == 1)
		return (ft_retputstr_int("Error: need one argument <path_to_file.cub>\n", 2, 0));
	if (!valid_name(av[1]))
		return (ft_retputstr_int("Error: with name doesn't have a .cub extansion\n", 2, 0));
	texture = get_texture(av[1]);
	if (!texture)
		return (ft_retputstr_int("Error\nTexture are not valid\n", 2, -1));
	colors = get_colors(av[1]);
	if (!colors)
	{
		ft_retfree_tab(&texture, 4);
		return (ft_retputstr_int("Error\nColors are not valid\n", 2, -1));
	}
	fd = open(av[1], O_RDONLY | O_NOCTTY);
	if (fd == -1)
		return (-1);
	if (map_parser(fd, &map) < 0)
	{
		for (int i = 0; i < 2; i++)
			free(colors[i]);
		free(colors);
		ft_retfree_tab(&texture, 4);
		return (ft_retputstr_int("Error\nMap is invalid\n", 2, -1));
	}
	ft_print_ret(map, colors);
	ft_print_ret(texture, NULL);
	ft_retfree_tab(&texture, 4);
	size = 0;
	while (map[size])
		size++;
	ft_retfree_tab(&map, size);
	for (int i = 0; i < 2; i++)
		free(colors[i]);
	free(colors);
	return (0);
}

#endif
