SRCS := ft_atoi.c \
	   ft_isalnum.c \
	   ft_isdigit.c \
	   ft_memcmp.c \
	   ft_memset.c \
	   ft_strncmp.c \
	   ft_tolower.c \
	   ft_bzero.c \
	   ft_isalpha.c \
	   ft_isprint.c \
	   ft_memcpy.c \
	   ft_strchr.c \
	   ft_strchr_null.c \
	   ft_strlcpy.c \
	   ft_strnstr.c \
	   ft_toupper.c \
	   ft_calloc.c \
	   ft_isascii.c \
	   ft_memchr.c \
	   ft_memmove.c \
	   ft_strdup.c \
	   ft_strlen.c \
	   ft_null.c \
	   ft_strrchr.c \
	   ft_strlcat.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_check.c \
	   ft_putchar_fd.c \
	   ft_putstr_check.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstnew.c \
	   ft_lstadd_front.c \
	   ft_lstsize.c \
	   ft_lstlast.c \
	   ft_lstadd_back.c \
	   ft_garbage_back.c \
	   ft_lstdelone.c \
	   ft_lstclear.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_swap.c \
	   ft_aff_bin.c \
	   ft_strcmp.c \
	   ft_atoi_base.c \
	   ft_tools.c \
	   ft_putargs.c \
	   ft_printf.c \
	   ft_strstr.c\
	   get_next_line.c


SLEEP := 0.110
VPATH := srcs # search in dir name in VPATH variable
OBJSDIR := objs
OBJS := $(SRCS:%.c=$(OBJSDIR)/%.o)
DEPS := $(OBJS:%.o=%.d)



CC = clang
CFLAGS = -MMD -Wall -Werror -Wextra
CPPFLAGS = -I ./includes

NAME = libft.a

all: $(NAME)

$(OBJSDIR)/%.o: %.c
	mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	echo -n "\\r$(UNDERLINE)$<$(RESET)$(ALIGN)$(YLOWCOLR)>$(RESET)	$(BLUECOLR)[$(RESET)$(MGENCOLR)$@$(RESET)$(BLUECOLR)]$(RESET)" && sleep $(SLEEP)
	echo -n "$(CLEARLINE)"

$(NAME): $(OBJS)
	echo -n "\n\n$(GRENCOLR)============[ COMPILING OK ]=========$(RESET)" && sleep 1
	ar rcs $@ $^
	echo -n "\\r$(GRENCOLR)============[ LIBFT.A OK ]========$(RESET)\\n"

clean:
	rm -rf objs/
	echo -n "\\r$(REDCOLOR)============[ CLEAN OK ]============$(RESET)"

fclean:	clean
	rm -rf $(NAME)
	echo -n "\\r$(REDCOLOR)============[ FCLEAN OK ]============$(RESET)" && sleep 1
	echo -n "$(CLEARLINE)\\n"

re: fclean all

-include $(DEPS)

.PHONY:	re fclean clean all

UNDERLINE = \e[1;4m
REDCOLOR = \e[1;38;5;9m
GRENCOLR = \e[1;38;5;10m
YLOWCOLR = \e[1;38;5;11m
BLUECOLR = \e[1;38;5;12m
MGENCOLR = \e[1;38;5;13m
CLEARLINE = \e[2K
RESET = \e[0m
ALIGN = \e[30G

.SILENT:
