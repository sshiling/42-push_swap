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

NAME_1 = checker

NAME_2 = push_swap

SRCS_1 = checker.c

SRCS_2 = push_swap.c

SRCS = stack_creator.c quick_sort.c commands.c commands_2.c printer.c comb.c\
	comb_2.c divide_stacks.c helpers.c push_back.c swap_elements.c swappers.c\
	error_check.c printer_helper.c

LIBFT = libft/

OBJECTS_1 = $(SRCS_1:.c=.o)

OBJECTS_2 = $(SRCS_2:.c=.o)

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJECTS) $(OBJECTS_1)
	@echo "Creating .o files. Please wait..."
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME_1) $(OBJECTS) $(OBJECTS_1)  -L $(LIBFT) -lftprintf
	@echo "All .o files successfully created."
	@echo "Executable successfully created."

$(NAME_2): $(OBJECTS_2)
	@echo "Creating .o files. Please wait..."
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME_2) $(OBJECTS) $(OBJECTS_2)  -L $(LIBFT) -lftprintf
	@echo "All .o files successfully created."
	@echo "Executable successfully created."

clean:
	@echo "Deleting all .o files. Please wait..."
	@rm -f $(OBJECTS) $(OBJECTS_1) $(OBJECTS_2)
	@make clean -C $(LIBFT)
	@echo "All .o files deleted."	

fclean: clean
	@echo "Deleting all .o files and executable. Please wait..."
	@rm -f $(NAME_1)
	@rm -f $(NAME_2)
	@make fclean -C $(LIBFT)
	@echo "All .o files and executable deleted."	

re: fclean all

.PHONY: re all clean fclean
