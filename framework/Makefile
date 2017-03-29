# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thugo <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/28 14:48:37 by thugo             #+#    #+#              #
#    Updated: 2017/03/29 18:53:11 by thugo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Binary
NAME = libunit.a
#GCC Flags
FLAGS = -Werror -Wall -Wextra
#Source files
SRC = register.c launcher.c
#Dependance files
DEP = Makefile includes/libunit.h
OBJ = $(addprefix obj/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(DEP)
	@make -C libft
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) -I includes -I libft -c $^ -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rm -rf obj

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
