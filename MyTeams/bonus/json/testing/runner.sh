#!/bin/bash

SUCCESS=0

C_BLACK="\033[48;5;232m"
C_RED="\033[38;5;9m${C_BLACK}"
C_LIME="\033[38;5;10m${C_BLACK}"
C_GREEN="\033[38;5;2m${C_BLACK}"
C_AQUA="\033[38;5;14m${C_BLACK}"
C_YELLOW="\033[38;5;11m${C_BLACK}"
C_RESET="\033[0m"

INCLUDE_PATH=../../../include
LIB_PATH=../../../libs
LIB_NAME=-ljson
TEST_FILE=./main.c
BIN_NAME=tmp_json_test

MEMORY_COMMAND=""
OUTPUT_FILE=./tmp_test.txt
REDIRECT_COMMAND=""

ERROR_OUTPUT=2
DEBUG_OUTPUT=1023
STANDARD_OUTPUT=1

function mecho() {
    if [ "$REDIRECT_COMMAND" == "" ]; then
        echo -e "$1"
    else
        echo -e "$1" >>$OUTPUT_FILE
    fi
}

function display_help() {
    echo -e "${C_YELLOW}Usage: $1 [d] [r] [file name] ${C_RESET}"
    echo -e "${C_YELLOW}d: Debug mode ${C_RESET}"
    echo -e "${C_YELLOW}r: Redirect the output of the test to a file ${C_RESET}"
    echo -e "${C_YELLOW}file name: The name of the file to test ${C_RESET}"
    exit $SUCCESS
}

echo "Before check"
echo "Number of arguments: $#"
echo "First argument: $1, second argument: $2, third argument: $3"
if [ $# -gt 3 ] || [ $1 == "--help" ] || [ $1 == "-h" ] || [ $1 == "/?" ]; then
    display_help $0
fi

for arg in $@; do
    case $arg in
    d)
        echo -e "${C_YELLOW}Debug mode: ${C_GREEN}Activated${C_RESET}"
        MEMORY_COMMAND="valgrind --leak-check=full -s"
        if [ "$REDIRECT_COMMAND" != "" ]; then
            REDIRECT_COMMAND=">> $OUTPUT_FILE $ERROR_OUTPUT>&$STANDARD_OUTPUT $DEBUG_OUTPUT>&$STANDARD_OUTPUT"
        fi
        ;;
    r)
        echo -e "${C_YELLOW}Redirecting output to file${C_RESET}"
        if [ "$MEMORY_COMMAND" != "" ]; then
            REDIRECT_COMMAND=">> $OUTPUT_FILE $ERROR_OUTPUT>&$STANDARD_OUTPUT $DEBUG_OUTPUT>&$STANDARD_OUTPUT"
        else
            REDIRECT_COMMAND=">> $OUTPUT_FILE $ERROR_OUTPUT>&$STANDARD_OUTPUT"
        fi
        ;;
    *)
        if [ -z "$arg" ] && [[ "$arg" =~ [^[:alnum:].[:space:]] ]]; then
            echo -e "${C_YELLOW}Redirecting output to custom file name${C_RESET}"
            OUTPUT_FILE="$arg"
            if [ "$MEMORY_COMMAND" != "" ]; then
                REDIRECT_COMMAND=">> $OUTPUT_FILE $ERROR_OUTPUT>&$STANDARD_OUTPUT $DEBUG_OUTPUT>&$STANDARD_OUTPUT"
            else
                REDIRECT_COMMAND=">> $OUTPUT_FILE $ERROR_OUTPUT>&$STANDARD_OUTPUT"
            fi
        else
            echo -e "${C_RED}No (or incorrect) file name provided. Using default file name${C_RESET}"
            display_help $0
        fi
        ;;
    esac
done
echo "After check"
if [ "$REDIRECT_COMMAND" != "" ]; then
    echo -n "" >"$OUTPUT_FILE"
fi

mecho "${C_YELLOW}(c) Written by Henry Letellier"
mecho "${C_YELLOW}Cleaning ressources ..."
eval "make -C $LIB_PATH/json fclean $REDIRECT_COMMAND"
eval "rm -vf $BIN_NAME $REDIRECT_COMMAND"
STATUS=$?
if [ $STATUS -ne $SUCCESS ]; then
    mecho "${C_RED}Failed to clean ressources"
    mecho "The status code is: $STATUS. ${C_RESET}"
    exit $STATUS
else
    mecho "${C_LIME}Ressources cleaned."
fi
mecho "${C_YELLOW}Compiling library ..."
eval "make -C $LIB_PATH/json debug $REDIRECT_COMMAND"
STATUS=$?
if [ $STATUS -ne $SUCCESS ]; then
    mecho "${C_RED}Library compilation failed."
    mecho "The status code is: $STATUS. ${C_RESET}"
    exit $STATUS
else
    mecho "${C_LIME}Library compilation success."
fi
mecho "${C_YELLOW}Compiling code ..."
eval "gcc -o $BIN_NAME $TEST_FILE -L $LIB_PATH $LIB_NAME -Wall -Wextra -iquote $INCLUDE_PATH -g3 $REDIRECT_COMMAND"
STATUS=$?
if [ $STATUS -ne $SUCCESS ]; then
    mecho "${C_RED}Code compilation failed."
    mecho "The status code is: $STATUS. ${C_RESET}"
    exit $STATUS
else
    mecho "${C_LIME}Code compilation success."
fi
mecho "${C_AQUA}Running code..."
mecho "Starting $BIN_NAME"
eval "$MEMORY_COMMAND ./$BIN_NAME $REDIRECT_COMMAND"
STATUS=$?
if [ $STATUS -ne $SUCCESS ]; then
    mecho "${C_RED}Run failed."
    mecho "The status code is: $STATUS. ${C_RESET}"
    exit $STATUS
else
    mecho "${C_LIME}Run success."
fi
mecho "End of script${C_RESET}"
