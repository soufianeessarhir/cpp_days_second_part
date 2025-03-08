NAME =account

SOURCES = Bureaucrat.cpp Form.cpp main.cpp                                                                                                                                                                                                                                                                                                           

OBJECTS = $(SOURCES:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 
RM = rm -f

all: $(NAME) $(BNAME)

$(NAME): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp Bureaucrat.cpp Form.cpp main.cpp Makefile                                                                                                                                                      
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re