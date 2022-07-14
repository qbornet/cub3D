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

/*
Test(get_texture, parsing)
{
	cr_assert(ne(ptr, get_texture("map.cub", 'n'), NULL));
	cr_expect(eq(str, get_texture("map.cub", 'n'), TEXTURE_NORTH);
	cr_assert(ne(ptr, get_texture("map.cub", 's'), NULL));
	cr_expect(eq(str, get_texture("map.cub", 's'), TEXTURE_SOUTH);
	cr_assert(ne(ptr, get_texture("map.cub", 'e'), NULL));
	cr_expect(eq(str, get_texture("map.cub", 'e'), TEXTURE_EAST);
	cr_assert(ne(ptr, get_texture("map.cub", 'w'), NULL));
	cr_expect(eq(str, get_texture("map.cub", 'w'), TEXTURE_WEST);
}
*/

Test(check_line, parsing)
{
	check_line(NULL, NULL);
	cr_assert(eq(int, check_line(NULL, NULL), -1));
	cr_assert(eq(int, check_line("", ""), -1));
	cr_assert(eq(int, check_line("111", ""), -1));
	cr_assert(eq(int, check_line("", "111"), -1));
	//Check first line
	cr_expect(eq(int, check_line(NULL, "11111"), 0));
	cr_assert(eq(int, check_line(NULL, "01111"), -1));
	cr_assert(eq(int, check_line(NULL, "  11110"), -1));
	cr_assert(eq(int, check_line(NULL, "11011  "), -1));
	cr_expect(eq(int, check_line(NULL, "   11111"), 0));
	cr_expect(eq(int, check_line(NULL, "11111    "), 0));
	cr_expect(eq(int, check_line(NULL, "   11111  "), 0));
	cr_expect(eq(int, check_line(NULL, "   11  111  "), 0));
	cr_expect(eq(int, check_line(NULL, "111  111"), 0));
	//Check last line
	cr_expect(eq(int, check_line("11111", NULL), 0));
	cr_assert(eq(int, check_line("01111", NULL), -1));
	cr_assert(eq(int, check_line("  11110", NULL), -1));
	cr_assert(eq(int, check_line("11011  ", NULL), -1));
	cr_expect(eq(int, check_line("   11111", NULL), 0));
	cr_expect(eq(int, check_line("11111    ", NULL), 0));
	cr_expect(eq(int, check_line("   11111  ", NULL), 0));
	cr_expect(eq(int, check_line("   11  111  ", NULL), 0));
	cr_expect(eq(int, check_line("111  111", NULL), 0));
	//Check second line (l_bef is first line)
	cr_assert(eq(int, check_line("11111", "00000"), -1));
	cr_assert(eq(int, check_line("11111", "10000"), -1));
	cr_assert(eq(int, check_line("11111", "00001"), -1));
	cr_expect(eq(int, check_line("11111", "10001"), 0));
	cr_assert(eq(int, check_line(" 11111", "10001"), -1));
	cr_assert(eq(int, check_line("1111 ", "10001"), -1));
	cr_assert(eq(int, check_line("111", "100001"), -1));
	cr_expect(eq(int, check_line("111", "101111"), 0));
	cr_expect(eq(int, check_line("1111", "101"), 0));
	cr_expect(eq(int, check_line("1111", "11"), 0));
	cr_expect(eq(int, check_line("11", "1111"), 0));
	cr_expect(eq(int, check_line("1111", "1"), 0));
	cr_expect(eq(int, check_line("1", "1111"), 0));
	cr_assert(eq(int, check_line("    11 11", "1001"), -1));
	cr_assert(eq(int, check_line("111 11", "1001"), -1));
	cr_assert(eq(int, check_line("111 11    ", "1001"), -1));
	cr_expect(eq(int, check_line("1111", "1001"), 0));
	cr_assert(eq(int, check_line("1111", "10001"), -1));
	cr_assert(eq(int, check_line("111111111", "1000000 1"), -1));
	cr_expect(eq(int, check_line("111111111", "1001 1001"), 0));
	cr_assert(eq(int, check_line("111111", "1001 1001"), -1));
	cr_assert(eq(int, check_line("1111111111", "10 11 1001"), -1));
	cr_expect(eq(int, check_line("     11111111111", "1111 10001 1001"), 0));
	cr_assert(eq(int, check_line("      1111111111", "1111 10001 1001"), -1));
	cr_assert(eq(int, check_line("11111111111    ", "1111 10001 1001"), -1));
	cr_expect(eq(int, check_line("111111111111111", "1111 10001 1001"), 0));
	cr_expect(eq(int, check_line("1111 11111 1111", "1111 10001 1001"), 0));
	cr_assert(eq(int, check_line("11111111111111", "1111 10001 1001"), -1));
	cr_assert(eq(int, check_line("11111111111111", "10000001100000001"), -1));
	cr_expect(eq(int, check_line("11111111111111", "10001101100101"), 0));
	//Check penultimate (l is last line)
	cr_assert(eq(int, check_line("00000", "11111"), -1));
	cr_assert(eq(int, check_line("10000", "11111"), -1));
	cr_assert(eq(int, check_line("00001", "11111"), -1));
	cr_expect(eq(int, check_line("10001", "11111"), 0));
	cr_assert(eq(int, check_line("10001", " 11111"), -1));
	cr_assert(eq(int, check_line("10001", "1111 "), -1));
	cr_assert(eq(int, check_line("100001", "111"), -1));
	cr_expect(eq(int, check_line("101111", "111"), 0));
	cr_expect(eq(int, check_line("101", "1111"), 0));
	cr_expect(eq(int, check_line("11", "1111"), 0));
	cr_expect(eq(int, check_line("1111", "11"), 0));
	cr_expect(eq(int, check_line("1", "1111"), 0));
	cr_expect(eq(int, check_line("1111", "1"), 0));
	cr_assert(eq(int, check_line("1001", "    11 11"), -1));
	cr_assert(eq(int, check_line("1001", "111 11"), -1));
	cr_assert(eq(int, check_line("1001", "111 11    "), -1));
	cr_expect(eq(int, check_line("1001", "1111"), 0));
	cr_assert(eq(int, check_line("1111", "10001"), -1));
	cr_assert(eq(int, check_line("1000000 1", "111111111"), -1));
	cr_expect(eq(int, check_line("1001 1001", "111111111"), 0));
	cr_assert(eq(int, check_line("1001 1001", "111111"), -1));
	cr_assert(eq(int, check_line("10 11 1001", "1111111111"), -1));
	cr_expect(eq(int, check_line("1111 10001 1001", "     11111111111"), 0));
	cr_assert(eq(int, check_line("1111 10001 1001", "      1111111111"), -1));
	cr_assert(eq(int, check_line("1111 10001 1001", "11111111111    "), -1));
	cr_expect(eq(int, check_line("1111 10001 1001", "111111111111111"), 0));
	cr_expect(eq(int, check_line("1111 10001 1001", "1111 11111 1111"), 0));
	cr_assert(eq(int, check_line("1111 10001 1001", "11111111111111"), -1));
	cr_assert(eq(int, check_line("10000001100000001", "11111111111111"), -1));
	cr_expect(eq(int, check_line("10001101100101", "11111111111111"), 0));
	//Check middle line
	cr_assert(eq(int, check_line("00001", "10001"), -1));
	cr_assert(eq(int, check_line("10000", "10001"), -1));
	cr_assert(eq(int, check_line("10001", "00001"), -1));
	cr_assert(eq(int, check_line("10001", "10000"), -1));
	cr_assert(eq(int, check_line("00000", "10001"), -1));
	cr_assert(eq(int, check_line("10001", "00000"), -1));
	cr_assert(eq(int, check_line("00000", "00000"), -1));
	cr_assert(eq(int, check_line("11 01", "10001"), -1));
	cr_assert(eq(int, check_line("10001", "10 11"), -1));
	cr_assert(eq(int, check_line("1000 1", "10 01"), -1));
	cr_expect(eq(int, check_line("10001", "10001"), 0));
	cr_assert(eq(int, check_line("10001", "1001"), -1));
	cr_assert(eq(int, check_line("1001", "10001"), -1));
	cr_expect(eq(int, check_line("10111", "10001"), 0));
	cr_expect(eq(int, check_line("10001", "11101"), 0));
	cr_expect(eq(int, check_line("10111", "11101"), 0));
	cr_expect(eq(int, check_line("101 111", "111 101"), 0));
	cr_expect(eq(int, check_line("10000111 101", "10100111 101"), 0));
	cr_expect(eq(int, check_line("101 101", "101 101"), 0));
	cr_assert(eq(int, check_line("101", "101 101"), -1));
	cr_expect(eq(int, check_line("101 111", "111"), 0));
	cr_assert(eq(int, check_line("101 101", "101"), -1));
	cr_expect(eq(int, check_line("101 111", "101"), 0));
}

Test(map_parser, parsing)
{
	int	fd;

	map_parser(0);

	fd = open("maps/map0.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_expect(eq(int, map_parser(fd), 0));
	cr_assert(ne(int, close(fd), -1));

	/*
	fd = open("maps/map0_err.cub", O_RDONLY);
	cr_assert(ne(int, fd, -1));
	cr_assert(eq(int, map_parser(fd), -1));
	cr_assert(ne(int, close(fd), -1));
	*/
}
