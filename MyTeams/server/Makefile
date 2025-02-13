##
## EPITECH PROJECT, 2024
## Server
## File description:
## Makefile
##

SRC	=	./main.c \
\
		./src/handle_server_error.c \
		./src/init_server.c \
		./src/server_loop.c \
		./src/client_management.c \
		./src/command_handling.c \
		./src/do_command.c \
\
		./src/command/login.c \
		./src/command/logout.c \
		./src/command/users.c \
		./src/command/help.c \
		./src/command/user.c \
		./src/command/send.c \
		./src/command/messages.c \
\
		./src/command/utils/finder.c \
		./src/command/utils/send_uuid_error.c \
		./src/command/utils/send_to_client.c \
\

OBJ	=	$(SRC:.c=.o)

RM	=	rm -rf

CC	=	gcc

CFLAGS	=	-Wall -Wextra

LDFLAGS	=	-L../libs -ljson -lutils -L../libs/myteams -lmyteams

CPPFLAGS	=	-iquote ../include/

NAME	=	myteams_server

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
