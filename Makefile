# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 12:09:34 by mghalmi           #+#    #+#              #
#    Updated: 2023/03/03 18:51:16 by mghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc

SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/ft_atoi.c\
	  libft/ft_atoi_base.c libft/ft_isprint.c   libft/ft_split.c     libft/ft_toupper.c\
	  ft_init.c	key.c ft_map_draw.c close_win.c ft_menu.c ft_matrix.c FDF.c

HEADER = FDF.h get_next_line/get_next_line.h libft/libft.h

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

%.o: %.c FDF.h
	$(CC) -fno-signed-zeros -mtune=intel -Ofast -march=native -fno-trapping-math -Wall -Wextra -Werror  -Imlx -c $< -o $@
	
clean :
	rm -rfv $(OBJ)
fclean : clean 
	rm -rfv $(NAME)

re : fclean all