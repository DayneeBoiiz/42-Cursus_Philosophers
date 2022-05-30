# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 18:41:22 by sayar             #+#    #+#              #
#    Updated: 2022/05/16 16:52:02 by sayar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc

FLAGS = -Wall -Werror -Wextra

SRC =	free_lst_bonus.c\
		ft_atoi_bonus.c\
		ft_checker_bonus.c\
		ft_logic_bonus.c\
		ft_time_bonus.c\
		linked_list_bonus.c\
		philo_bonus.c\
		profile_utils_bonus.c\

OBJ = ${patsubst %.c, %.o, ${SRC}}


all : ${NAME}

.PHOMY : all clean fclean re

${NAME} : ${OBJ} philo_bonus.h
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all