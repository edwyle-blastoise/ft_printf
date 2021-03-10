# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eblastoi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 15:02:16 by eblastoi          #+#    #+#              #
#    Updated: 2020/11/27 20:36:03 by eblastoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c ft_print_char.c ft_print_string.c ft_printf_parse.c check_types.c ft_print_pdiux.c ft_isdigit.c ft_putchar.c ft_strchr.c ft_strlen.c ft_putstr.c ft_strlcpy.c ft_itoa.c ft_strdup.c ft_strcmp.c ft_unsigned_itoa.c ft_itoa_hex.c

HEADERS		= ft_printf.h

OBJS	= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc

AR			= ar rc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

%.o:		%.c ${HEADERS}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}
			${RM} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re