# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 15:49:09 by amdemuyn          #+#    #+#              #
#    Updated: 2023/04/25 16:12:09 by amdemuyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iheaders 

SRC = main.c \
	  maps.c \
	  errors.c \
	  graphs.c \
	  itinerary.c \
	  move.c \
	  get_next_line.c \
	  get_next_line_utils.c \

LIBRARY = -lmlx -framework OpenGL -framework appKit

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${SRC} ${LIBRARY} -o ${NAME}

clean: 
	rm -rf ${OBJ}

fclean:
	rm -rf ${NAME}
	rm -rf ${OBJ}

re: fclean all

.PHONY: all clean fclean re

