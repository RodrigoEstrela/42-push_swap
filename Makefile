# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 15:56:17 by rdas-nev          #+#    #+#              #
#    Updated: 2022/05/05 15:00:31 by rdas-nev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_putstr.c ft_atoi.c ft_putunsigned.c \
		  ft_bzero.c ft_putchar.c ft_strlen.c pushes.c ft_calloc.c ft_puthex.c \
		  ft_strupper.c ft_itoa.c ft_putptr.c ft_uitoa.c rotates.c mvmnts_tester.c \
		  ft_memset.c ft_putsigned.c swaps.c main.c ft_lstnew.c ft_lstadd_back.c \
		  ft_lstadd_front.c ft_lstlast.c ft_lstindex.c ft_lstsize.c ft_lstdelone.c \
		  ft_isdigit.c input_reader.c ft_split.c \


OBJS	= $(addprefix objs/,$(SRCS:.c=.o))

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

NAME	= push_swap

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

