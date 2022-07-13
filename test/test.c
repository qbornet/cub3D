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
