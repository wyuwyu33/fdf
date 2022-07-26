# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 03:03:56 by wyu               #+#    #+#              #
#    Updated: 2022/07/26 21:52:34 by wyu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Werror -Wextra

LIBRARIES	= -L$(LIBFT_DIR) -L$(MIX_DIR) -lmlx -lft -lm -framework OpenGL -framework Appkit
INCLUDES	= -I$(FDF_HEADERS) -I$(LIBFT_HEADERS) -I$(MIX_HEADERS)

LIBFT			= $(LIBFT_DIR)libft.a
LIBFT_DIR		= ./libft
LIBFT_HEADERS	= $(LIBFT_DIR)

MIX			= $(MIX_DIR)libmlx.a
MIX_DIR		= ./minilibx_macos/
MIX_HEADERS	= $(MIX_DIR)

HEADERS			= $(addprefix $(HEADER_DIR), $(HEADER_LIST))
HEADER_DIR		= ./inc/
HEADER_LIST		=

SRCS			= $(addprefix $(SRC_DIR), $(SRC_LIST))
SRC_DIR			= ./src/
SRC_LIST		= main.c
SRCS			= $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJS			= $(addprefix $(OBJ_DIR), $(OBJ_LIST))
OBJ_DIR			= ./obj/
OBJ_LIST		= $(patsubst %.c, %.o, $(SRC_LIST))
OBJS			= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

all: $(NAME)

$(NAME): $(LIBFT) $(MIX) $(OBJS)
	$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJS) -o $(NAME)

$(LIBFT):
	make -sC $(LIBFT_DIR)

$(MIX):
	make -sC $(MIX_DIR)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(INCLUDES) $<
	mv $(OBJ_LIST) $(OBJ_DIR)

clean:
	make -sC $(LIBFT_DIR) clean
	make -sC $(MIX_DIR) clean
	rm -rf $(OBJS)

fclean:	clean
	rm -f $(LIBFT)
	rm -f $(MIX)
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re