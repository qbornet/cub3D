#ifndef CUB3D_H
# define CUB3D_H
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# define BUFFER_SIZE 10
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define ON_DESTROY 17
# define WIDTH 1024
# define HEIGHT 960

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
	void	*mlx;
	void	*win;
	int		**colors;
	char	**texture;
	char	**map;
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

/* start_window.c */
// create a window 
int		start_window(t_data **d_curr);

/* opt_parser.c */
// optimization for norm of colors_atoi fucntion
int		opt_colorsatoi(char *str, int *i);

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

/* ft_free_str.c */
// Free s and return NULL
char	*ft_retfree_str(char **s);

// Free tab of string and return NULL
char	*ft_retfree_tab(char ***tab, size_t len);

/* map_parser.c */
// Return 0 if the map is valid or -1 if the map is not valid; The map is saved inside res if valid.
int		map_parser(int fd, char ***res);

// Current line check; if correct get_next_line else return -1
int		set_line(char **l, char **l_bef, int *pos, int fd);

// Check valid char in line && rm trailing \n from gnl
char	*nrm_line(const char *s, int *pos);

/* map_parser_utils.c */
// Check for valid line
int		check_line(char *lbefore, char *l);

// Return 1 if c is S, N, E, W
int		ft_is_sta_pos(char c);

/* ft_str_tools.c */
// Removes trailing c char
char	*ft_rmt_chr(const char *s, char c);

// Cpy len elts from tab to res
int		ft_cpy_tab(const char **tab, char **res, size_t len);

// Return tab len /!\ Do not use if no NULL inside tab /!\.
size_t	ft_len_tab(const char **tab);

// Allocate a new tab, if s is not NULL place it at index 0 of the tab and NULL at index 1
char	**ft_new_tab(const char *s);

// Return a tab of string updated with s at the end
char	**ft_add_str(const char **tab, const char *s);

/* map_parser_res.c */
// Init res and return 0 else return -1
char	**init_res(int fd, char **l, char **l_bef, int *pos);

// Add valid line to res
void	update_res_tab(char ***res, const char *s);

/* destroy_mlx.c */
// use function to free and destroy win in mlx
int		destroy_mlx(t_data **d_curr);
/* cub3D.c */
// free frame and exit(0)
int	free_all(t_data **d_curr);

#endif
