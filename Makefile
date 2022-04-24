NAME =		philo

CFLAGS =	#-Wall -Wextra -Werror

SRCS =		main.c \
			srcs/init_pthread.c\

OBJS =		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			gcc -g -pthread $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		cleans
			rm -f $(NAME)

re: 		fclean all

.PHONY:		re clean fclean all