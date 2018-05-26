# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 11:16:54 by bgeorges          #+#    #+#              #
#    Updated: 2018/05/13 20:59:22 by bgeorges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		:=	gcc -Wall -Wextra -Werror

SRC 	=	ft_printf.c \
			ft_find_flags.c \
			ft_find_lenght.c \
			ft_find_specifiers.c \
			ft_find_type.c \
			ft_specifier_dec.c \
			ft_specifier_str.c \
			ft_specifier_base.c \
			ft_get_flags_neg_pos_sp.c \
			ft_get_flags_hash_zero.c \
			ft_find_width.c \
			ft_check_specifiers_flags.c \
			ft_dispatcher_flags.c \
			ft_aff_unicode.c \
			ft_change_width.c \
			ft_transform_wchar_in_char.c \

OBJ 	=	$(SRC:.c=.o)

OBJ_PATH =	./obj/
OBJ_DIR =	$(addprefix ./obj/,$(OBJ))
SRC_DIR =	$(addprefix ./src/,$(SRC))

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(SRC_DIR) -I src/ft_printf.h
	@mv $(OBJ) $(OBJ_PATH)
	@ar rcs $(NAME) $(OBJ_DIR)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
