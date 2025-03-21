# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brogalsk <brogalsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 09:22:19 by brogalsk          #+#    #+#              #
#    Updated: 2025/03/18 14:58:21 by brogalsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	cc

CFLAGS	=	-g -Wall -Wextra -Werror

SRCS	=	init.c \
				main.c \
				monitor.c \
				routine.c \
				thread.c \
				utils.c
				
OBJS	=	${SRCS:.c=.o}


all:		${NAME}

${NAME}:	${OBJS} 
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
			rm -f ${OBJS}
fclean:		clean
			rm -f ${NAME}

re:				fclean all

.PHONY:		all clean fclean re
