# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 12:09:34 by mghalmi           #+#    #+#              #
#    Updated: 2023/02/14 12:34:16 by mghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FDF

SRCS = get_next_line/*.c libft/*.c

SRCB = 

HEADER = FDF.h get_next_line/*.h libft/*.h

OBJ = ${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	gcc -Wall -Wextra -Werror FDF.c $(OBj) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
clean :
	rm -rfv $(OBJ)
fclean : clean 
	rm -rfv $(NAME)

re : fclean all