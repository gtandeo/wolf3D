# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/30 11:08:47 by gtandeo           #+#    #+#              #
#    Updated: 2015/06/01 13:16:10 by gtandeo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft.a

LIBDIR = ./libft

NAME = wolf3d

SRC = wolf.c \
		ray_calc.c\
		deplacements.c \
		wall_define.c \
		display.c \
		struct_init.c

SRCO = $(SRC:.c=.o)

CFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror

all: $(LIB) $(NAME)

$(LIB):
		@make -C $(LIBDIR) fclean
		@make -C mlx
		@make -C $(LIBDIR)

$(NAME): $(LIB) $(SRC)
		@cc -o $(NAME) $(SRC) $(CFLAGS) -L $(LIBDIR) -lft
		@echo "\033[33m"wolf3d Compiled ! "\033[32m"Success

clean:
		@rm -f $(SRCO)
		@make fclean -C $(LIBDIR)

fclean: clean
		@rm -f $(NAME)

re: fclean all
