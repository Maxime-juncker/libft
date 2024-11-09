# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 18:00:56 by mjuncker          #+#    #+#              #
#    Updated: 2024/11/09 14:44:57 by mjuncker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGG = -g3
CFLAGS = -Wall -Werror -Wextra
SRCS =  ft_isalpha.c 			\
		ft_isdigit.c 			\
		ft_isalnum.c 			\
		ft_isascii.c 			\
		ft_isprint.c 			\
		ft_strlen.c 			\
		ft_memset.c 			\
		ft_bzero.c 				\
		ft_memcpy.c				\
		ft_memmove.c 			\
		ft_strlcpy.c 			\
		ft_strlcat.c 			\
		ft_toupper.c 			\
		ft_tolower.c 			\
	    ft_strchr.c 			\
		ft_strrchr.c 			\
		ft_strncmp.c 			\
		ft_memchr.c 			\
		ft_memcmp.c 			\
		ft_strnstr.c 			\
		ft_atoi.c 				\
		ft_calloc.c 			\
		ft_strdup.c 			\
		ft_substr.c 			\
		ft_strjoin.c 			\
		ft_strtrim.c 			\
		ft_split.c 				\
		ft_itoa.c 				\
		ft_strmapi.c 			\
		ft_putchar_fd.c 		\
		ft_putstr_fd.c 			\
		ft_putendl_fd.c 		\
		ft_putnbr_fd.c 			\
		ft_striteri.c
BSRCS = ft_lstnew_bonus.c 		\
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c 		\
		ft_lstlast_bonus.c 		\
		ft_lstadd_back_bonus.c 	\
		ft_lstdelone_bonus.c 	\
		ft_lstclear_bonus.c 	\
		ft_lstiter_bonus.c 		\
		ft_lstmap_bonus.c


OBJ = $(SRCS:.c=.o)
BOBJ = $(BSRCS:.c=.o)
NAME = libft.a

.PHONY: all
all : $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c libft.h Makefile
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: bonus
bonus: $(OBJ) $(BOBJ)
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
debug: $(OBJ) $(BOBJ)
	$(CC) $(CFLAGG) $(OBJ) $(BOBJ) main.c -o a.out


