NAME	= PanSim

CC	= g++

RM	= rm -f

SRCS	= $(wildcard src/*.cpp)

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS += -Wall -Wextra -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -g

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CPPFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
