NAME =		philo

CFLAGS =	-Wall -Wextra -Werror -g -fsanitize=address 

SRCS =		main.c \
			srcs/init_pthread.c \
			srcs/check.c \
			srcs/philo.c \
			srcs/utils.c\

OBJS =		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			gcc -g -pthread $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re: 		fclean all

.PHONY:		re clean fclean all