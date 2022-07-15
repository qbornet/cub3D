#include <test.h>

Test(valid_name, parsing)
{
	cr_assert(ne(int, valid_name("map.cub"), -1));
	cr_expect(eq(int, valid_name("map.cub"), 1));
	cr_assert(ne(int, valid_name("./map.cub"), -1));
	cr_expect(eq(int, valid_name("./map.cub"), 1));
	cr_assert(ne(int, valid_name("..cub"), -1));
	cr_expect(eq(int, valid_name("..cub"), 0));
	cr_assert(ne(int, valid_name("/path/to/file.cub"), -1));
	cr_expect(eq(int, valid_name("/path/to/file.cub"), 1));
	cr_assert(ne(int, valid_name("/dev/urandom"), -1));
	cr_expect(eq(int, valid_name("/dev/urandom"), 0));
	cr_assert(ne(int, valid_name(".asdfad.cub"), -1));
	cr_expect(eq(int, valid_name(".asdfad.cub"), 1));
	cr_assert(ne(int, valid_name(".asdfad.cub.cub"), -1));
	cr_expect(eq(int, valid_name(".asdfad.cub.cub"), 1));
}

Test(ft_get_texture, parsing)
{
	char	*path;

	path = ft_get_texture("./map/toto.cub", 'n');
	cr_assert(ne(ptr, path, NULL));
	cr_expect(eq(str, path, "./north_texture"));
	path = ft_get_texture("./map/toto.cub", 's');
	cr_assert(ne(ptr, path, NULL));
	cr_expect(eq(str, path, "./south_texture"));
	path = ft_get_texture("./map/toto.cub", 'e');
	cr_assert(ne(ptr, path, NULL));
	cr_expect(eq(str, path, "./east_texture"));
	path = ft_get_texture("./map/toto.cub", 'w');
	cr_assert(ne(ptr, path, NULL));
	cr_expect(eq(str, path, "./west_texture"));
}

Test(get_texture, parsing)
{
	int		ret;
	char	**res;
	char	*tab[5] = { "./north_texture", "./south_texture", "./west_texture", "./east_texture", NULL };

	res = get_texture("map/gap.cub");
	cr_assert(ne(ptr, res, NULL));
	for (int i = 0; tab[i]; i++)
	{
		ret = memcmp(tab[i], res[i], strlen(tab[i]) * sizeof(char));
		cr_expect(eq(int, ret, 0));
	}
	res = get_texture("./map/tmp.cub");
	cr_expect(eq(ptr, res, NULL));
}

Test(ft_get_colors, parsing)
{
	int	*tab;

	tab = ft_get_colors("./map/toto.cub", 'f');
	cr_assert(ne(ptr, tab, NULL));
	cr_expect(eq(int, tab[0], 0));
	cr_expect(eq(int, tab[1], 255));
	cr_expect(eq(int, tab[2], 255));
	tab = ft_get_colors("./map/toto.cub", 'c');
	cr_expect(eq(int, tab[0], 255));
	cr_expect(eq(int, tab[1], 255));
	cr_expect(eq(int, tab[2], 255));
	tab = ft_get_colors("./map/tmp.cub", 'f'); // valeur non valide pour le floor
	cr_expect(eq(ptr, tab, NULL));
	tab = ft_get_colors("./map/tmp.cub", 'c'); // valeur non valide pour le ceilling
	cr_expect(eq(ptr, tab, NULL));
}

Test(get_colors, parsing)
{
	int	**colors;
	int	tab[2][3] = {
		{ 0, 255, 255 },
		{ 255, 255, 255 }
	};
	int	ret;

	colors = get_colors("./map/toto.cub");
	cr_assert(ne(ptr, colors, NULL));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ret = memcmp(&colors[i][j], &tab[i][j], sizeof(int));
			cr_expect(eq(int, ret, 0));
		}
	}
	colors = get_colors("./map/tmp.cub");
	cr_expect(eq(ptr, colors, NULL));
}
