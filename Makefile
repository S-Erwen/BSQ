# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rkowalsk <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/07/23 15:32:09 by rkowalsk     #+#   ##    ##    #+#        #
#    Updated: 2019/07/24 00:05:42 by nepage-l    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = bsq
SRCS = main.c srcs/ft_check_map.c srcs/ft_split.c srcs/print_map.c srcs/set_matrix.c srcs/util.c srcs/read_map.c srcs/solve.c srcs/util2.c
HEADER = includes/ft.h
OBJS = ${SRCS:.c=.o}

.c.o: $(HEADER)
		gcc -Wall -Wextra -Werror -I includes -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
		gcc $(OBJS) -o $(NAME)

all : $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
