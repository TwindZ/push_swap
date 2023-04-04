# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 10:27:08 by emlamoth          #+#    #+#              #
#    Updated: 2023/04/04 16:16:57 by emlamoth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	pushswap.c \
		pushswap_util.c \

LIBFT_DIR = ./srcs/libft/
LIBF = ./srcs/libft/libft.a
SRCS_DIR = ./srcs/
OBJS_DIR = ./objs/
OBJS = $(SRCS:%.c=%.o)
OBJS := $(OBJS:$(SCRS_DIR)%=$(OBJS_DIR)%)

NAME = pushswap

CFLAGS = -Wall -Wextra -Werror

CC = gcc

GREEN = \033[1;32m
RED = \033[1;31m
NC = \033[0;0m

all: $(NAME)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<
	
$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "${GREEN}COMPILED PUSHSWAP${NC}"

clean:
	@$(MAKE) clean -C ./srcs/libft
	@rm -rf $(OBJS_DIR)
	@echo "${RED}PUSHSWAP OBJECTS DELETED${NC}"

fclean: clean
	@$(MAKE) fclean -C ./srcs/libft
	@rm -f $(NAME)
	@echo "${RED}PUSHSWAP DELETED${NC}"


bonus: all

re: fclean all

.PHONY: all clean fclean bonus re