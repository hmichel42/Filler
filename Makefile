# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/06 16:29:54 by maegaspa     #+#   ##    ##    #+#        #
#    Updated: 2019/07/25 17:09:40 by hmichel     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = hmichel.filler
CC = gcc
FLAGS = -Wall -Wextra -Werror
INC = /includes/printf.h

FILES = src/get_next_line\
		src/main\
		src/parsing\

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Je suis le boss."
	@make -C libft/
	@$(CC) $(FLAGS) $(OBJ)
	
object/%.o	:	%.c $(INC) #metter flags en dependance
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

clean:
	@echo "	 ██████╗██╗     ███████╗ █████╗ ███╗   ██╗██╗███╗   ██╗ ██████╗    	███████╗██╗██╗	   ██╗	   ███████╗██████╗ "
	@echo "	██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║██║████╗  ██║██╔════╝     ██╔════╝██║██║     ██║	   ██╔════╝██╔══██╗"
	@echo "	██║     ██║     █████╗  ███████║██╔██╗ ██║██║██╔██╗ ██║██║  ███╗    █████╗	██║██║	   ██║	   █████╗  ██████╔╝"
	@echo "	██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║██║██║╚██╗██║██║   ██║    ██╔══╝	██║██║	   ██║	   ██╔══╝  ██╔══██╗"
	@echo "	╚██████╗███████╗███████╗██║  ██║██║ ╚████║██║██║ ╚████║╚██████╔╝    ██║		██║███████╗███████╗███████╗██║  ██║"
	@echo "	 ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝ ╚═════╝     ╚═╝		╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝"
	@rm -f $(OBJ)
	@make clean -C libft/

onlylibft:
	@make -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all
