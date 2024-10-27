# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjuncker <mjuncker@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 18:00:56 by mjuncker          #+#    #+#              #
#    Updated: 2024/10/27 16:12:07 by mjuncker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGG = -g3
CFLAGS = -Wall -Werror -Wextra
SRCS =  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	    ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_striteri.c
BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c


OBJ = $(SRCS:.c=.o)
BOBJ = $(BSRCS:.c=.o)
NAME = libft.a

.PHONY: all
all : $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

.PHONY: bonus
bonus: fclean $(OBJ) $(BOBJ)
	ar rcs $(NAME) $(OBJ) $(BOBJ)

.PHONY: clean
clean:
	rm -f $(OBJ) $(BOBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: debug
debug: clean
	$(CC) $(CFLAGG) $(SRCS) main.c -o a.out
	./a.out

.PHONY: bdebug
bdebug: clean
	$(CC) $(CFLAGG) $(SRCS) $(BSRCS) main.c -o a.out


