# Makefile principale

TARGET = my_program
SRC_DIR = printffone
LIB_DIR = libft
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
LIB = $(LIB_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -I$(LIB_DIR)

all: $(TARGET)

$(TARGET): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIB_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIB):
	@$(MAKE) -C $(LIB_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(TARGET)
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
