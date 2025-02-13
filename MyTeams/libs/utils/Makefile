##
## EPITECH PROJECT, 2024
## teams
## File description:
## Makefile
##

SRC	=	./is_digit.c					\
		./str_to_word_array.c			\
		./special_str_to_word_array.c	\
		./use_log_function.c 			\
		./generate_uuid.c				\
		./count_array_length.c			\
		./time_handling.c				\

CC	=	gcc

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-iquote ../../include

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

COPY	=	cp -f

HEADER_FILE	=	utils.h

NAME	=	libutils.a

all: update_include_path $(NAME) update_libs

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

update_include_path:
	$(COPY) $(HEADER_FILE) ../../include

update_libs:
	$(COPY) $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

debug: CFLAGS	+=	-g3
debug: clean all

.PHONY: all clean fclean re update_include_path update_libs	debug
