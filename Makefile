# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 18:14:19 by dmorar            #+#    #+#              #
#    Updated: 2019/04/17 14:42:30 by dmorar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ./push_swap

NAME2 = ./checker

FLAGS = -Wall -Wextra -Werror

LIBDIR = libft

OBJ_DIR = ./obj

LIB = $(LIBDIR)/libft.a

INC = -I $(LIBDIR) -I .

LIB_LNK = -L $(LIBDIR) -lft

SRC = main_swap.c moves.c only_max_min.c push_swap.c validation.c validation2.c

SRC2 = checker.c moves.c validation.c validation2.c checker2.c visualisation.c visualisation2.c

OBJ     = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

OBJ2     = $(addprefix $(OBJ_DIR)/,$(SRC2:%.c=%.o))

all: $(NAME) $(NAME2)

pswp: $(NAME)

check: $(NAME2)

$(NAME): LIB $(OBJ)
	@gcc $(FLAGS) $(INC) $(LIB_LNK) $(OBJ) -o $(NAME)

$(NAME2): LIB $(OBJ2)
	@gcc $(FLAGS) $(INC) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(LIB_LNK) $(OBJ2) -o $(NAME2)

LIB:
	@make -C libft

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(addprefix $(OBJ_DIR)/, %.o): %.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	make clean -C libft
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)
	rm -f $(NAME2)

re: fclean all
