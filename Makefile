# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 12:31:10 by tiskow            #+#    #+#              #
#    Updated: 2017/09/25 16:05:26 by tiskow           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = ft_ls

SRC_PATH = ./sources
OBJ_PATH = ./objs

SRC_NAME =      ft_ls.c\
                        ft_check_args.c\
                        ft_display_error.c\
                        ft_display_l.c\
                        ft_display_ls.c\
                        ft_sortlist.c\
                        ft_time.c\
                        ft_tools.c\
                        ft_toolslist.c\

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
		@cd ./libs/libft && $(MAKE)
		@$(CC) $(FLAGS) -o $@ $^ ./libs/libft/libft.a
		@echo "----------------------------------"
		@echo "[\033[32m✔\033[0m] $(NAME): Compilation Success"
		@echo "----------------------------------"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(FLAGS) -o $@ -c $<

clean:
		@(rm -rf $(OBJ))
		@cd ./libs/libft && $(MAKE) fclean
		@echo "----------------------------------"
		@echo "[\033[32m✔\033[0m] $(NAME): file *.o Objects deleted"
		@echo "----------------------------------"

fclean: clean
		@rm -rf $(OBJ) $(NAME)
		@rm -rf ./libs/libft/libft.a
		@rm -rf ./libft.a
		@cd ./libs/libft && $(MAKE) clean
		@echo "----------------------------------"
		@echo "[\033[32m✔\033[0m] $(NAME): All deleted"
		@echo "----------------------------------"
        # @cd ./libft && $(MAKE) fclean

re: fclean all