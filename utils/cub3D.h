#ifndef CUB3D_H
# define CUB3D_H
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <stdio.h>

/* parser.c */
// check if the extension is valid
int	valid_name(char *str);

/* ft_retputstr_int.c */
// print and return value
int	ft_retputstr_int(char *str, int fd, int exit_code);

#endif
