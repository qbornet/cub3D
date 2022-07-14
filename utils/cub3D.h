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
#define BUFFER_SIZE 10

/* parser.c */
// check if the extension is valid
int	valid_name(char *str);

/* ft_retputstr_int.c */
// print and return value
int	ft_retputstr_int(char *str, int fd, int exit_code);

/* ft_get_next_line.c */
// return next line for a given fd
char	*ft_get_next_line(int fd);

/* ft_get_next_line_utils.c */
// check valid fd and allocates buffer memory
char	*init_gnl(int file_des);

/* ft_free_str.c */
// free s and return NULL
char	*ft_retfree_str(char **s);

/* map_parser.c */
// Check for valid lign
int		check_line(char *lbefore, char *l);
// Check for valid map
int		map_parser(int fd);

#endif
