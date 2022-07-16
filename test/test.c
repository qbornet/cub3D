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

	path = ft_get_texture("./maps/toto.cub", 'n');
	cr_assert(ne(ptr, path, NULL));
	cr_expect(eq(str, path, "./north_texture"));
	free(path);
	path = ft_get_texture("./maps/toto.cub", 's');
	cr_assert(ne(ptr, path, NULL));
	cr_expect(eq(str, path, "./south_texture"));
	free(path);
	path = ft_get_texture("./maps/toto.cub", 'e');
	cr_assert(ne(ptr, path, NULL));
	cr_expect(eq(str, path, "./east_texture"));
	free(path);
	path = ft_get_texture("./maps/toto.cub", 'w');
	cr_assert(ne(ptr, path, NULL));
	cr_expect(eq(str, path, "./west_texture"));
	free(path);
}

Test(get_texture, parsing)
{
	int		ret;
	char	**res;
	char	*tab[5] = { "./north_texture", "./south_texture", "./west_texture", "./east_texture", NULL };

	res = get_texture("maps/gap.cub");
	cr_assert(ne(ptr, res, NULL));
	for (int i = 0; tab[i]; i++)
	{
		ret = memcmp(tab[i], res[i], strlen(tab[i]) * sizeof(char));
		cr_expect(eq(int, ret, 0));
	}
	for (int i = 0; i < 4; i++)
		if (res[i])
			free(res[i]);
	if (res)
		free(res);
	res = get_texture("./maps/tmp.cub");
	cr_expect(eq(ptr, res, NULL));
}

Test(ft_get_colors, parsing)
{
	int	*tab;

	tab = ft_get_colors("./maps/toto.cub", 'f');
	cr_assert(ne(ptr, tab, NULL));
	cr_expect(eq(int, tab[0], 0));
	cr_expect(eq(int, tab[1], 255));
	cr_expect(eq(int, tab[2], 255));
	free(tab);
	tab = ft_get_colors("./maps/toto.cub", 'c');
	cr_expect(eq(int, tab[0], 255));
	cr_expect(eq(int, tab[1], 255));
	cr_expect(eq(int, tab[2], 255));
	free(tab);
	tab = ft_get_colors("./maps/tmp.cub", 'f'); // valeur non valide pour le floor
	cr_expect(eq(ptr, tab, NULL));
	tab = ft_get_colors("./maps/tmp.cub", 'c'); // valeur non valide pour le ceilling
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

	colors = get_colors("./maps/toto.cub");
	cr_assert(ne(ptr, colors, NULL));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ret = memcmp(&colors[i][j], &tab[i][j], sizeof(int));
			cr_expect(eq(int, ret, 0));
		}
	}
	for (int i = 0; i < 2; i++)
		if (colors[i])
			free(colors[i]);
	if (colors)
		free(colors);
	colors = get_colors("./maps/tmp.cub");
	cr_expect(eq(ptr, colors, NULL));
}

Test(check_line, parsing)
{
	check_line(NULL, NULL);
	cr_expect(eq(int, check_line(NULL, NULL), -1));
	cr_expect(eq(int, check_line("", ""), -1));
	cr_expect(eq(int, check_line("111", ""), -1));
	cr_expect(eq(int, check_line("", "111"), -1));
	//Check first line
	cr_expect(eq(int, check_line(NULL, "11111"), 0));
	cr_expect(eq(int, check_line(NULL, "01111"), -1));
	cr_expect(eq(int, check_line(NULL, "  11110"), -1));
	cr_expect(eq(int, check_line(NULL, "11011  "), -1));
	cr_expect(eq(int, check_line(NULL, "   11111"), 0));
	cr_expect(eq(int, check_line(NULL, "11111    "), 0));
	cr_expect(eq(int, check_line(NULL, "   11111  "), 0));
	cr_expect(eq(int, check_line(NULL, "   11  111  "), 0));
	cr_expect(eq(int, check_line(NULL, "111  111"), 0));
	//Check last line
	cr_expect(eq(int, check_line("11111", NULL), 0));
	cr_expect(eq(int, check_line("01111", NULL), -1));
	cr_expect(eq(int, check_line("  11110", NULL), -1));
	cr_expect(eq(int, check_line("11011  ", NULL), -1));
	cr_expect(eq(int, check_line("   11111", NULL), 0));
	cr_expect(eq(int, check_line("11111    ", NULL), 0));
	cr_expect(eq(int, check_line("   11111  ", NULL), 0));
	cr_expect(eq(int, check_line("   11  111  ", NULL), 0));
	cr_expect(eq(int, check_line("111  111", NULL), 0));
	//Check second line (l_bef is first line)
	cr_expect(eq(int, check_line("11111", "00000"), -1));
	cr_expect(eq(int, check_line("11111", "10000"), -1));
	cr_expect(eq(int, check_line("11111", "00001"), -1));
	cr_expect(eq(int, check_line("11111", "10001"), 0));
	cr_expect(eq(int, check_line(" 11111", "10001"), 0));
	cr_expect(eq(int, check_line("1111 ", "10001"), 0));
	cr_expect(eq(int, check_line("111", "100001"), -1));
	cr_expect(eq(int, check_line("111", "101111"), 0));
	cr_expect(eq(int, check_line("1111", "101"), 0));
	cr_expect(eq(int, check_line("1111", "11"), 0));
	cr_expect(eq(int, check_line("11", "1111"), 0));
	cr_expect(eq(int, check_line("1111", "1"), 0));
	cr_expect(eq(int, check_line("1", "1111"), 0));
	cr_expect(eq(int, check_line("    11 11", "1001"), -1));
	cr_expect(eq(int, check_line("111 11", "1001"), 0));
	cr_expect(eq(int, check_line("111 11    ", "1001"), 0));
	cr_expect(eq(int, check_line("1111", "1001"), 0));
	cr_expect(eq(int, check_line("111111111", "1000000 1"), -1));
	cr_expect(eq(int, check_line("111111111", "1001 1001"), 0));
	cr_expect(eq(int, check_line("111111", "1001 1001"), -1));
	cr_expect(eq(int, check_line("111111", "100 001"), -1));
	cr_expect(eq(int, check_line("1111111111", "10 11 1001"), -1));
	cr_expect(eq(int, check_line("     11111111111", "1111 10001 1001"), 0));
	cr_expect(eq(int, check_line("      1111111111", "1111 10001 1001"), 0));
	cr_expect(eq(int, check_line("11111111111    ", "1111 10001 1001"), -1));
	cr_expect(eq(int, check_line("111111111111111", "1111 10001 1001"), 0));
	cr_expect(eq(int, check_line("1111 11111 1111", "1111 10001 1001"), 0));
	cr_expect(eq(int, check_line("11111111111111", "1111 10001 1001"), 0));
	cr_expect(eq(int, check_line("11111111111111", "10000001100000001"), -1));
	cr_expect(eq(int, check_line("11111111111111", "10001101100101"), 0));
	//Check penultimate (l is last line)
	cr_expect(eq(int, check_line("00000", "11111"), -1));
	cr_expect(eq(int, check_line("10000", "11111"), -1));
	cr_expect(eq(int, check_line("00001", "11111"), -1));
	cr_expect(eq(int, check_line("10001", "11111"), 0));
	cr_expect(eq(int, check_line("10001", " 11111"), 0));
	cr_expect(eq(int, check_line("10001", "1111 "), 0));
	cr_expect(eq(int, check_line("100001", "111"), -1));
	cr_expect(eq(int, check_line("101111", "111"), 0));
	cr_expect(eq(int, check_line("101", "1111"), 0));
	cr_expect(eq(int, check_line("11", "1111"), 0));
	cr_expect(eq(int, check_line("1111", "11"), 0));
	cr_expect(eq(int, check_line("1", "1111"), 0));
	cr_expect(eq(int, check_line("1111", "1"), 0));
	cr_expect(eq(int, check_line("1001", "    11 11"), -1));
	cr_expect(eq(int, check_line("1001", "111 11"), 0));
	cr_expect(eq(int, check_line("1001", "111 11    "), 0));
	cr_expect(eq(int, check_line("1001", "1111"), 0));
	cr_expect(eq(int, check_line("1111", "10001"), 0));
	cr_expect(eq(int, check_line("1000000 1", "111111111"), -1));
	cr_expect(eq(int, check_line("1001 1001", "111111111"), 0));
	cr_expect(eq(int, check_line("1001 1001", "111111"), -1));
	cr_expect(eq(int, check_line("100 001", "111111"), -1));
	cr_expect(eq(int, check_line("10 11 1001", "1111111111"), -1));
	cr_expect(eq(int, check_line("1111 10001 1001", "     11111111111"), 0));
	cr_expect(eq(int, check_line("1111 10001 1001", "      1111111111"), 0));
	cr_expect(eq(int, check_line("1111 10001 1001", "11111111111    "), -1));
	cr_expect(eq(int, check_line("1111 10001 1001", "111111111111111"), 0));
	cr_expect(eq(int, check_line("1111 10001 1001", "1111 11111 1111"), 0));
	cr_expect(eq(int, check_line("1111 10001 1001", "11111111111111"), 0));
	cr_expect(eq(int, check_line("10000001100000001", "11111111111111"), -1));
	cr_expect(eq(int, check_line("10001101100101", "11111111111111"), 0));
	//Check middle line
	cr_expect(eq(int, check_line("00001", "10001"), -1));
	cr_expect(eq(int, check_line("10000", "10001"), -1));
	cr_expect(eq(int, check_line("10001", "00001"), -1));
	cr_expect(eq(int, check_line("10001", "10000"), -1));
	cr_expect(eq(int, check_line("00000", "10001"), -1));
	cr_expect(eq(int, check_line("10001", "00000"), -1));
	cr_expect(eq(int, check_line("00000", "00000"), -1));
	cr_expect(eq(int, check_line("11 01", "10001"), -1));
	cr_expect(eq(int, check_line("10001", "10 11"), -1));
	cr_expect(eq(int, check_line("1000 1", "10 01"), -1));
	cr_expect(eq(int, check_line("10001", "10001"), 0));
	cr_expect(eq(int, check_line("10001", "1001"), 0));
	cr_expect(eq(int, check_line("1001", "10001"), 0));
	cr_expect(eq(int, check_line("10 01", "10001"), -1));
	cr_expect(eq(int, check_line("10 01", "10 01"), -1));
	cr_expect(eq(int, check_line("1 001", "10001"), -1));
	cr_expect(eq(int, check_line("1 001", "11101"), -1));
	cr_expect(eq(int, check_line("1    1", "1    1"), 0));
	cr_expect(eq(int, check_line("10111", "10001"), 0));
	cr_expect(eq(int, check_line("10001", "11101"), 0));
	cr_expect(eq(int, check_line("10111", "11101"), 0));
	cr_expect(eq(int, check_line("101 111", "111 101"), 0));
	cr_expect(eq(int, check_line("10000111 101", "10100111 101"), 0));
	cr_expect(eq(int, check_line("101 101", "101 101"), 0));
	cr_expect(eq(int, check_line("101", "101 101"), -1));
	cr_expect(eq(int, check_line("101 111", "111"), 0));
	cr_expect(eq(int, check_line("101 101", "101"), -1));
	cr_expect(eq(int, check_line("101 111", "101"), 0));
}

Test(ft_rmv_trailing_chr, parsing)
{
	char	*res;

	ft_rmt_chr(NULL, 0);
	cr_expect(eq(ptr, ft_rmt_chr(NULL, 0), NULL));
	res = ft_rmt_chr("toto", 0);
	cr_expect(eq(str, res, "toto"));
	free(res);
	res = ft_rmt_chr("toto", 'o');
	cr_expect(eq(str, res, "tot"));
	free(res);
	res = ft_rmt_chr("toto", 'z');
	cr_expect(eq(str, res, "toto"));
	free(res);
	res = ft_rmt_chr("", 'z');
	cr_expect(eq(str, res, ""));
	free(res);
	res = ft_rmt_chr("toto\n", '\n');
	cr_expect(eq(str, res, "toto"));
	free(res);
}

Test(nrm_line, parsing)
{
	char	*res;
	int		pos;

	pos = 0;
	nrm_line(NULL, NULL);
	cr_expect(eq(ptr, nrm_line(NULL, NULL), NULL));
	pos = 0;
	res = nrm_line("1100011", &pos);
	cr_expect(eq(str, res, "1100011"));
	free(res);
	pos = 0;
	res = nrm_line("11001  1011", &pos);
	cr_expect(eq(str, res, "11001  1011"));
	free(res);
	pos = 0;
	res = nrm_line("1100W11\n", &pos);
	cr_expect(eq(str, res, "1100W11"));
	free(res);
	pos = 0;
	res = nrm_line("1100E11\n", &pos);
	cr_expect(eq(str, res, "1100E11"));
	free(res);
	pos = 0;
	res = nrm_line("11000S1\n", &pos);
	cr_expect(eq(str, res, "11000S1"));
	free(res);
	pos = 0;
	res = nrm_line("1N00011\n", &pos);
	cr_expect(eq(str, res, "1N00011"));
	free(res);
	pos = 0;
	cr_expect(eq(ptr, nrm_line("\n", &pos), NULL));
	pos = 0;
	cr_expect(eq(ptr, nrm_line("110a0011\n", &pos), NULL));
	pos = 0;
	cr_expect(eq(ptr, nrm_line("", &pos), NULL));
	pos = 0;
	cr_expect(eq(ptr, nrm_line("        ", &pos), NULL));
	pos = 0;
	cr_expect(eq(ptr, nrm_line("        \n", &pos), NULL));
	pos = 1;
	res = nrm_line("1100011", &pos);
	cr_expect(eq(str, res, "1100011"));
	free(res);
	pos = 1;
	res = nrm_line("11001  1011", &pos);
	cr_expect(eq(str, res, "11001  1011"));
	free(res);
	pos = 1;
	res = nrm_line("1100W11\n", &pos);
	cr_assert(eq(ptr, res, NULL));
	free(res);
	pos = 1;
	res = nrm_line("1100E11\n", &pos);
	cr_assert(eq(ptr, res, NULL));
	free(res);
	pos = 1;
	res = nrm_line("11000S1\n", &pos);
	cr_assert(eq(ptr, res, NULL));
	free(res);
	pos = 1;
	res = nrm_line("1N00011\n", &pos);
	cr_assert(eq(ptr, res, NULL));
	free(res);
	pos = 1;
	cr_expect(eq(ptr, nrm_line("\n", &pos), NULL));
	pos = 1;
	cr_expect(eq(ptr, nrm_line("110a0011\n", &pos), NULL));
	pos = 1;
	cr_expect(eq(ptr, nrm_line("", &pos), NULL));
	pos = 1;
	cr_expect(eq(ptr, nrm_line("        ", &pos), NULL));
	pos = 1;
	cr_expect(eq(ptr, nrm_line("        \n", &pos), NULL));
}

Test(map_parser, parsing_map0)
{
	int	fd;

	fd = open("./maps/map0.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), 0));
	cr_assert(ne(int, close(fd), -1));
}

// Valid map
Test(map_parser, parsing_map2)
{
	int	fd;

	fd = open("./maps/map2.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), 0));
	cr_assert(ne(int, close(fd), -1));
}

Test(map_parser, parsing_map3)
{
	int	fd;

	fd = open("./maps/map3.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), 0));
	cr_assert(ne(int, close(fd), -1));
}

Test(map_parser, parsing_map4)
{
	int	fd;

	fd = open("./maps/map4.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), 0));
	cr_assert(ne(int, close(fd), -1));
}

Test(map_parser, parsing_map5)
{
	int	fd;

	fd = open("./maps/map5.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), 0));
	cr_assert(ne(int, close(fd), -1));
}

// Not valid map
Test(map_parser, parsing_map0_err)
{
	int	fd;

	fd = open("./maps/err/map0_err.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), -1));
	cr_assert(ne(int, close(fd), -1));
}
	
Test(map_parser, parsing_map1_err)
{
	int	fd;

	fd = open("./maps/err/map1_err.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), -1));
	cr_assert(ne(int, close(fd), -1));
}

Test(map_parser, parsing_map2_err)
{
	int	fd;

	fd = open("./maps/err/map2_err.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), -1));
	cr_assert(ne(int, close(fd), -1));
}

Test(map_parser, parsing_map5_err)
{
	int	fd;

	fd = open("./maps/err/map5_err.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), -1));
	cr_assert(ne(int, close(fd), -1));
}

Test(map_parser, parsing_map6_err)
{
	int	fd;

	fd = open("./maps/err/map6_err.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), -1));
	cr_assert(ne(int, close(fd), -1));
}

Test(map_parser, parsing_map7_err)
{
	int	fd;

	fd = open("./maps/err/map7_err.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), -1));
	cr_assert(ne(int, close(fd), -1));
}

Test(map_parser, parsing_map8_err)
{
	int	fd;

	fd = open("./maps/err/map8_err.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), -1));
	cr_assert(ne(int, close(fd), -1));
}

Test(map_parser, parsing_map9_err)
{
	int	fd;

	fd = open("./maps/err/map9_err.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), -1));
	cr_assert(ne(int, close(fd), -1));
}

Test(map_parser, parsing_map10_err)
{
	int	fd;

	fd = open("./maps/err/map10_err.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), -1));
	cr_assert(ne(int, close(fd), -1));
}

Test(map_parser, parsing_map11_err)
{
	int	fd;

	fd = open("./maps/err/map11_err.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), -1));
	cr_assert(ne(int, close(fd), -1));
}

Test(map_parser, parsing_map12_err)
{
	int	fd;

	fd = open("./maps/err/map12_err.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), -1));
	cr_assert(ne(int, close(fd), -1));
}

Test(map_parser, parsing_map13_err)
{
	int	fd;

	fd = open("./maps/err/map13_err.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), -1));
	cr_assert(ne(int, close(fd), -1));
}
