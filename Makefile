# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshiling <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 13:01:36 by sshiling          #+#    #+#              #
#    Updated: 2017/10/11 23:20:04 by sshiling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK_NAME = checker
PUSH_NAME = push_swap
FLAGS = -Wall -Wextra -Werror
INC = -Iincludes/ -I$(LIB_DIR)/includes

CHECK_SRC_NAME = checker.c stack_creator.c quick_sort.c commands.c\
commands_2.c printer.c comb.c comb_2.c divide_stacks.c helpers.c\
push_back.c swap_elements.c swappers.c error_check.c printer_helper.c

CHECK_OBJ_NAME = $(CHECK_SRC_NAME:.c=.o)
CHECK_OBJ = $(addprefix $(OBJ_DIR),$(CHECK_OBJ_NAME))

PUSH_SRC_NAME = push_swap.c stack_creator.c quick_sort.c commands.c\
commands_2.c printer.c comb.c comb_2.c divide_stacks.c helpers.c\
push_back.c swap_elements.c swappers.c error_check.c printer_helper.c

PUSH_OBJ_NAME = $(PUSH_SRC_NAME:.c=.o)
PUSH_OBJ = $(addprefix $(OBJ_DIR),$(PUSH_OBJ_NAME))

LIB_DIR = libft/
SRC_DIR = srcs/
OBJ_DIR = objs/

all: $(CHECK_NAME) $(PUSH_NAME)

$(CHECK_NAME): $(CHECK_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(CHECK_NAME) $(CHECK_OBJ) -L $(LIB_DIR) -lft
	@echo "##### checker compiling finished! #####"

$(PUSH_NAME): $(PUSH_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(PUSH_NAME) $(PUSH_OBJ) -L $(LIB_DIR) -lft
	@echo "##### push_swap compiling finished! #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "##### Creating" [ $@ ] " #####"
	@gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(CHECK_OBJ) $(PUSH_OBJ)
	@echo "##### Removed object files #####"

fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(CHECK_NAME) $(PUSH_NAME)
	@echo "##### Removed binary files #####"

re: fclean all

.PHONY: all clean fclean re

