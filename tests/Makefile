# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thugo <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/28 14:48:37 by thugo             #+#    #+#              #
#    Updated: 2017/03/31 00:07:32 by thugo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Binary
NAME = unit_test
#GCC Flags
FLAGS = -Werror -Wall -Wextra
#Includes Folders
INCLUDES = -I .
#Link library
LINKS = -L. -lft
#Source files
SRC = main.c $(wildcard */*.c)
#Dependance files
DEP = Makefile $(wildcard */*.h)

OBJ = $(addprefix .obj/, $(SRC:.c=.o))
INCLUDES += $(foreach dirs, $(wildcard */), -I $(dirs)) -I ../framework/includes
LINKS += -L. -lunit

all: $(NAME)

run: $(NAME)
	-@./$(NAME)

$(NAME): $(OBJ) $(DEP)
	@printf "\n[\e[33m$(NAME)\e[0m] \e[34mBuild:\e[0m $(NAME)"
	@gcc $(OBJ) $(LINKS) -o $(NAME)
	@printf " [\e[32mOK\e[0m]\n"

.obj/%.o: %.c
	@printf "[\e[33m$(NAME)\e[0m] \e[34mCompile:\e[0m $^\e[K\r"
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) $(INCLUDES) -c $^ -o $@
	@printf "[\e[33m$(NAME)\e[0m] \e[34mCompile:\e[0m $^ [\e[32mOK\e[0m]\e[K\r"

clean:
	@printf "[\e[33m$(NAME)\e[0m] \e[34mDelete objects\e[0m"
	@rm -f $(OBJ)
	@rm -rf .obj
	@printf " [\e[32mOK\e[0m]\n"

fclean: clean
	@printf "[\e[33m$(NAME)\e[0m] \e[34mDelete binary\e[0m"
	@rm -f $(NAME)
	@printf " [\e[32mOK\e[0m]\n"

re: fclean all

.PHONY: all run clean fclean re
