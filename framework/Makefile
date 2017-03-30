# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thugo <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/28 14:48:37 by thugo             #+#    #+#              #
#    Updated: 2017/03/30 03:56:39 by thugo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Binary
NAME = libunit.a
#GCC Flags
FLAGS = -Werror -Wall -Wextra
#Source files
SRC = register.c launcher.c init.c minilib/ml_lstnew.c minilib/ml_lstpush.c
#Dependance files
DEP = Makefile includes/libunit.h
OBJ = $(addprefix obj/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(DEP)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) -I includes -c $^ -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
