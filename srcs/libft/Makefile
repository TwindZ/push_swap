NAME = libft.a

SRC =	ft_isalnum.c	\
		ft_isdigit.c	\
		ft_memcmp.c		\
		ft_memset.c		\
		ft_strlcpy.c	\
		ft_strnstr.c	\
		ft_toupper.c	\
		ft_atoi.c		\
		ft_isalpha.c	\
		ft_isprint.c	\
		ft_memcpy.c		\
		ft_strchr.c		\
		ft_strlen.c		\
		ft_strrchr.c	\
		ft_bzero.c		\
		ft_isascii.c	\
		ft_memchr.c		\
		ft_memmove.c	\
		ft_strlcat.c	\
		ft_strncmp.c	\
		ft_tolower.c	\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_itoa.c		\
		ft_strtrim.c	\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_split.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		get_next_line.c	\
		ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\
		ft_printf.c			\
		ft_putchar.c		\
		ft_putstr.c			\
		ft_putnbr.c			\
		ft_putnbr_un.c		\
		ft_putnbr_hex.c		\
		ft_freeall.c		\
		
OBJS_DIR = libft_objs/
OBJS = $(SRC:%.c=%.o)
OBJS := $(OBJS:%=$(OBJS_DIR)%)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

GREEN = \033[1;32m
RED = \033[1;31m
NC = \033[0;0m

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@echo "${GREEN}LIBFT COMPILED${NC}"

$(OBJS_DIR)%.o:%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJS_DIR)
	@echo "${RED}LIBFT OBJECTS DELETED${NC}"

fclean: clean
	@rm -f $(NAME)
	@echo "${RED}LIBFT DELETED${NC}"

re: fclean all

.PHONY: all clean fclean bonus re