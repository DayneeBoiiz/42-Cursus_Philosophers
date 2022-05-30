# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 21:13:12 by sayar             #+#    #+#              #
#    Updated: 2022/05/15 18:41:02 by sayar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

FLAGS = -Wall -Werror -Wextra

SRC =	checker.c\
		ft_atoi.c\
		ft_time.c\
		linked_list.c\
		philo.c\
		philo_logic.c\
		profile_utils.c\

OBJ = ${patsubst %.c, %.o, ${SRC}}


all : ${NAME}

.PHOMY : all clean fclean re

${NAME} : ${OBJ} philo.h
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all