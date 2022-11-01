# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niclaw <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 13:59:17 by niclaw            #+#    #+#              #
#    Updated: 2022/10/28 21:23:52 by niclaw           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCLIST	=   playground.c get_next_line.c get_next_line_utils.c  
SRCDIR	= 
BUILD =	./build/
OBJS	=	${SRCS:%.c=%.o}
BONUS_OBJS = ${BONUS_SRC:.c=.o}
INCH	= get_next_line.h 
INCHB	= 

BONUS_SRC	=  
SRCS	= ${addprefix ${SRCDIR}, ${SRCLIST}}

CC	= gcc

CFLAGS	= -g -Wall -Wextra -Werror -D BUFFER_SIZE=4

RM	= rm -f

NAME	= get.a

%.o:	%.c ${INCH} 
	@mkdir -p ${BUILD}
	${CC} ${CFLAGS} -include ${INCH} -c $< -o ${addprefix ${BUILD}, ${<:.c=.o}}

%bonus.o:	%bonus.c ${INCHB}
	${CC} ${CFLAGS} -include ${INCHB} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} 
	ar -crs ${NAME} ${addprefix ${BUILD}, ${OBJS}}
	@echo "Linking Done!" 

all:	${NAME}

clean:
	${RM} -r ${BUILD}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re  

bonus: all

test: all	
	${CC} ${CFLAGS} ${INCH} playground.c ${NAME} -o playground
	./playground

mem: 
	${CC} -g -Wall -Wextra -include ${INCH} playground.c ${NAME} -o playground
	valgrind -v --leak-check=full ./playground
