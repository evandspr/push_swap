NAME=push_swap

FLAGS:=-Wall -Wextra -Werror -I ./ft_printf -I ./libft -g -g3

LIBFT=libft/libft.a
CC=cc
OBJ=$(SRC:.c=.o)

SRC=./src/parsing.c\
	./src/stocking.c\
	./src/instructions_one.c\
	./src/instructions_two.c\
	./src/instructions_three.c\
	./src/main.c\
	./src/algorithm.c\
	./src/algorithm_two.c\

INCLUDS = ./includes/push_swap.h\

GREEN=\033[32m
RED=\033[31m
YELLOW=\033[33m
RESET=\033[0m
CYAN=\033[36m

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(GREEN)✧ Creating libft library... ✧$(RESET)"
	@make -C ./libft/ -s

$(NAME): $(LIBFT) $(OBJ)
	@echo "$(YELLOW)✧ Creating push_swap... ✧$(RESET)"
	@echo "$(CYAN)ıllı DONE ıllı$(RESET)"
	@$(CC) -I $(INCLUDS) -o $(NAME) $(OBJ) $(LIBFT) $(FLAGS)

%.o: %.c
	@$(CC) $(FLAGS) -c $^ -o $@

clean:
	@echo "$(RED)🗑️ clean done 🗑️$(RESET)"
	@rm -rf $(OBJ)
	@make -C libft clean -s

fclean: clean
	@echo "$(RED)🗑️ fclean done 🗑️$(RESET)"
	@rm -rf $(NAME)
	@make -C libft fclean -s

re: fclean all

.PHONY: all cleann fclean re
