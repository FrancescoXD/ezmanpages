#include "parser.h"

int main(void) {
    // File used only to test the library
    parser_error_t ret;

    // Define the `man_parser_t` struct
    man_parser_t man_parser;

    // Init the ezmanparser
    ret = ezmanparser_init(&man_parser, "ls", 1, "NAME");
    if (ret == E_PARSER_SUCCESS) {
        //fprintf(stderr, "%s", parser_error_desc[ret]);
        exit(EXIT_FAILURE);
    }

    // You can use those functions to change the `man_parser_t` structure
    //ezmanparser_set_name();
    //ezmanparser_set_page();
    //ezmanparser_set_section();

    return 0;
}
