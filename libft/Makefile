# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 17:41:03 by hrischma          #+#    #+#              #
#    Updated: 2024/10/16 16:28:21 by hrischma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strcmp.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c  

ADDITIONAL = ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_striteri.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

PRINTF = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_u.c ft_puthex.c ft_puthex_upper.c ft_putptr.c ft_printf.c

GNL = get_next_line.c


SRC = ${LIBC} ${ADDITIONAL}
SRCALL = ${LIBC} ${ADDITIONAL} ${BONUS} ${PRINTF} ${GNL}
OBJ = ${SRC:.c=.o}
OBJALL = ${SRCALL:.c=.o}
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		cc ${CFLAGS} -c $< -o $@

${NAME}: ${OBJALL}
		ar -rcs ${NAME} ${OBJALL}

all: ${NAME}

clean:	
		rm -rf ${OBJALL}

fclean:	clean
		rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
