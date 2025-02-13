CC = c++

CURRENT_DIR = $(shell pwd)

NAME = hppbuild
BIN_DIR = $(CURRENT_DIR)
BIN = $(BIN_DIR)/$(NAME)
TEMPLATE_DIR = $(CURRENT_DIR)
BASHRC =	~/.bashrc

SOURCES =	hppbuild.cpp
OBJECTS = $(SOURCES:.cpp=.o)

CFLAGS += -Wall -Wextra -Werror -std=c++98

all: $(BIN)

$(BIN): $(OBJECTS) add_alias
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BIN)
	@make clean --no-print-directory

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -D'TEMPLATE_DIR="$(TEMPLATE_DIR)"'

clean:
	@rm -f $(OBJECTS)

fclean: clean remove_alias
	rm -f $(BIN)
	$(remove_alias)

re: fclean all

remove_alias:
	$(shell cat $(BASHRC) | grep -v "alias $(NAME)=" > $(BASHRC).tmp)
	$(shell cat $(BASHRC).tmp > $(BASHRC); rm $(BASHRC).tmp)

add_alias: remove_alias
	$(shell echo "alias $(NAME)=$(BIN)" >> $(BASHRC))

.PHONY: all clean fclean re

