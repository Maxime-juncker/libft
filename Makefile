# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 18:00:56 by mjuncker          #+#    #+#              #
#    Updated: 2024/11/26 13:49:45 by mjuncker         ###   ########.fr        #
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
		ft_printf.c				\

OBJ = $(SRCS:.c=.o)

# adding path for src and obj
OBJ := $(addprefix $(OBJ_D), $(OBJ))
SRCS := $(addprefix $(SRCS_D), $(SRCS))

# compiler settings
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES_D)

# commands
RM = rm -fr

# colors
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m
BLUE = \033[34m

.PHONY: all
all : $(BIN_D)$(NAME)

$(BIN_D)$(NAME): $(OBJ) | $(BIN_D)
	@echo "$(GREEN)[LINKING]: $(NAME)$(RESET)"
	@ar rcs $(BIN_D)$(NAME) $(OBJ)
	@echo "$(GREEN)[SUCCESS]$(RESET)"


$(OBJ_D)%.o: $(SRCS_D)%.c | $(OBJ_D)
	@echo "$(BLUE)[COMPILING]: $@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_D):
	@echo "$(YELLOW)[CREATING]: $(OBJ_D)$(RESET)"
	@mkdir -p $(OBJ_D)

$(BIN_D):
	@echo "$(YELLOW)[CREATING]: $(BIN_D)$(RESET)"
	@mkdir -p $(BIN_D)

.PHONY: clean
clean:
	@echo "$(RED)[CLEAN]: obj files$(RESET)"
	@$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	@echo "$(RED)[CLEAN]: binaries$(RESET)"
	@$(RM) $(BIN_D)$(NAME)
	@$(RM) $(BIN_D)a.out
	@$(RM) $(BIN_D)libft.so

.PHONY: re
re:
	@$(MAKE) fclean
	@$(MAKE) all

debug:
	$(CFLAGS) += -g3
	$(CC) $(CFLAGS) $(SRCS) -o $(BIN_D)a.out

run: debug
	$(BIN_D)a.out