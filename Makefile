# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 15:01:01 by okapshai          #+#    #+#              #
#    Updated: 2024/09/26 14:10:07 by okapshai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

NAME = philo

 
SRCS				:=	doctor.c \
						clean.c \
						print_state.c \
						init.c \
						check_args.c \
						party.c \
						time_handle.c \
						libft_1.c \
						libft_2.c \
						main.c \



OBJS = $(SRCS:.c=.o)

HEADER = philo.h \

GREEN = '\033[0;32m'
CYAN = '\033[0;36m'
WHITE = '\033[0;37m'

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo ✅ $(GREEN)"Project successfully compiled"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo 🧹 $(CYAN)"Removing .o files"$(WHITE)
	rm -f $(OBJS)

fclean: clean
	@echo 🧹 $(CYAN)"Removing all"$(WHITE)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re