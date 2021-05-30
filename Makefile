NAME = beautiful_number

STD = -std=c++2a

SOURCE_FILES =	main.cpp

SRC = $(addprefix src/, $(SOURCE_FILES))

OBJS = $(SRC:.cpp=.o)

CXX = clang++
CXXFLAGS = $(STD) -Wall -Wextra -Werror

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:			fclean all