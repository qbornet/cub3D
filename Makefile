# Makefile
# main function is in file: cub3D.c

NAME := cub3D

SRCS := parser.c \
		ft_retputstr_int.c \
		ft_free_str.c \
		ft_get_next_line.c \
		ft_get_next_line_utils.c \
		map_parser.c \
		map_parser_utils.c \
		ft_str_tools.c \
		cub3D.c

TEST := test.c
UTILS := $(UTILSDIR)$(addsufix .h, $(NAME))
DEFINE=-D MAIN=1

CC := clang
CFLAGS := -MMD -Wall -Werror -Wextra $(DEFINE) -I ./utils -I ./test -I ./libft/includes -fsanitize=address -g3
CPPFLAGS := -L ./libft
LDFLAGS := -lcriterion -lft

OBJSDIR := objs/
SRCSDIR := srcs/
UTILSDIR := utils/
TESTDIR := test/

OBJS := $(SRCS:%.c=$(OBJSDIR)%.o)
TOBJS := $(TEST:%.c=$(OBJSDIR)%.o)
DEPS := $(OBJS:%.o=%.d)

$(OBJSDIR)%.o: $(TESTDIR)%.c $(UTILS)
	make -C ./libft
	mkdir -p $(OBJSDIR) 2>&1 > /dev/null
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIR)%.o:	$(SRCSDIR)%.c $(UTILS)
	make -C ./libft
	mkdir -p $(OBJSDIR) 2>&1 > /dev/null
	$(CC) $(CFLAGS) -c $< -o $@

parser: $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ -lft

test.out: $(OBJS) $(TOBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS) -g3
	./test.out

testclean:
	rm -rf $(OBJSDIR)
	rm -rf test.out

retest: testclean test.out

-include $(DEPS)

.PHONY: retest testclean
