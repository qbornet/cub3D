# Makefile
# main function is in file: cub3D.c

NAME := cub3D

# --- [FILE] ----

# File to create main
SRCS := cub3D.c \
		start_window.c \
		destroy_mlx.c \
		ft_retputstr_int.c

# File to create parser
PARSER := parser.c \
		  opt_parser.c \
		  map_parser.c \
		  parser_colors.c \
		  map_parser_res.c \
		  map_parser_utils.c \
		  ft_free_str.c \
		  ft_str_tools.c \
		  ft_parser_utils.c \
		  ft_free_iptr.c

# File to create raycast
RAYCAST := ft_conv.c\
		   ft_moves.c \
		   side_move.c \
		   move_fb.c \
		   ft_moves_mouse.c \
		   ft_pixel_put.c \
		   hook.c \
		   shot_ray.c \
		   crl_move.c \
		   buffer.c \
		   setup_dda.c \
		   start_dda.c

# --- [COMPILE] ---

UTILS := $(UTILSDIR)$(addsufix .h, $(NAME))

CC := clang
DFLAGS := -MMD -Wall -Werror -Wextra
CFLAGS :=  $(DFLAGS) -I ./mlx_linux -I ./utils -I ./test -I ./libft/includes
CPPFLAGS := -L ./mlx_linux -L ./libft
LDFLAGS := -lft -lmlx_Linux -lXext -lX11 -lm

# --- [DIR] ---

OBJSDIR := objs/
SRCSDIR := srcs/
UTILSDIR := utils/

# --- [OBJECT] ---

OBJS := $(SRCS:%.c=$(OBJSDIR)%.o)
POBJS := $(PARSER:%.c=$(OBJSDIR)%.o)
ROBJS := $(RAYCAST:%.c=$(OBJSDIR)%.o)
DEPS := $(OBJS:%.o=%.d)

# --- [RULES] ---

$(OBJSDIR)%.o:	$(SRCSDIR)%.c $(UTILS)
	make -C ./libft
	make -C ./mlx_linux
	mkdir -p $(OBJSDIR) 2>&1 > /dev/null
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(POBJS) $(ROBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS)

bonus: $(NAME)

all: $(NAME)

clean:
	make clean -C ./mlx_linux
	rm -rf $(OBJSDIR)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean $(NAME)

-include $(DEPS)

.PHONY: all clean fclean re
