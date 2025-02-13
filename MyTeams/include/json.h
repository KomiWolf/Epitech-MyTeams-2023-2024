/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-thomas.lebouc
** File description:
** json.h
*/

#pragma once

#include "linked_list.h"
#include "server/struct.h"

/**
** @brief Structure in charge of tracking the the information
** for string creation
** @param string    The string containing the converted version
** @param index     The current index (a way of tracking the progress)
** @param max_size  The calculated size of the string
** @param add_comma Add a comma or not to the line
**/
struct carrier_node_s {
    char *string;
    size_t index;
    size_t max_size;
    bool add_comma;
};

/**
** @brief Rebind of the carrier_node structure
**/
typedef struct carrier_node_s carrier_node_t;
/**
** @brief Rebind of the carrier_node structure
**/
typedef struct carrier_node_s cnode_t;
/**
** @brief Rebind of the carrier_node structure
**/
typedef struct carrier_node_s cn_t;

/**
** @brief Structure in charge of tracking the the information
** for string decompilation
** @param string    The string containing the converted version
** @param index     The current index (a way of tracking the progress)
** @param max_size  The calculated size of the string
** @param add_comma Add a comma or not to the line
**/
struct decompiler_node_s {
    bool curly_open;
    bool bracket_open;
    struct decompiler_node_s *next;
};

/**
** @brief Rebind of the decompiler_node structure
**/
typedef struct decompiler_node_s decompiler_node_t;
/**
** @brief Rebind of the decompiler_node structure
**/
typedef struct decompiler_node_s dnode_t;
/**
** @brief Rebind of the decompiler_node structure
**/
typedef struct decompiler_node_s dn_t;

/**
** @brief Rebind of the linked list structure
**/
typedef struct linked_list_s json_t;

/**
** @brief Rebind of the data_type structure
**/
typedef data_type_t dtype_t;
/**
** @brief Rebind of the data_type structure
**/
typedef data_type_t dt_t;

/**
** @brief Rebind of the channels_data structure
**/
typedef channels_data_t chdata_t;
/**
** @brief Rebind of the channels_data structure
**/
typedef channels_data_t chd_t;

/**
** @brief Rebind of the direct_message structure
**/
typedef direct_message_t dmessage_t;
/**
** @brief Rebind of the direct_message structure
**/
typedef direct_message_t dm_t;

/**
** @brief Rebind of the comments_data structure
**/
typedef comments_data_t codata_t;
/**
** @brief Rebind of the comments_data structure
**/
typedef comments_data_t cod_t;

/**
** @brief Rebind of the threads_data structure
**/
typedef threads_data_t tdata_t;
/**
** @brief Rebind of the threads_data structure
**/
typedef threads_data_t td_t;

/**
** @brief JSON constant JSON_ERROR signifying an error. value: 84
**/
static const int JSON_ERROR = 84;
/**
** @brief JSON constant JSON_SUCCESS signifying success. value: 0
**/
static const int JSON_SUCCESS = 0;

/**
** @brief JSON constant JSON_MAX_BUFFER signifying the default
** stack allocation. value: 1024
**/
static const int JSON_MAX_BUFFER = 1024;

/**
** @brief JSON constant JSON_INT_ARRAY_END signifying the end key
** for an int array. value: -2147483648
**/
static const int JSON_INT_ARRAY_END = -2147483648;

/**
** @brief JSON constant JSON_S_TAB signifying the characters for a tab.
** value: '    '
**/
static const char JSON_S_TAB[] = "    ";
/**
** @brief JSON constant JSON_S_NAME signifying the default name for a
** structure. value: 'c_structure_name'
**/
static const char JSON_S_NAME[] = "c_structure_name";
/**
** @brief JSON constant JSON_S_NEW_LINE signifying the character
** for a new line. value: '\n'
**/
static const char JSON_S_NEW_LINE[] = "\n";
/**
** @brief JSON constant JSON_S_LIST_START signifying the character
** for the opening of a list. value: '[\n'
**/
static const char JSON_S_LIST_START[] = "[\n";
/**
** @brief JSON constant JSON_S_LIST_INNER signifying
** the character for the separation of arguments inside the list. value: ', '
**/
static const char JSON_S_LIST_INNER[] = ", ";
/**
** @brief JSON constant JSON_S_LIST_END signifying
** the character closing a list. value: ']\n'
**/
static const char JSON_S_LIST_END[] = "],\n";
/**
** @brief JSON constant JSON_S_COMMAD signifying the comma charater
** at the end of the line. value: ',\n'
**/
static const char JSON_S_COMMA[] = ",\n";
/**
** @brief JSON constant JOSN_S_COLON signifying the colon character.
** value: ': '
**/
static const char JSON_S_COLON[] = ": ";
/**
** @brief JSON constant JSON_S_CURLY_START signifying the begining
** of a term/definition pair. value: '{\n'
**/
static const char JSON_S_CURLY_START[] = "{\n";
/**
** @brief JSON constant JSON_S_CURLY_END signifying
** the end of a term/definition pair. value: '}\n'
**/
static const char JSON_S_CURLY_END[] = "},\n";
/**
** @brief JSON constant JSON_S_EMPTY signifying an empty content. value: '\n'
**/
static const char JSON_S_EMPTY[] = "\n";
/**
** @brief JSON constant JSON_S_QUOTATION_MARK_START signifying the opening
** of a string. value: '"'
**/
static const char JSON_S_QUOTATION_MARK_START[] = "\"";
/**
** @brief JSON constant JSON_S_QUOTATION_MARK_END signifying the closing
** of the string value. value: '"'
**/
static const char JSON_S_QUOTATION_MARK_END[] = "\"";

/**
** @brief JSON constant JSON_S_NULL_STRING signifying the string
** to put when the passed value is of type NULL. value: '(Null)'
**/
static const char JSON_S_NULL_STRING[] = "(Null)";

/**
** @brief JSON constant JSON_NEW_LINE signifying a new line length. value: 1
**/
static const int JSON_NEW_LINE = 1;
/**
** @brief JSON constant JSON_COMMA signifying the length of a comma. value: 2
**/
static const int JSON_COMMA = 1 + JSON_NEW_LINE;
/**
** @brief JSON constant JSON_LIST signifying the length of a list. value: 4
**/
static const int JSON_LIST = 2 + JSON_NEW_LINE + JSON_COMMA;
/**
** @brief JSON constant JSON_COLON signifying the length of a colon. value: 2
**/
static const int JSON_COLON = 2;
/**
** @brief JSON constant JSON_CURLY signifying the length of curly brackets.
** value: 4
**/
static const int JSON_CURLY = 2 + JSON_NEW_LINE + JSON_COMMA;
/**
** @brief JSON constant JSON_EMPTY signifying the length of an empty line.
** value: 1
**/
static const int JSON_EMPTY = 0 + JSON_NEW_LINE;
/**
** @brief JSON constant JSON_TAB_SIZE signifying the size of the tab. value: 4
**/
static const int JSON_TAB_SIZE = 4;
/**
** @brief JSON constant JSON_QUOTATION_MARK signifying the length
** of the quotation mark. value: 2
**/
static const int JSON_QUOTATION_MARK = 2;
/**
** @brief JSON constant JSON_LIST_INNER_SIZE signifying the size
** of the internal list seperator. value: 2
**/
static const int JSON_LIST_INNER_SIZE = 2;

/**
** @brief JSON constant JSON_NULL_STRING_LENGTH signifying the length
** of the NULL string. value: 8
**/
static const int JSON_NULL_STRING_LENGTH = 8;

/**
** @brief Function in charge of converting the json structures to a json string
** @param json_data The json structures to be converted a json string
**/
char *to_string(json_t *json_data);

/**
** @brief Function in charge of converting a json string to json structures
** @param string The json string to be converted to json structures
**/
json_t *to_json(char *string);
/**
** @brief Function in charge removing a node from the json index
** @param json_data The json structures
** @param index     The index of the node you wish to remove
**/
json_t *pop_node(json_t *json_data, int index);
/**
** @brief Function in charge of getting node from the json data
** @param json_data The json structures
** @param index     The index of the node you wish to get
**/
json_t *get_node(json_t *json_data, int node_index);
/**
** @brief Function in charge initialising the json list
** @param node_content The content of the first node
** @param type         The type of the provided node
**/
json_t *init_json(void *node_content, data_type_t type);

/**
** @brief Function in charge of freeing an int
** @param content The int * type
**/
int free_int(int *data);
/**
** @brief Function in charge of freeing a dictionary structure
** @param content The dict_t structure
**/
int free_dict(dict_t *content);
/**
** @brief Function in charge of freeing an int array
** @param array   The int array
**/
int free_int_array(int *array);
/**
** @brief Function in charge of freeing the json structures
** @param json_data The json structures
**/
int free_json(json_t *json_data);
/**
** @brief Function in charge of freeing the server_t structure
** @param data    The server_t structure
**/
int free_string_array(char **array);
/**
** @brief Function in charge of freeing the messages_t structure
** @param data    The messages_t structure
**/
int free_messages(messages_t *data);
/**
** @brief Function in charge of freeing the teams_data_t structure
** @param data    The teams_data_t structure
**/
int free_teams_data(teams_data_t *data);
/**
** @brief Function in charge of freeing the users_data_t structure
** @param data    The users_data_t structure
**/
int free_users_data(users_data_t *data);
/**
** @brief Function in charge of freeing the threads_data_t structure
** @param data    The threads_data_t structure
**/
int free_threads_data(threads_data_t *data);
/**
** @brief Function in charge of freeing the comments_data_t structure
** @param data    The comments_data_t structure
**/
int free_comments_data(comments_data_t *data);
/**
** @brief Function in charge of freeing the channels_data_t structure
** @param data    The channels_data_t structure
**/
int free_channels_data(channels_data_t *data);
/**
** @brief Function in charge of freeing the direct_message_t structure
** @param data    The direct_message_t structure
**/
int free_direct_message(direct_message_t *data);
/**
** @brief Function in charge of freeing a node based on the provided type
** @param data    A node
** @param type    The type of the node
**/
int free_node_content(void *node, data_type_t type);

/**
** @brief Function in charge of calculating the size of the json structure
** @param json_data The json structure
**/
int get_list_size(json_t *json_data);

/**
** @brief Function in charge of adding the correct amount of tabs to the stirng
** @param cn   The cn_t structure
** @param ntl  The tab level
**/
int append_string_tab(cn_t *cn, int ntl);
/**
** @brief Function in charge of creating the first line of a structure
** to the json string.
** @param cn   The cn_t structure
** @param str  The string for the title of the structure
** @param ntl  The tab level
**/
int append_string_node_header(cn_t *cn, char *str, int ntl);
/**
** @brief Function in charge of adding an int to the string
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param ntl  The tab level
**/
int append_string_int(cn_t *cn, int data, int ntl);
/**
** @brief Function in charge of adding a char to the string
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param ntl  The tab level
**/
int append_string_char(cn_t *cn, char data, int ntl);
/**
** @brief Function in charge of adding a size_t to the string
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param ntl  The tab level
**/
int append_string_size_t(cn_t *cn, size_t data, int ntl);
/**
** @brief Function in charge of adding a char * to the string
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param ntl  The tab level
**/
int append_string_string(cn_t *cn, char *data, int ntl);
/**
** @brief Function in charge of adding an int * to the string
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param ntl  The tab level
**/
int append_string_int_array(cn_t *cn, int *data, int ntl);
/**
** @brief Function in charge of adding a dict_t to the string
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param ntl  The tab level
**/
int append_string_dict_t(cn_t *cn, dict_t *data, int ntl);
/**
** @brief Function in charge of adding a linked_list_t to the string
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param ntl  The tab level
**/
int append_string_linked_list(cn_t *cn, llist_t *ll, int ntl);
/**
** @brief Function in charge of adding a char ** to the string
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param ntl  The tab level
**/
int append_string_string_array(cn_t *cn, char **data, int ntl);
/**
** @brief Function in charge of adding a message_t to the string
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param ntl  The tab level
**/
int append_string_messages_t(cn_t *cn, messages_t *data, int ntl);
/**
** @brief Function in charge of adding a linked list to the json structure
** @param cn   The cn_t structure
** @param str  The string for the title of the linked list
** @param d    The Data of the linked list
** @param ntl  The tab level
**/
int append_linked_list_node(cn_t *cn, char *str, ll_t *d, int ntl);
/**
** @brief Function in charge of adding a dictionary line
** @param cn   The cn_t structure
** @param t    The term of the node that is inputted
** @param d    The definition of the node that is inputted
** @param ntl  The tab level
**/
int append_string_dict_node(cn_t *cn, char const *t, char const *d, int ntl);
/**
** @brief Function in charge of adding a teams_data_t to the string
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param ntl  The tab level
**/
int append_string_teams_data_t(cn_t *cn, teams_data_t *data, int ntl);
/**
** @brief Function in charge of adding a users_data_t to the string
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param ntl  The tab level
**/
int append_string_users_data_t(cn_t *cn, users_data_t *data, int ntl);
/**
** @brief Function in charge of adding the correct string type
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param type The type of the inputted data
** @param ntl  The tab level
**/
int append_correct_string(cnode_t *cn, void *data, data_type_t type, int ntl);
/**
** @brief Function in charge of adding a threads_data_t to the string
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param ntl  The tab level
**/
int append_string_threads_data_t(cn_t *cn, threads_data_t *data, int ntl);
/**
** @brief Function in charge of adding a comments_data_t to the string
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param ntl  The tab level
**/
int append_string_comments_data_t(cn_t *cn, comments_data_t *data, int ntl);
/**
** @brief Function in charge of adding a channels_data_t to the string
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param ntl  The tab level
**/
int append_string_channels_data_t(cn_t *cn, channels_data_t *data, int ntl);
/**
** @brief Function in charge of adding a direct_message_t to the string
** @param cn   The cn_t structure
** @param data The data that is inputted
** @param ntl  The tab level
**/
int append_string_direct_message_t(cn_t *cn, direct_message_t *data, int ntl);

/**
** @brief Function in charge of adding an empty slot to the json structure
** @param p_list The json structure
**/
int append_empty_slot(json_t *p_list);
/**
** @brief Function in charge of adding an int slot to the json structure
** @param p_list The json structure
** @param value  The integer value
**/
int append_int(json_t *p_list, int value);
/**
** @brief Function in charge of adding a dict_t slot to the json structure
** @param p_list The json structure
** @param child  The dict_t value
**/
int append_dict(json_t *p_list, dict_t *child);
/**
** @brief Function in charge of adding a character slot to the json structure
** @param p_list The json structure
** @param character  The char value
**/
int append_char(json_t *p_list, char character);
/**
** @brief Function in charge of adding a char * slot to the json structure
** @param p_list The json structure
** @param string  The char * value
**/
int append_string(json_t *p_list, char *string);
/**
** @brief Function in charge of adding a size_t slot to the json structure
** @param p_list The json structure
** @param value  The size_t value
**/
int append_size_t(json_t *p_list, size_t value);
/**
** @brief Function in charge of adding an int * slot to the json structure
** @param p_list The json structure
** @param array  The int * value
**/
int append_int_array(json_t *p_list, int *array);
/**
** @brief Function in charge of adding a char ** slot to the json structure
** @param p_list The json structure
** @param array  The char ** value
**/
int append_string_array(json_t *p_list, char **array);
/**
** @brief Function in charge of adding a message_t slot to the json structure
** @param p_list The json structure
** @param child  The message_t value
**/
int append_messages(json_t *p_list, messages_t *child);
/**
** @brief Function in charge of adding a users_data_t slot
** to the json structure
** @param p_list The json structure
** @param child  The users_data_t value
**/
int append_users_data(json_t *p_list, users_data_t *child);
/**
** @brief Function in charge of adding a threads_data_t slot
** to the json structure
** @param p_list The json structure
** @param child  The threads_data_t value
**/
int append_threads_data(json_t *p_list, threads_data_t *child);
/**
** @brief Function in charge of adding a teams_data_t slot
** to the json structure.
** @param p_list The json structure
** @param child  The teams_data_t value
**/
int append_teams_data(json_t *parent_list, teams_data_t *child);
/**
** @brief Function in charge of adding a json_t slot to the json structure
** @param p_list The json structure
** @param child_list  The json_t value
**/
int append_linked_list(json_t *parent_list, json_t *child_list);
/**
** @brief Function in charge of adding a comments_data_t slot
** to the json structure
** @param p_list The json structure
** @param child  The comments_data_t value
**/
int append_comments_data(json_t *p_list, comments_data_t *child);
/**
** @brief Function in charge of adding a channels_data_t slot
** to the json structure
** @param p_list The json structure
** @param child  The channels_data_t value
**/
int append_channels_data(json_t *p_list, channels_data_t *child);
/**
** @brief Function in charge of adding a direct_message_t slot
** to the json structure
** @param p_list The json structure
** @param child  The direct_message_t value
**/
int append_direct_message(json_t *p_list, direct_message_t *child);
/**
** @brief Function in charge of adding a slot to the json structure
** @param json_data     The json structure
** @param node_content  The value of the node
** @param type          The type of the node
**/
int append_node(json_t *json_data, void *node_content, data_type_t type);

/**
** @brief Function in charge getting the size of an element
** @param number      An int
** @param ntl         The indentation level
**/
size_t get_size_integer(int number, int ntl);
/**
** @brief Function in charge getting the size of an element
** @param data        A char
** @param ntl         The indentation level
**/
size_t get_size_char(char data, int tab_level);
/**
** @brief Function in charge getting the size of an element
** @param data        A size_t
** @param ntl         The indentation level
**/
size_t get_size_size_t(size_t data, int tab_level);
/**
** @brief Function in charge getting the size of an element
** @param data        A char *
** @param ntl         The indentation level
**/
size_t get_size_string(char *data, int tab_level);
/**
** @brief Function in charge getting the size of an element
** @param data        A structure dict_t
** @param ntl         The indentation level
**/
size_t get_size_dict_t(dict_t *data, int tab_level);
/**
** @brief Function in charge getting the size of an element
** @param data        A structure json_t
** @param ntl         The indentation level
**/
size_t get_size_json_t(json_t *data, int tab_level);
/**
** @brief Function in charge getting the size of an element
** @param data        An int *
** @param ntl         The indentation level
**/
size_t get_size_int_array(int *data, int tab_level);
/**
** @brief Function in charge getting the size of an element
** @param data        A char ** instance
** @param ntl         The indentation level
**/
size_t get_size_string_array(char **data, int tab_level);
/**
** @brief Function in charge getting the size of an element
** @param data        A structure messages_t
** @param ntl         The indentation level
**/
size_t get_size_messages_t(messages_t *data, int tab_level);
/**
** @brief Function in charge getting the size of an element
** @param data        An structure teams_data_t
** @param ntl         The indentation level
**/
size_t get_size_teams_data_t(teams_data_t *data, int tab_level);
/**
** @brief Function in charge getting the size of an element
** @param data        A structure users_data_t
** @param ntl         The indentation level
**/
size_t get_size_users_data_t(users_data_t *data, int tab_level);

/**
** @brief Function in charge getting the size of an element
** @param data        The input data
** @param type        The type of the input data
** @param tab_level   The indentation level
**/
size_t get_string_size(void *data, data_type_t type, int tab_level);
/**
** @brief Function in charge getting the size of an element
** @param number      A structure threads_data_t
** @param ntl         The indentation level
**/
size_t get_size_threads_data_t(threads_data_t *data, int tab_level);
/**
** @brief Function in charge getting the size of an element
** @param data        A structure channels_data_t
** @param ntl         The indentation level
**/
size_t get_size_channels_data_t(channels_data_t *data, int tab_level);
/**
** @brief Function in charge getting the size of an element
** @param data        A structure comments_data_t
** @param ntl         The indentation level
**/
size_t get_size_comments_data_t(comments_data_t *data, int tab_level);
/**
** @brief Function in charge getting the size of an element
** @param data        A structure direct_message_t
** @param ntl         The indentation level
**/
size_t get_size_direct_message_t(direct_message_t *data, int tab_level);

/**
** @brief Function in charge of converting a string to an array
** @param str         The string to be split
** @param sep         The characters at which to split
** @param width       The reference to the width variable
**                     (will be set by the function)
** @param height      The reference to the height variable
**                     (will be set by the function)
**/
char **json_str_to_word_array(char *str, char *sep, int *width, int *height);

// Debugging functions
/**
** @brief Function in charge of displaying a string on the terminal
** @param string      The string to display
** @param channel     The channel on which to dislay it
**/
void my_putstri(char const *string, int channel);
/**
** @brief Function in charge of displaying a string on channel
** JSON_STANDARD_OUTPUT of the terminal
** @param string      The string to display
**/
void my_perror(char const *string);
/**
** @brief Function in charge of displaying a string on channel
** JSON_ERROR_OUTPUT of the terminal
** @param string      The string to display
**/
void my_putstr(char const *string);
/**
** @brief Function in charge of displaying a string on channel
** JSON_DEBUG_OUTPUT of the terminal
** @param string      The string to display
**/
void my_putdebug(char const *string);
/**
** @brief Constant in charge of storing the standard value
** of the output on the terminal
**/
static const int JSON_STANDARD_OUTPUT = 1;
/**
** @brief Constant in charge of storing the error value
** of the output on the terminal
**/
static const int JSON_ERROR_OUTPUT = 2;
/**
** @brief Constant in charge of storing the debug value
** of the output on the terminal
**/
static const int JSON_DEBUG_OUTPUT = 1023;
