# Makefile
# main function is in file: cub3D.c

NAME := cub3D

# --- [FILE] ----

# File to create main
SRCS := cub3D.c \
		ft_retputstr_int.c

# File to create parser
PARSER := parser.c \
		  parser_colors.c \
		  opt_parser.c \
		  ft_parser_utils.c \
		  map_parser.c \
		  ft_free_str.c \
		  map_parser_utils.c \
		  ft_str_tools.c \
		  map_parser_res.c \
		  ft_free_iptr.c

# --- [COMPILE] ---

TEST := test.c
UTILS := $(UTILSDIR)$(addsufix .h, $(NAME))
DEFINE :=#-D MAIN=1

CC := clang
DFLAGS := -MMD -Wall -Werror -Wextra
CFLAGS :=  $(DFLAGS) $(DEFINE) -I ./utils -I ./test -I ./libft/includes -g3 -fsanitize=address
CPPFLAGS := -L ./libft
LDFLAGS := -lcriterion -lft

# --- [DIR] ---

OBJSDIR := objs/
SRCSDIR := srcs/
UTILSDIR := utils/
TESTDIR := test/

# --- [OBJECT] ---
OBJS := $(SRCS:%.c=$(OBJSDIR)%.o)
POBJS := $(PARSER:%.c=$(OBJSDIR)%.o)
TOBJS := $(TEST:%.c=$(OBJSDIR)%.o)
DEPS := $(OBJS:%.o=%.d)

# --- [RULES] ---
$(OBJSDIR)%.o: $(TESTDIR)%.c $(UTILS)
	make -C ./libft
	mkdir -p $(OBJSDIR) 2>&1 > /dev/null
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIR)%.o:	$(SRCSDIR)%.c $(UTILS)
	make -C ./libft
	mkdir -p $(OBJSDIR) 2>&1 > /dev/null
	$(CC) $(CFLAGS) -c $< -o $@

parser: $(OBJS) $(POBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ -lft

test.out: $(OBJS) $(TOBJS) $(POBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS)
	./test.out

testclean:
	rm -rf $(OBJSDIR)
	rm -rf test.out

retest: testclean test.out

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	make fclean -C ./libft
	rm -rf parser

re: fclean parser

-include $(DEPS)

.PHONY: retest testclean clean fclean re
