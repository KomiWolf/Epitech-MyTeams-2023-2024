##
## EPITECH PROJECT, 2023
## B-NWP-400-PAR-4-1-myteams-thomas.lebouc
## File description:
## Makefile
##

SRC	=	\
		./to_json.c	\
		./pop_node.c	\
		./my_putstr.c	\
		./init_json.c	\
		./to_string.c	\
		./json_str_to_word_array.c	\
\
		./append/append_int.c	\
		./append/append_char.c	\
		./append/append_node.c	\
		./append/append_dict.c	\
		./append/append_string.c	\
		./append/append_size_t.c	\
		./append/append_messages.c	\
		./append/append_int_array.c	\
		./append/append_users_data.c	\
		./append/append_teams_data.c	\
		./append/append_empty_slot.c	\
		./append/append_linked_list.c	\
		./append/append_threads_data.c	\
		./append/append_string_array.c	\
		./append/append_channels_data.c	\
		./append/append_comments_data.c	\
		./append/append_direct_message.c	\
		./append/append_correct_string.c	\
\
		./append/string/append_string_tab.c	\
		./append/string/append_string_int.c	\
		./append/string/append_node_header.c	\
		./append/string/append_string_char.c	\
		./append/string/append_string_size_t.c	\
		./append/string/append_string_string.c	\
		./append/string/append_string_dict_t.c	\
		./append/string/append_linked_list_node.c	\
		./append/string/append_string_dict_node.c	\
		./append/string/append_string_int_array.c	\
		./append/string/append_string_messages_t.c	\
		./append/string/append_string_linked_list.c	\
		./append/string/append_string_string_array.c	\
		./append/string/append_string_teams_data_t.c	\
		./append/string/append_string_users_data_t.c	\
		./append/string/append_string_threads_data_t.c	\
		./append/string/append_string_channels_data_t.c	\
		./append/string/append_string_comments_data_t.c	\
		./append/string/append_string_direct_message_t.c	\
\
		./free/free_int.c	\
		./free/free_json.c	\
		./free/free_dict.c	\
		./free/free_messages.c	\
		./free/free_int_array.c	\
		./free/free_users_data.c	\
		./free/free_teams_data.c	\
		./free/free_string_array.c	\
		./free/free_threads_data.c	\
		./free/free_node_content.c	\
		./free/free_channels_data.c	\
		./free/free_comments_data.c	\
		./free/free_direct_message.c	\
\
		./get/get_node.c	\
		./get/get_list_size.c	\
		./get/get_string_size.c	\
\
		./get/size/get_size_json.c	\
		./get/size/get_size_char.c	\
		./get/size/get_size_size_t.c	\
		./get/size/get_size_string.c	\
		./get/size/get_size_integer.c	\
		./get/size/get_size_of_dict_t.c	\
		./get/size/get_size_int_array.c	\
		./get/size/get_size_messages_t.c	\
		./get/size/get_size_string_array.c	\
		./get/size/get_size_teams_data_t.c	\
		./get/size/get_size_users_data_t.c	\
		./get/size/get_size_threads_data_t.c	\
		./get/size/get_size_channels_data_t.c	\
		./get/size/get_size_comments_data_t.c	\
		./get/size/get_size_direct_message_t.c	\
\

CC	=	gcc

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-iquote ../../include

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

COPY	=	cp -f

HEADER_FILE	=	json.h

NAME	=	libjson.a

INCLUDE_DESTINATION	=	../../include

TEST_FILE_PATH	=	../../

TEST_FILES	=	\

TEST_NAME	=	test_json

all: update_include_path $(NAME) update_libs

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

update_include_path:
	$(COPY) $(HEADER_FILE) $(INCLUDE_DESTINATION)

update_libs:
	$(COPY) $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)
	$(RM) $(TEST_NAME)

re: fclean all

debug: CFLAGS	+=	-g3
debug: clean all

tests_run: CFLAGS += --coverage -lcriterion
tests_run: fclean
tests_run:	$(TEST_NAME)

$(TEST_NAME):
	$(CC) -o $(TEST_NAME) $(TEST_FILES) $(SRC)
	./$(TEST_NAME)

test_coverage:
	gcovr --exclude /tests
	gcovr --exclude /tests --branches

.PHONY: all clean fclean re update_include_path update_libs	\
		tests_run debug test_coverage
