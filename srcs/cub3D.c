/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <jfrancai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:56:43 by jfrancai          #+#    #+#             */
/*   Updated: 2022/08/31 09:10:24 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/*
void	ft_print_result(char **texture, int **colors)
{
	if (colors && *colors)
	{
		printf("E_FLOOR:\n");
		for (int j = 0; colors[E_FLOOR][j] && j < 3; j++)
			printf("<%d>\n", colors[E_FLOOR][j]);
		printf("E_CELLING:\n");
		for (int j = 0; colors[E_CELLING][j] && j < 3; j++)
			printf("<%d>\n", colors[E_CELLING][j]);
	}
	if (texture && *texture)
		for (int i = 0; texture[i]; i++)
			printf("%s\n", texture[i]);
}
*/

int	free_all(t_data **d_curr)
{
	int		i;
	t_data	*frame;

	i = -1;
	frame = *d_curr;
	ft_retfree_tab(&frame->texture, 4);
	while (frame->colors && ++i < 2)
		free(frame->colors[i]);
	free(frame->colors);
	i = 0;
	while (frame->map && frame->map[i])
		i++;
	if (frame->map)
		ft_retfree_tab(&frame->map, i);
	destroy_mlx(&frame);
	if (frame->mlx)
		free(frame->mlx);
	free(frame);
	exit(0);
}

int	frame_alloc(t_data **d_curr, char *filename)
{
	int		fd;

	(*d_curr) = ft_calloc(1, sizeof(t_data));
	if (!*d_curr)
		return (-1);
	(*d_curr)->texture = get_texture(filename);
	if (!(*d_curr)->texture)
		return (ft_retputstr_int("Error\nTexture are not valid\n", 2, -1));
	(*d_curr)->colors = get_colors(filename);
	if (!(*d_curr)->colors)
	{
		ft_retfree_tab(&(*d_curr)->texture, 4);
		return (ft_retputstr_int("Error\nColors are not valid\n", 2, -1));
	}
	fd = open(filename, O_RDONLY | O_NOCTTY);
	if (fd == -1)
		return (ft_retputstr_int("Error\nNot valide filename\n", 2, -1));
	if (map_parser(fd, &(*d_curr)->map) < 0)
	{
		close(fd);
		return (ft_retputstr_int("Error\nMap is invalid\n", 2, -1));
	}
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*frame;

	if (ac > 2)
		return (ft_retputstr_int("Error\nToo many arguments\n", 2, 0));
	if (ac == 1)
		return (ft_retputstr_int(\
					"Error\nNeed one argument <path_to_file.cub>\n", 2, 0));
	if (valid_name(av[1]))
		return (ft_retputstr_int(\
					"Error\nWith name doesn't have a .cub extansion\n", 2, 0));
	if (frame_alloc(&frame, av[1]) < 0)
		return (free_all(&frame));
	start_window(&frame);
	return (free_all(&frame));
}
