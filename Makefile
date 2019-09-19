# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/06 16:29:54 by maegaspa     #+#   ##    ##    #+#        #
#    Updated: 2019/09/19 02:41:30 by hmichel     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = hmichel.filler
CC = gcc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
INC = includes/filler.h

FILES = src/get_next_line\
		src/main\
		src/parsing\
		src/heat_map\
		src/resolve

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@echo "Je suis le boss."
	@make -C libft/
	@$(CC) $(FLAGS) src/get_next_line.c src/main.c src/parsing.c src/heat_map.c src/resolve.c libft/libft.a -o $(NAME)
	@cp hmichel.filler players
	@./filler_vm -f maps/map00 -p1 players/champely.filler -p2 players/hmichel.filler
	@open trace.txt
	#@rm ../resources_Filler/text.log
	#@touch ../resources_Filler/text.log
	
object/%.o	:	%.c $(INC) #metter flags en dependance
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

clean:
	@echo "	 ██████╗██╗     ███████╗ █████╗ ███╗   ██╗██╗███╗   ██╗ ██████╗     ███████╗██╗██╗     ██╗     ███████╗██████╗ "
	@echo "	██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║██║████╗  ██║██╔════╝     ██╔════╝██║██║     ██║     ██╔════╝██╔══██╗"
	@echo "	██║     ██║     █████╗  ███████║██╔██╗ ██║██║██╔██╗ ██║██║  ███╗    █████╗	██║██║     ██║     █████╗  ██████╔╝"
	@echo "	██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║██║██║╚██╗██║██║   ██║    ██╔══╝	██║██║     ██║     ██╔══╝  ██╔══██╗"
	@echo "	╚██████╗███████╗███████╗██║  ██║██║ ╚████║██║██║ ╚████║╚██████╔╝    ██║		██║███████╗███████╗███████╗██║  ██║"
	@echo "	 ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝ ╚═════╝     ╚═╝		╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝"
	@rm -f $(OBJ)
	@make clean -C libft/

trace:
	@rm trace.txt
	@touch trace.txt

onlylibft:
	@make -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all