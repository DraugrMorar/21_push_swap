# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 19:30:33 by dmorar            #+#    #+#              #
#    Updated: 2019/04/02 13:55:29 by dmorar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_H   = ./

OBJ_DIR = ./obj

NAME    = libft.a

SRC     = $(wildcard *.c)

OBJ     = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

CC      = gcc

FLAGS   = -Wall -Wextra -Werror

INC     = -I $(LIB_H)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(addprefix $(OBJ_DIR)/, %.o): %.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all