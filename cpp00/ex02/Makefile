NAME := dreamjob

CXX := c++ -std=c++98
CXXFLAGS := -Wall -Wextra -Werror

.PHONY := all clean fclean re

SOURCES :=	tests.cpp \
			Account.cpp

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
