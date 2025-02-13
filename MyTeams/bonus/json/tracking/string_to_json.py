##
# EPITECH PROJECT, 2023
# B-NWP-400-PAR-4-1-myteams-thomas.lebouc [fed34_prox_vm]
# File description:
# string_to_json.py
##

class StringToJson:
    """ The class in charge of converting a string to a json object """

    def __init__(self, json_string: str = "{},") -> None:
        self.json_string = json_string
        self.json_data_length = 0

    def skip_tab(self, json_string: str = "") -> int:
        """ Skip the tabs at the beginning of the string """
        nb_tabs: int = 0

        for i in json_string:
            if i in ("\t", " "):
                nb_tabs += len(i)
            else:
                return nb_tabs
        return nb_tabs

    def process_line(self, json_data: list, json_array: list, index: int) -> None:
        """ Process the current line that is provided """
        if json_array[index][-1] == '{':
            self.process_line(json_data, json_array, index+1)
        if json_array[index][-1] == '[':
            self.process_line(json_data, json_array, index+1)

    def main(self) -> list:
        """ The main function of the program """
        json_data = list()
        json_array = self.json_string.split("\n")
        # json_array.pop(0)
        # json_array.pop(-1)
        self.json_data_length = len(json_array) - 2
        for i in enumerate(json_array, 1):
            self.process_line(json_data, json_array, i[0])
        return json_data


if __name__ == "__main__":
    JSON_STRING_DATA = """
{
    "char *": "jjijoojj",
    "int": 100,
    "char": "a",
    "dict_t": {
        "c_structure_name": "dict_t",
        "term": "Term",
        "char *": "Definition",
    },
    "teams_data_t": {
        "c_structure_name": "teams_data_t",
        "uuid": "uuid",
        "name": "Name",
        "description": "Description",
        "channels":
        [
        ],
    },
    "users_data_t": {
        "c_structure_name": "users_data_t",
        "uuid": "uuid",
        "name": "name",
        "teams_uuid":
        [
        ],
        "dm":
        [
        ],
    },
    "size_t": "200",
    "char *": "This is a test string",
    "threads_data_t": {
        "c_structure_name": "threads_data_t",
        "uuid": "uuid",
        "user_uuid": "user_uuid",
        "title": "title",
        "body": "body",
        "created_time": "0",
        "created_time_str": "created_time_str",
        "comments":
        [
        ],
    },
    "channels_data_t": {
        "c_structure_name": "channels_data_t",
        "uuid": "uuid",
        "name": "name",
        "description": "description",
        "threads": "",
        [
        ],
    },
    "comments_data_t": {
        "c_structure_name": "comments_data_t",
        "user_uuid": "user_uuid",
        "reply_body": "reply_body",
        "replied_time_str": "replied_time_str",
        "replied_time": "0",
    },
    "messages_t": {
        "c_structure_name": "messages_t",
        "msg": "msg",
        "sender_uuid": "sender_uuid",
        "sent_time_str": "sent_time_str",
    },
    [
        0,
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
        11,
        12,
        13,
        14,
        15,
        16,
        17,
        18,
        19
    ],
    [
        "aaaaaaaaaa",
        "aaaaaaaaaa",
        "aaaaaaaaaa",
        "aaaaaaaaaa",
        "aaaaaaaaaa",
        "aaaaaaaaaa",
        "aaaaaaaaaa",
        "aaaaaaaaaa",
        "aaaaaaaaaa",
        "aaaaaaaaaa"
    ],
    "direct_message_t": {
        "c_structure_name": "direct_message_t",
        "receiver_uuid": "receiver_uuid",
        "messages": "",
        [
        ],
    },
},
"""
    STI = StringToJson(JSON_STRING_DATA)
    JSON_DATA = STI.main()
    print(f"Converted data = {JSON_DATA}")
    print(f"Type of converted data = {type(JSON_DATA)}")
