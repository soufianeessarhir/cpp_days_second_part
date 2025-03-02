
GREEN   = \033[32;1m
RED     = \033[31;1m
YELLOW  = \033[33;1m
BLUE    = \033[34;1m
MAGENTA = \033[35;1m
CYAN    = \033[36;1m
WHITE   = \033[37;1m
RESET   = \033[0m


NAME        = RPN
CC          = c++
CPPFLAGS    = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address


SRC         =  main.cpp 


OBJ         = $(SRC:.cpp=.o)


COUNTER     = 0
TOTAL       = $(words $(SRC))


all: banner $(NAME)

banner:
	@echo "$(MAGENTA)"
	@echo "╔══════════════════════════════════════╗"
	@echo "║            Bureaucrat               ║"
	@echo "╚══════════════════════════════════════╝$(RESET)"

$(NAME): $(OBJ)
	@echo "$(YELLOW)\nLinking objects...$(RESET)"
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Build successful! ✨$(RESET)"

%.o: %.cpp $(NAME).hpp Makefile
	@printf "$(CYAN)Compiling [%d/%d] %s...$(RESET)\r" $$(($(COUNTER) + 1)) $(TOTAL) $<
	@$(CC) $(CPPFLAGS) -c $< -o $@
	@$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJ)
	@echo "$(GREEN)Clean complete! 🧹$(RESET)"

fclean: clean
	@echo "$(RED)Removing executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)Full clean complete! 🧹✨$(RESET)"

re: fclean all

.PHONY: all clean fclean re banner

help:
	@echo "$(CYAN)Available commands:$(RESET)"
	@echo "$(WHITE)make all    $(BLUE)- Build the program$(RESET)"
	@echo "$(WHITE)make clean  $(BLUE)- Remove object files$(RESET)"
	@echo "$(WHITE)make fclean $(BLUE)- Remove object files and executable$(RESET)"
	@echo "$(WHITE)make re     $(BLUE)- Rebuild the program$(RESET)"