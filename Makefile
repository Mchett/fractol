# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchett <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/30 12:29:15 by mchett            #+#    #+#              #
#    Updated: 2019/09/30 12:29:18 by mchett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra -Werror -Ofast -I includes/
INCLUDES = -I ./libft/ -I ./minilibx/
LIBFLAGS = -L./libft -lft -L./minilibx -lmlx -framework OpenGL \
		   -framework AppKit
FILES = main.c image.c mouse.c key.c mlx.c fractols.c math_func.c

SRCS = $(addprefix src/, $(FILES))
OBJ = $(addprefix objectives/, $(FILES:.c=.o))

all: $(NAME)

$(NAME):$(OBJ) | lib
	gcc $(FLAGS) $(LIBFLAGS) -o $(NAME) $(OBJ)

objectives/%.o: src/%.c | objectives
	gcc $(FLAGS) $(INCLUDES) -o $@ -c $^

re: fclean all

lib:
	@make -C ./libft
	@make -C ./minilibx

clean:
	@rm -rf objectives/
	@make clean -C ./libft
	@make clean -C ./minilibx

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)

objectives:
	@mkdir objectives/
