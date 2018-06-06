NAME := ignore

CC := gcc
FLAGS := -Wall -Wextra -Werror
LIB := minilibx_macos_10.11/libmlx.a libft/libft.a
FW := -framework OpenGL -framework AppKit

BIN_DIR := objs

# Files names
FILES += main	fdf_line	fdf_key		fdf_draw
BIN := $(addsuffix .o,$(FILES))

OBJS := $(addprefix $(BIN_DIR)/,$(BIN))

$(BIN_DIR)/%.o: %.c
	@$(CC) $(FLAGS) -I . -c $^ -o $@
	@/bin/echo -n "#"

.PHONY: debug clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n\033[32m[ ᕦ(ˇò_ó)ᕤ object files created ᕦ(ò_óˇ)ᕤ ]\033[0m"
	@make -C libft
	@$(CC) $(FLAGS) $(FW) $(OBJS) $(LIB) -o $(NAME)
	@echo "\033[36m[ (^-^)/ executable \033[35m$(NAME)\033[35m \033[36mcreated \(^-^) ]\033[0m"

$(OBJS): | $(BIN_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

clean:
	@/bin/rm -rf $(BIN_DIR)
	@echo "\033[31m[object files deleted]\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31m[executable \033[35m$(NAME)\033[0m \033[31mdeleted]\033[0m"

debug: $(OBJS)
	@echo "\n\033[32m[ ᕦ(ˇò_ó)ᕤ object files created ᕦ(ò_óˇ)ᕤ ]\033[0m"
	@/bin/rm -f rm $@
	@$(CC) -g $(FLAGS) $(FW) $(OBJS) $(LIB) -o $(NAME)
	@echo "debug executable created"

re: fclean all

