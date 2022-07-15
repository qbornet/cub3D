#ifndef TEST_H
# define TEST_H
# define CRITERION_VERBOSITY_LEVEL 1
# define TEXTURE_NORTH "./north_texture"
# define TEXTURE_SOUTH "./south_texture"
# define TEXTURE_WEST "./west_texture"
# define TEXTURE_EAST "./east_texture"
# include <cub3D.h>
# include <criterion/criterion.h>
# include <criterion/new/assert.h>

/* J'ai mis les proto de ces fonctions ici et pas dans cub3D.h,
 * car c'est mieux de tester ces fonctions que celle qui renvoie un tableau 2D
 * (get_texture, get_colors) */
char	*ft_get_texture(char *filename, int direction);
int		*ft_get_colors(char *filename, int level);

TestSuite(ft_get_texture, .description = "This should return texture path");
TestSuite(ft_get_colors, .description = "This should return a colors value");
TestSuite(get_texture, .description = "This should return a 2d array with texture path");
TestSuite(get_colors, .description = "This should return a 2d array with colors value");
TestSuite(valid_name, .description = "This should return a valid map");

#endif
