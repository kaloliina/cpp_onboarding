NAME = abstract
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = include/
SRCS = $(SRC_DIR)Animal.cpp $(SRC_DIR)Cat.cpp $(SRC_DIR)Dog.cpp $(SRC_DIR)WrongAnimal.cpp $(SRC_DIR)WrongCat.cpp $(SRC_DIR)Brain.cpp $(SRC_DIR)main.cpp
OBJS = $(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
HEADERS = $(INC_DIR)Animal.hpp $(INC_DIR)Cat.hpp $(INC_DIR)Dog.hpp $(INC_DIR)WrongAnimal.hpp $(INC_DIR)WrongCat.hpp $(INC_DIR)Brain.hpp

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
