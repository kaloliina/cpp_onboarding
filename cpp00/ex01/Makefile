NAME = phonebook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = include/
SRCS = $(SRC_DIR)Contact.cpp $(SRC_DIR)PhoneBook.cpp $(SRC_DIR)main.cpp
OBJS = $(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
HEADERS = $(INC_DIR)Contact.hpp $(INC_DIR)PhoneBook.hpp

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADERS) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
