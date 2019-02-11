# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaoliiny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/27 19:37:45 by kaoliiny          #+#    #+#              #
#    Updated: 2018/10/27 21:16:44 by kaoliiny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRC = ft_strcmp.c ft_toupper.c ft_strcpy.c	ft_strdup.c ft_atoi.c	ft_strlen.c	ft_isalnum.c ft_strncat.c ft_isalpha.c ft_strncmp.c	ft_isascii.c ft_strncpy.c	ft_isdigit.c	ft_strnstr.c	ft_isprint.c ft_strrchr.c ft_strcat.c ft_strstr.c ft_strchr.c	ft_tolower.c	ft_memmove.c	ft_memcpy.c	ft_memccpy.c	ft_memcmp.c	ft_memset.c	ft_bzero.c	ft_memchr.c	ft_strlcat.c	ft_putstr_fd.c	ft_putchar_fd.c	ft_putendl_fd.c	ft_putendl.c	ft_putnbr_fd.c	ft_putnbr.c	ft_putstr.c	ft_putchar.c	ft_memalloc.c	ft_memdel.c	ft_strnew.c	ft_strdel.c	ft_strclr.c	ft_striter.c	ft_striteri.c	ft_strmap.c	ft_strmapi.c	ft_strequ.c	ft_strnequ.c	ft_strsub.c	ft_strsplit.c	ft_strjoin.c	ft_lstnew.c	ft_lstdelone.c	ft_randint.c	ft_lstadd.c	ft_lstiter.c	ft_strtrim.c	ft_lstdel.c	ft_itoa.c	ft_lstmap.c
INC = includes
LIBS = ft_strcmp.o	ft_toupper.o	ft_strcpy.o	ft_strdup.o	ft_atoi.o	ft_strlen.o	ft_isalnum.o	ft_strncat.o  ft_isalpha.o	ft_strncmp.o	ft_isascii.o	ft_strncpy.o ft_isdigit.o	ft_strnstr.o	ft_isprint.o	ft_strrchr.o ft_strcat.o	ft_strstr.o	ft_strchr.o	ft_tolower.o	ft_memchr.o	ft_memmove.o	ft_memcpy.o	ft_memccpy.o	ft_memcmp.o	ft_memset.o	ft_bzero.o	ft_strlcat.o	ft_putstr_fd.o	ft_putchar_fd.o	ft_putendl_fd.o	ft_putendl.o	ft_putnbr_fd.o	ft_putnbr.o	ft_putstr.o	ft_putchar.o	ft_memalloc.o	ft_memdel.o	ft_strnew.o	ft_strclr.o	ft_strdel.o	ft_striter.o	ft_striteri.o	ft_strmap.o	ft_strmapi.o	ft_strequ.o	ft_strnequ.o	ft_strsub.o	ft_strsplit.o	ft_strjoin.o	ft_lstnew.o	ft_lstdelone.o	ft_randint.o	ft_lstadd.o	ft_lstiter.o	ft_strtrim.o	ft_lstdel.o	ft_itoa.o	ft_lstmap.o

all: $(NAME)
$(NAME):
	gcc -c $(SRC) -I$(INC) $(CFLAGS)
	ar rc libft.a $(LIBS)
	ranlib libft.a

clean:
	/bin/rm -f $(LIBS)
fclean: clean
	/bin/rm -f libft.a
re: fclean all
