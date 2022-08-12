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
# include <math.h>
# define BUFFER_SIZE 10
# define M_KEY 109
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define ESC_KEY 65307
# define ON_KEYDOWN 2
# define ON_RELEASE 3
# define ON_MOUSEMOVE 6
# define ON_DESTROY 17
# define WIDTH 800
# define HEIGHT 600
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

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

/* Tout les vecteur fonctionne comme ca, x de droite (0 >) a gauche(0 <),
 * y de bas(0 >) en haut (< 0).*/

typedef struct s_ray
{
	int		mapx; // vecteur du joueur x en int
	int		mapy; // vecteur du joueur y en int
	int		stepx; // increntation donne la direction dans la quelle on va -1 ou 1 pour x
	int		stepy; // increntation donne la direction dans la quelle on va -1 ou 1 pour y
	int		lineheight; // la taille de la ligne a dessigner
	int		drawstart; // la position de depart pour dessigner la ligne
	int		drawend; // la position de fin pour dessigner la ligne
	int		x; // le ray
	int		hit; // si le ray a hit ou non
	int		side; // pour differencier qu'elle coter c'est stoper sur le mur sidedistx/sidedisty
	double	posx; // vecteur du joueur x
	double	posy; // vecteur du joueur y
	double	dirx; // vecteur de direction du joueur x
	double	diry; // vecteur de direction du joueur y
	double	planex; // vecteur du plan donne le FoV (Field Of View) x
	double	planey; // vecteur du plan donne le FoV (Field Of View) y
	double	camerax;  // donne la cordonner x de l'ecran (gauche = -1 millieux = 0 droite = 1)
	double	raydirx; // calcul de la direction x du rayon
	double	raydiry; // calcul de la direction y du rayon
	double	sidedistx; // la distance que le rayon a parcourue depuis la position du debut sur l'axe x
	double	sidedisty; // la distance que le rayon a parcourue depuis la position du debut sur l'axe y
	double	dx; // delta de x la difference entre x et x1
	double	dy; // delta de y la difference entre y et y1
	double	perpwall; // distance du mur
	double	movespeed; // vitesse de deplacement
	double	rotspeed; // vitesse de rotation
}	t_ray;

typedef struct s_tex
{
	int				texdir; // direction NO S EA WE de la texture
	int				texx; // position x de la texture
	int				texy; // position y de la texture
	double			wallx; // side == 1 position x  side == 0 position y ou le mur a etait toucher
	double			step; // incrementation par pixel
	double			texpos; // position de la texture
}	t_tex;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		forward;
	int		backward;
	int		left;
	int		right;
	int		fcolors;
	int		ccolors;
	int		**colors;
	char	**texture;
	char	**map;
	size_t	max_x;
	t_ray	ray;
	int		mouse_mode;
	int		prev;
	t_tex	tex;
	t_img	data[E_MAX_TEXTURE]; // les textures
	t_img	buffer; // l'image qui permet d'afficher le resultat
}	t_data;

/* start_dda.c */
// start dda algo which is basically the start of raycasting
void	start_dda(t_data **d_curr, t_ray *ray);

/* buffer.c */
// destroy buffer image
int		destroy_buffer(t_data **d_curr);

// put buffer to window
int		put_buffer(t_data **d_curr);

// create buffer image this will have texture and result of raycast
int		create_buffer(t_data **d_curr);

/* ft_pixel_put.c */
// my own pixel put (faster compared to the one made for mlx)
void	ft_pixel_put(t_img *data, int x, int y, int colors);

/* hook.c */
// hook for mlx, when key is pressed
int		move_down(int keycode, t_data **d_curr);

// hook for mlx, when key is up
int		move_release(int keycode, t_data **d_curr);

// hook for mlx, when mouse moving
int	mouse_move(int x, int y, t_data **d_curr);

/* crl_move.c */
// circule moves left
void	move_crl_l(t_data **d_curr);

// circule moves right
void	move_crl_r(t_data **d_curr);

// backward circule moves left
void	move_bcrl_l(t_data **d_curr);

// backward circule moves right
void	move_bcrl_r(t_data **d_curr);

/* ft_moves.c */
// move dir == 0 forward, dir == 1 backward
void	move(int dir, char **map, t_ray *ray);
// rotate dir == 0 left, dir == 1 right
void	rotate(int dir, t_ray *ray);
// check if we needed to moves 
void	ft_moves(t_data **d_curr);

/* shot_ray.c */
// start raycasting
int		shot_ray(t_data **d_curr);

/* ft_conv.c */
// take a radian as input and return it to degree format
double	ft_rad2deg(double radians);

// take a degree as input and return it to radian format
double	ft_deg2rad(double degree);

/* start_dda.c */
// set starting value needed for dda algo plus other value needed for raycasting
int		setup_dda(t_data **d_curr);

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
// check for atoi if to many numbers are input or not enought input 1 reset to 0 the static
int		ft_check_numconv(int input);

// optimization for norm of colors_atoi fucntion
int		opt_colorsatoi(char *str, int *i);
void	opt_check_commas(char *str, int *i, int *count);

// optimization for norm of select_direction function
void	opt_setdirection(char **t_curr, int direction);


/* parser_colors.c */
// return tab with rgb colors of celling and floor
int		**get_colors(char *filename);


/* ft_retputstr_int.c */
// print and return value
int		ft_retputstr_int(char *str, int fd, int exit_code);

/* ft_free_iptr.c */
// free a (int *) and return NULL
int		*ft_retfree_iptr(int *tab);

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
// return -1 free everything and read all the file until the end (leaks on gnl if not)
int		ft_clear_map_parser(int fd, char ***res);

// Add valid line to res
void	update_res_tab(char ***res, const char *s);

/* destroy_mlx.c */
// use function to free and destroy win in mlx
int		destroy_mlx(t_data **d_curr);

/* cub3D.c */
// free frame and exit(0)
int		free_all(t_data **d_curr);

/* ft_moves_mouse.c */
void	ft_moves_mouse(t_data **d_curr, int x);

#endif
