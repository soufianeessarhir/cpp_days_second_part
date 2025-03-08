NAME =ex03

SOURCES = AForm.cpp Bureaucrat.cpp main.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 
RM = rm -f

all: $(NAME) $(BNAME)

$(NAME): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp  AForm.hpp Bureaucrat.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Makefile Intern.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re