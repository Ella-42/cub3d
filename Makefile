# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 10:59:31 by qraymaek          #+#    #+#              #
#    Updated: 2024/03/27 20:21:06 by qraymaek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
INCLUDES = include
SRCS_DIR = .
OBJS_DIR = objs
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
LIBFT = libft
MLX = mlx_macos

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SOURCES = cub3d.c exit/error.c exit/events.c parser/map_checker.c minimap/drawer.c

SRCS = $(addprefix $(SRCS_DIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJS_DIR)/,$(SOURCES:.c=.o))

all: lib tmp $(NAME)

lib:
	@echo "$(GREEN)Creating lib files$(BLUE)"
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -L $(LIBFT) -o $@ $^ $(MLX)/libmlx.a -lft -L /opt/X11/lib -l Xext -l X11 -framework OpenGL -framework AppKit
	@echo "$(GREEN)Project successfully compiled"

tmp:
	@mkdir -p objs
	@mkdir -p objs/parser
	@mkdir -p objs/exit
	@mkdir -p objs/minimap

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(WHITE)"

clean:
	@echo "$(RED)Deleting library files$(BLUE)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJS_DIR)

fclean:
	@echo "$(RED)Deleting library files and .a$(BLUE)"
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(RED)All the files are now cleaned with fclean"

re: fclean
	@$(MAKE) all -j

.PHONY: tmp, re, fclean, clean
