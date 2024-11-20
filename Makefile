# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 18:00:56 by mjuncker          #+#    #+#              #
#    Updated: 2024/11/20 15:27:35 by mjuncker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# paths
OBJ_D		= obj/
SRCS_D		= src/
BIN_D		= bin/
INCLUDES_D	= includes/

# src file names
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
		ft_striteri.c			\
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c 		\
		ft_lstlast_bonus.c 		\
		ft_lstadd_back_bonus.c 	\
		ft_lstdelone_bonus.c 	\
		ft_lstclear_bonus.c 	\
		ft_lstiter_bonus.c 		\
		ft_lstmap_bonus.c		\
		ft_get_next_line.c		\

OBJ = $(SRCS:.c=.o)

# adding path for src and obj
OBJ := $(addprefix $(OBJ_D), $(OBJ))
SRCS := $(addprefix $(SRCS_D), $(SRCS))

# compiler settings
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES_D)

# commands
RM = rm -fr

.PHONY: all
all : $(NAME)

.PHONY: so
so: clean
	$(MAKE) CFLAGS="$(CFLAGS) -fPIC" $(OBJ)
	$(CC) $(CFLAGS) -shared -o $(BIN_D)libft.so $(OBJ)


$(NAME): $(OBJ) | $(BIN_D)
	ar rcs $(BIN_D)$(NAME) $(OBJ)

$(OBJ_D)%.o: $(SRCS_D)%.c | $(OBJ_D)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_D):
	mkdir -p $(OBJ_D)

$(BIN_D):
	mkdir -p $(BIN_D)

.PHONY: clean
clean:
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	$(RM) $(BIN_D)$(NAME)
	$(RM) $(BIN_D)a.out
	$(RM) $(BIN_D)libft.so

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all

debug:
	$(CFLAGS) += -g3
	$(CC) $(CFLAGS) $(SRCS) -o $(BIN_D)a.out 

run: debug
	$(BIN_D)a.out