#ifndef CUB3D_H
# define CUB3D_H
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <stdio.h>

enum e_colors_pos
{
	E_FLOOR,
	E_CELLING,
	E_MAX_COLORS
};

enum e_texture_pos
{
	E_NORTH,
	E_SOUTH,
	E_WEST,
	E_EAST,
	E_MAX_TEXTURE
};

typedef struct s_data
{
	int		**colors;
	char	**texture;
}	t_data;

/* parser.c */
// check if the extension is valid
int		valid_name(char *str);

// return (char **)tab with texture path inside
char	**get_texture(char *filename);

/* ft_parser_utils.c */
// return 1 if path is normally formated else 0
int		ft_isvalid_path(char c, char next);

// return 1 if whitespace else return 0
int		ft_isspace(char c);

// check if you didn't get symlink of /dev/random
int		ft_valid_file(char *filename);

/* opt_parser.c */
// optimization for norm of colors_atoi fucntion
int	opt_colorsatoi(char *str, int *i);

// optimization for norm of select_direction function
void	opt_setdirection(char **t_curr, int direction);

/* parser_colors.c */
// return tab with rgb colors of celling and floor
int		**get_colors(char *filename);


/* ft_retputstr_int.c */
// print and return value
int		ft_retputstr_int(char *str, int fd, int exit_code);

/* ft_free_ret_iptr.c */
// free a (int *) and return NULL
int		*ft_free_ret_iptr(int *tab);

#endif
