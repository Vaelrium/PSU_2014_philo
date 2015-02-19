##
## Makefile for Makefile in /home/durand_u/github/PSU_2014_philo
## 
## Made by Rémi DURAND
## Login   <durand_u@epitech.net>
## 
## Started on  Thu Feb 19 10:59:30 2015 Rémi DURAND
## Last update Thu Feb 19 11:00:10 2015 Rémi DURAND
##

SRC	=	philo.c

CC	=	gcc

RM	=	rm -f

OBJ	=	$(SRC:.cpp=.o)

NAME	=	philo

CFLAGS	+=	-W -Wall -Wextra -Werror -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all	
