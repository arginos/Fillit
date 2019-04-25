# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbhuiyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 15:56:53 by hbhuiyan          #+#    #+#              #
#    Updated: 2019/01/04 16:25:11 by asimonia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	utility.c \
		main.c \
		read_in.c \
		fil_err.c \
		fil_bord.c \

OBJ = 	*.o

INC = 	fillit.h

NAME = 	fillit

$(NAME) : 
		make -C libft/ fclean && make -C libft/
		gcc -Wall -Wextra -Werror -I libft/includes $(SRC) -o $(NAME) -I libft/libft.h -L libft/ -lft

all : $(NAME)

clean :
		rm -r -f $(OBJ)
		find . -type f -name '*.o' -delete
		rm -r -f libft/libft.h.gch

fclean : clean
		rm -f ./libft/libft.a
		rm -f $(NAME)
re :
		make fclean
		make all

