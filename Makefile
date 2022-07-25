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

# File to create 2D raycast
RAYCAST := print2d_map.c \
		   ft_conv.c

# --- [COMPILE] ---

TEST := test.c
UTILS := $(UTILSDIR)$(addsufix .h, $(NAME))
DEFINE :=#-D MAIN=1

CC := clang
DFLAGS := -MMD -Wall -Werror -Wextra
CFLAGS :=  $(DFLAGS) $(DEFINE) -I ./mlx_linux -I ./utils -I ./test -I ./libft/includes -g3 -fsanitize=address
CPPFLAGS := -L ./mlx_linux -L ./libft
LDFLAGS := -lcriterion -lft -lmlx_linux -lXext -lX11

# --- [DIR] ---

OBJSDIR := objs/
SRCSDIR := srcs/
UTILSDIR := utils/
TESTDIR := test/

# --- [OBJECT] ---
OBJS := $(SRCS:%.c=$(OBJSDIR)%.o)
POBJS := $(PARSER:%.c=$(OBJSDIR)%.o)
TOBJS := $(TEST:%.c=$(OBJSDIR)%.o)
ROBJS := $(RAYCAST:%.c=$(OBJSDIR)%.o)
DEPS := $(OBJS:%.o=%.d)

# --- [RULES] ---
$(OBJSDIR)%.o: $(TESTDIR)%.c $(UTILS)
	make -C ./libft
	make -C ./mlx_linux
	mkdir -p $(OBJSDIR) 2>&1 > /dev/null
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIR)%.o:	$(SRCSDIR)%.c $(UTILS)
	make -C ./libft
	make -C ./mlx_linux
	mkdir -p $(OBJSDIR) 2>&1 > /dev/null
	$(CC) $(CFLAGS) -c $< -o $@

parser: $(OBJS) $(POBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ -lft -lmlx_linux -lXext -lX11

raycast: $(OBJS) $(POBJS) $(ROBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ -lft -lmlx_linux -lXext -lX11

test.out: $(OBJS) $(TOBJS) $(POBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS)
	./test.out

testclean:
	rm -rf $(OBJSDIR)
	rm -rf test.out

retest: testclean test.out

clean:
	make clean -C ./mlx_linux
	rm -rf $(OBJSDIR)

fclean: clean
	make fclean -C ./libft
	rm -rf parser

re: fclean parser

-include $(DEPS)

.PHONY: retest testclean clean fclean re
