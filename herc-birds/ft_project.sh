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
		echo "place holder for generating C file stuff"
		echo "\033[36m[ generating Makefile ]\033[0m"
		echo "\033[36m[ creating directories ]\033[0m"
		mkdir src lib inc


	fi

	# Flag for clone libft
	if [ "$1" == "-l" ] || [ "$1" == "-L" ] || [ "$2" == "-l" ] || [ "$2" == "-L" ]; then
		echo "\033[36m[ cloning libft ]\033[0m"
		git clone https://github.com/s-gorrin/42-libft.git libft
	fi
fi
