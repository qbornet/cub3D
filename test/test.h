#ifndef TEST_H
# define TEST_H
# define CRITERION_VERBOSITY_LEVEL 1
# define TEXUTRE_NORTH "A/PATH_TO_FILE"
# define TEXUTRE_SOUTH "A/PATH_TO_FILE"
# define TEXUTRE_WEST "A/PATH_TO_FILE"
# define TEXUTRE_EAST "A/PATH_TO_FILE"
# include <cub3D.h>
# include <criterion/criterion.h>
# include <criterion/new/assert.h>

TestSuite(get_texture, .description = "This should return texture path");
TestSuite(valid_name, .description = "This should return a valid map");
TestSuite(map_parser, .description = "This should parse a map");
TestSuite(check_line, .description = "This should parse lines");
TestSuite(nrm_line, .description = "This should check if non-valid char or empty line inside a line");
TestSuite(ft_rmv_trailing_chr, .description = "This should removes trailing char if it exists");

#endif
