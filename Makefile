# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 15:56:17 by rdas-nev          #+#    #+#              #
#    Updated: 2022/04/25 15:59:42 by rdas-nev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 

OBJS	= $(addprefix objs/,$(SRCS:.c=.o))

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

NAME	= fdf

# COLORS

DARKRED	= \033[0;31m
RED		= \033[1;3;91m
GREEN	= \033[1;3;92m
BLUE	= \033[1;3;94m
YELLOW	= \033[1;3;93m
CYAN	= \033[0;36m
NC		= \033[0;0m

all:		$(NAME)

objs/%.o: srcs/%.c
			@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): 	$(OBJS)
			@cc $(OBJS) -g -o $(NAME)
			@echo  "\n${YELLOW}A wild ${RED}push${GREEN}_${BLUE}swap ${YELLOW}appears in current dir...${NC}\n"

clean:
			@$(RM) $(OBJS)
			@echo "\n${DARKRED}OBJS DESTROYED! ${NC}\n"

fclean:		clean
			@$(RM) $(NAME)
			@echo "\n${RED}push${GREEN}_${BLUE}swap ${CYAN}says goodbye! ${NC}\n"

re:			fclean all
			@echo "\n${RED}push${GREEN}_${BLUE}swap ${CYAN}remade! ${NC}\n" 

