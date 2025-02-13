##
## EPITECH PROJECT, 2024
## client
## File description:
## Makefile
##

SRC	=	./main.c \
\
		./src/handle_client_error.c \
		./src/start_loop.c	\
		./src/in_connection.c	\
		./src/create_socket.c	\
		./src/read_message.c	\
		./src/call_log.c	\

OBJ	=	$(SRC:.c=.o)

RM	=	rm -rf

CC	=	gcc

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-iquote ../include/

LDFLAGS	=	-L../libs -lutils -ljson -L../libs/myteams -lmyteams

NAME	=	myteams_cli

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS) $(LDFLAGS)
			mv ./$(NAME) ../

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) ../$(NAME)

debug:		CFLAGS += -g3
debug:		clean all

re:			fclean all

.PHONY:		all clean fclean re debug
