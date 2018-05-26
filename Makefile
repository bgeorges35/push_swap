# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 11:16:54 by bgeorges          #+#    #+#              #
#    Updated: 2018/05/23 20:50:58 by bgeorges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAGS =  -I push_swap.h -Wall -Wextra -Werror
CC = gcc
PATH_LIB=./libft/libft.a
EXEC_PUSH = push_swap
EXEC_CHECK = checker

PATH_CHECK = checker_dir/
PATH_PUSH = push_swap_dir/
PATH_COM = Commun_dir/

SRC3			=	check_sort_tab.c \
					error.c \
					free_struct.c \
					init_struct.c \
					instruction_push.c \
					instruction_reverse.c \
					instruction_rotate.c \
					instruction_swap.c \


SRC1			=	algo.c \
					basics_functions.c \
					push_swap.c \
					stack_a_b.c \
					exceptions.c \

SRC2			=	checker.c \
					instruction.c \


SRC_CHECKER = $(addprefix $(PATH_CHECK), $(SRC2))
SRC_PUSH = $(addprefix $(PATH_PUSH), $(SRC1))
SRC_COM = $(addprefix $(PATH_COM), $(SRC3))


OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)

all: $(LIB) $(EXEC_PUSH) $(EXEC_CHECK)

$(LIB):
	@make -C ./Libft
$(EXEC_PUSH):
	@make -C ./Libft
	@$(CC) -c $(FLAGS) $(SRC_PUSH)
	@$(CC) -c $(FLAGS) $(SRC_COM)
	@$(CC) $(FLAGS) $(OBJ1) $(OBJ3) $(PATH_LIB) -o $(EXEC_PUSH)

$(EXEC_CHECK):
	@$(CC) -c $(FLAGS) $(SRC_CHECKER)
	@$(CC) -c $(FLAGS) $(SRC_COM)
	@$(CC) $(FLAGS) $(OBJ2) $(OBJ3) $(PATH_LIB) -o $(EXEC_CHECK)

%.o:%.c
	@gcc $(FLAGS) $< -o $@

clean:
	@make clean -C ./Libft
	@rm -f $(OBJ2)
	@rm -f $(OBJ1)
	@rm -f $(OBJ3)


fclean: clean
	@make fclean -C ./Libft
	@rm -f $(EXEC_CHECK)
	@rm -f $(EXEC_PUSH)

re : fclean all

.PHONY : clean fclean re all
