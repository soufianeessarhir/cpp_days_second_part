NAME =ex02

SOURCES = AForm.cpp Bureaucrat.cpp main.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 
RM = rm -f

all: $(NAME) $(BNAME)

$(NAME): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp  AForm.hpp Bureaucrat.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re