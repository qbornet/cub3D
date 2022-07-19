#include <cub3D.h>

void	ft_print_result(char **texture, int **colors)
{
	for (int i = 0; i < 2; i++)
	{
		printf("[%d]\n", i);
		for (int j = 0; j < 3; j++)
			printf("<%d>\n", colors[i][j]);
	}
	for (int i = 0; texture[i]; i++)
		printf("%s\n", texture[i]);
}

int	free_all(t_data **d_curr)
{
	int		i;
	t_data	*frame;

	i = -1;
	frame = *d_curr;
	ft_retfree_tab(&frame->texture, 4);
	while (++i < 2)
		free(frame->colors[i]);
	free(frame->colors);
	mlx_clear_window(frame->mlx, frame->win);
	mlx_destroy_window(frame->mlx, frame->win);
	mlx_destroy_display(frame->mlx);
	free(frame->mlx);
	free(frame);
	exit(0);
}

int	frame_alloc(t_data **d_curr, char *filename)
{
	t_data	*frame;

	frame = *d_curr;
	frame = ft_calloc(1, sizeof(t_data));
	if (!frame)
		return (-1);
	frame->texture = get_texture(filename);
	if (!frame->texture)
		return (ft_retputstr_int("Error\nTexture are not valid\n", 2, -1));
	frame->colors = get_colors(filename);
	if (!frame->colors)
	{
		ft_retfree_tab(&frame->texture, 4);
		return (ft_retputstr_int("Error\nColors are not valid\n", 2, -1));
	}
	*d_curr = frame;
	return (0);
}

#ifndef MAIN

int	main(int ac, char **av)
{
	t_data	*frame;

	if (ac > 2)
		return (ft_retputstr_int("Error: too many arguments\n", 2, 0));
	if (ac == 1)
		return (ft_retputstr_int("Error: need one argument <path_to_file.cub>\n", 2, 0));
	if (!valid_name(av[1]))
		return (ft_retputstr_int("Error: with name doesn't have a .cub extansion\n", 2, 0));
	frame_alloc(&frame, av[1]);
	start_window(&frame);
	return (free_all(&frame));
}

#endif
