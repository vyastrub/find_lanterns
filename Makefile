NAME =  trams
SRCS =  src/main.cpp src/city.cpp src/parcer.cpp
FLAGS = -std=c++11 -Wall -Werror -Wextra 
BINS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(BINS)
	g++ -o $(NAME) $(BINS) $(FLAGS) 
%.o: %.c
	g++ $(FLAGS) -c -o $@ $<
clean:
	/bin/rm -f *.o
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all