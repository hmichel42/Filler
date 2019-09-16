# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/06 16:29:54 by maegaspa     #+#   ##    ##    #+#        #
#    Updated: 2019/08/07 18:09:36 by hmichel     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = hmichel.filler
CC = gcc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
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
	@$(CC) $(FLAGS) src/get_next_line.c src/main.c src/parsing.c libft/libft.a -o $(NAME)
	#@mv hmichel.filler ../resources_Filler/players
	#@rm ../resources_Filler/text.log
	#@touch ../resources_Filler/text.log
	
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
