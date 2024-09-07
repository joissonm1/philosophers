NAME = philo
SRCS = philo.c philo_verif.c philo_utils.c philo_routine.c
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)
	@clear
	@echo "\033[32mProjeto compilado com sucesso, pode trabalhar!\033[0m"

all: $(NAME)

clean:
	rm -f *.o
	@clear
	@echo "\033[31mTudo eliminado com sucesso, pode bazar!\033[0m"

fclean: clean
	rm -f $(NAME)
	@clear
	@echo "\033[31mTudo eliminado com sucesso, pode bazar!\033[0m"

re: fclean all
