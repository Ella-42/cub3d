# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 02:14:32 by lpeeters          #+#    #+#              #
#    Updated: 2024/03/15 21:32:45 by lpeeters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

program_name = cub3D

compiler = cc

minilibx_flags = -L /usr/lib -l Xext -l X11 -l m -l z

compilation_flags = -g -Wall -Werror -Wextra

#find other makefiles
makefiles = ${shell find . -mindepth 2 \( -name "Makefile" -o -name "makefile" \) -not -path "*test*"}

#fetch makefile directory
makefile_directories = ${sort ${dir ${makefiles}}}

#make other projects that were found
makefiles_compilation = ${foreach makefile_directory,${makefile_directories}, make -sC ${makefile_directory} ;}

source_files = ${shell find ./ -name "*.c" -not -path "*lib*" -a -not -path "*mlx*"}

header_files = ${shell find ./ -name "*.h" -not -path "*lib*" -a -not -path "*mlx*"}

header_directories = ${sort ${foreach header_path,${header_files},${dir ${header_path}}}}

header_includes = ${foreach header_directory,${header_directories},-I ${header_directory}}

#find library files
library_files = ${shell find . -name "*.a"}

#fetch library directories
library_file_directories = ${sort ${dir ${library_files}}}

#fetch library filenams
library_file_path_names = ${notdir ${library_files}} #cut off the path
library_names = ${library_file_path_names:lib%.a=%} #cut off the library files' "lib" prefix
library_file_names = ${library_names:.a=} #cut off the library files' ".a" suffix

#compilation flags, their directories and names for any library
library_files_compilation_flags = ${foreach library_directory,${library_file_directories},-L ${library_directory}} \
	  ${foreach library_file_name,${library_file_names},-l ${library_file_name}}

object_directory = objects/

make_object_directory = mkdir -p ${@D}

object_files = ${source_files:%.c=${object_directory}%.o}

force_remove = rm -rf

silence_output = > /dev/null

# Color codes for printing colorful text
white = \033[0;39m
yellow = \033[38;5;226m
green = \033[0;92m
red = \033[0;31m

# Move the cursor up one line
up = \033[A

# Erase the current line on the cursor
clear = \033[K

# Build dependency
program: compile_makefiles ${program_name}

#TODO: fix dependencies
compile_makefiles:
	@${makefiles_compilation}

# Build executable
${program_name}: ${source_files} ${header_files}
	@echo "${yellow}compiling into executable...${white}"
	@printf "${up}${clear}"
	@if [ ! -e "${program_name}" ] && [ ! -d "${object_directory}" ]; then \
		${compiler} ${compilation_flags} ${source_files} ${header_includes} ${library_files_compilation_flags} ${minilibx_flags} -o ${program_name}; \
		if [ $$? -ne 0 ] || [ ! -e "${program_name}" ]; then \
			echo "${red}error compiling executable${white}"; \
		else \
			echo "${green}done compiling executable${white}"; \
		fi \
	else \
		make -s obj; \
		${compiler} ${compilation_flags} ${object_files} ${library_files_compilation_flags} ${minilibx_flags} -o ${program_name}; \
		if [ $$? -ne 0 ] || [ ! -e "${program_name}" ]; then \
			echo "${red}error compiling object files${white}"; \
		else \
			echo "${green}done compiling executable${white}"; \
		fi \
	fi

# Create object files
obj: ${object_files}

# Compile object files
${object_directory}%.o: %.c ${header_files}
	@${make_object_directory}
	@echo "${yellow}compiling $< into an object file...${white}"
	@if [ $$? -eq 0 ]; then \
		printf "${up}${clear}"; \
	fi
	@${compiler} ${compilation_flags} -c $< ${header_includes} -o $@
	@if [ $$? -ne 0 ]; then \
		echo "${red}error compiling object files${white}"; \
	elif [ "./${<:%.c=%.o}" = "${lastword ${source_files:%.c=%.o}}" ]; then \
		echo "${green}done compiling object files${white}"; \
	fi

# If they exist, remove unecessary files for the final product
#TODO: fix if conditional checking if no projects were cleaned
clean:
	@$(cleaned = 0)
	@$(foreach dir,$(makefile_directories),\
		if [ -n "$$(find $(dir) -maxdepth 1 -name '*.a' -print -quit)" ]; then \
			echo "$(red)removing library files in $(dir)...$(white)"; \
			make -sC $(dir) fclean; \
			$(cleaned = $$(shell expr $(cleaned) + 1)) \
		fi;)
	@if [ "$(cleaned)" = "0" ]; then \
		echo "make: No library files to be cleaned."; \
	fi
	@# does not work yet ^
	@if [ -d "${object_directory}" ]; then \
		echo "${red}removing object files...${white}"; \
		${force_remove} ${object_directory}; \
	else \
		echo "make: No object files to be cleaned."; \
	fi

# Remove everything that was created by this makefile
fclean: clean
	@if [ -e "${program_name}" ]; then \
		echo "${red}removing executable...${white}"; \
		${force_remove} ${program_name}; \
	else \
		echo "make: No executable to be cleaned."; \
	fi

# Remove everything that was created, then build once more
re: fclean program

# Targets
.PHONY: compile_makefiles program obj clean fclean re
