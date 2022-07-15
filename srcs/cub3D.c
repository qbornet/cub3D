#include <cub3D.h>

#ifndef MAIN

int	main(int ac, char **av)
{
	int		**colors;
	char	**texture;
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
		for (int i = 0; texture[i]; i++)
			free(texture[i]);
		free(texture);
		return (ft_retputstr_int("Error\nColors are not valid\n", 2, -1));
	}
	for (int i = 0; i < 2; i++)
	{
		printf("[%d]\n", i);
		for (int j = 0; j < 3; j++)
			printf("<%d>\n", colors[i][j]);
	}
	for (int i = 0; texture[i]; i++)
		printf("%s\n", texture[i]);
	for (int i = 0; texture[i]; i++)
		free(texture[i]);
	for (int i = 0; i < 2; i++)
		free(colors[i]);
	free(texture);
	free(colors);
	return (0);
}

#endif
