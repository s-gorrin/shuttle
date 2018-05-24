#!/bin/sh

if [ "$1" == "-h" ] || [ "$1" == "--help" ]; then
	echo "Info:
Always generates .gitignore file.
For C files, use \"-c\" or \"-C\" to generate blank Makefile and create directories.
To clone libft, use \"-l\" or \"-L\""
else	
	# Generate .gitignore
	echo "\033[36m[ generating .gitignore ]\033[0m"
	echo "# Object files
*.o
*.obj
*.ko
*.elf

# Unnamed executables
a.out

# Debug files
*.dSYM/
*.su
*.idb
*.pdb

# Intentional ignores
*.ignore
ignore*" > TESTgitignore

	# Flag for C files
	if [ "$1" == "-c" ] || [ "$1" == "-C" ] || [ "$2" == "-c" ] || [ "$2" == "-C" ]; then
		echo "\033[36m[ generating Makefile ]\033[0m"
		echo "NAME :=" >> Makefile
		echo "" >> Makefile
		echo "CC := gcc" >> Makefile
		echo "CFLAGS += -Wall -Wextra -Werror" >> Makefile
		echo "" >> Makefile
		echo "SOURCE_DIR := src" >> Makefile
		echo "BIN_DIR := obj" >> Makefile
		echo "" >> Makefile
		echo "" >> Makefile
		echo "# SOURCE_DIR := \$(addprefix \$(SOUCE_DIR)/,\$())" >> Makefile
		echo "" >> Makefile
		echo "" >> Makefile
		echo "OBJ := \$(addprefix \$(BIN_DIR)/,\$())" >> Makefile
		echo "" >> Makefile
		echo "INC := inc" >> Makefile
		echo "" >> Makefile
		echo "\$(BIN_DIR)/%.o: $\(SOURCE_DIR)/%.c" >> Makefile
		echo "	@\$(CC) \$(CFLAGS) -I \$(INC) -c $^ -o $@" >> Makefile
		echo "	@/bin/echo -n \"#\"" >> Makefile
		echo "" >> Makefile
		echo ".PHONY: clean fclean re" >> Makefile
		echo "" >> Makefile
		echo "all: \$(NAME)" >> Makefile
		echo "" >> Makefile
		echo "\$(NAME): \$(OBJ)" >> Makefile
		echo "	@echo \"\\\n\\\033[32m[ object files created ( ͡° ͜ʖ ͡°) ]\\\033[0m\"" >> Makefile
		echo "	@\$(CC) \$(OBJ) -o \$(NAME)" >> Makefile
		echo "	@echo \"\\\033[32m[ executable \$(NAME) created ( ͡° ͜ʖ ͡°) ]\\\033[0m\"" >> Makefile
		echo "" >> Makefile
		echo "\$(OBJ): | \$(BIN_DIR)" >> Makefile
		echo "" >> Makefile
		echo "\$(BIN_DIR):" >> Makefile
		echo "	@mkdir -p \$(addprefix \$(BIN_DIR)/,\$())" >> Makefile
		echo "" >> Makefile
		echo "" >> Makefile
		echo "clean:" >> Makefile
		echo "	@rm -rf \$(BIN_DIR)" >> Makefile
		echo "	@echo \"\\\033[31m[ object files deleted (╯°□°）╯︵ ┻━┻ ]\\\033[0m\"" >> Makefile
		echo "" >> Makefile
		echo "fclean: clean" >> Makefile
		echo "	@rm -rf \$(NAME)" >> Makefile
		echo "	@echo \"\\\033[31m[ executable \$(NAME) deleted ᕙ(⇀‸↼‶)ᕗ ]\\\033[0m\"" >> Makefile
		echo "" >> Makefile
		echo "re: fclean all" >> Makefile
		echo "\033[36m[ creating directories ]\033[0m"
		mkdir src lib inc


	fi

	# Flag for clone libft
	if [ "$1" == "-l" ] || [ "$1" == "-L" ] || [ "$2" == "-l" ] || [ "$2" == "-L" ]; then
		echo "\033[36m[ cloning libft ]\033[0m"
		git clone https://github.com/s-gorrin/42-libft.git libft
	fi
fi
