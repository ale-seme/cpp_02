NAME = a.out

CC = g++

INCLUDES = -I./include

SRC =  main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

CFLAGS = -Wall -Werror -Wextra -std=c++11 -fsanitize=address

DIR_SRC = src
DIR_OBJ = obj

# Full path to source files
FILES_SRC := $(addprefix $(DIR_SRC)/, $(SRC))

# Full path to object files
OBJ := $(subst $(DIR_SRC)/, $(DIR_OBJ)/, $(FILES_SRC:.cpp=.o))

# Target to build the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Default target
all: $(NAME)

# Rule to compile source files into object files
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.cpp
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up object files and directories
clean:
	rm -rf $(DIR_OBJ)

# Clean up everything including the executable
fclean: clean
	rm -rf $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
