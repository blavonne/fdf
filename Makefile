# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 20:05:11 by blavonne          #+#    #+#              #
#    Updated: 2019/11/28 19:06:19 by blavonne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = ./srcs/main.c ./srcs/read.c ./srcs/fdf_init.c ./srcs/draw.c\
	./srcs/checks.c ./srcs/bresenham.c ./srcs/quaterni.c ./srcs/mouse.c\
	./srcs/keymlx.c ./srcs/cntrl.c ./srcs/dimens.c ./srcs/menu.c ./srcs/keys.c\
	./srcs/caminit.c
OBJ = $(SRC:%.c=%.o)

INCLUDES = ./includes
LFT_DIR = ./libft
MLX_DIR = ./minilibx

FLAGS = -Wall -Werror -Wextra -I $(INCLUDES) -I $(MLX_DIR) -I $(LFT_DIR)
LFLAGS = -L $(LFT_DIR) -lft
MFLAGS = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a
MLX = ./minilibx/libmlx.a

all: $(SRC) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	gcc $(OBJ) -o $(NAME) $(FLAGS) $(LFLAGS) $(MFLAGS)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re