NAME := array
CXX := c++
CXXFLAGS := -std=c++17 -Wall -Wextra -Werror

.PHONY := all clean fclean re

SOURCES :=	main.cpp

OBJECTS := $(SOURCES:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
